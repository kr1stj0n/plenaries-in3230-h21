#include <stdlib.h>		/* free */
#include <stdio.h> 		/* printf */
#include <unistd.h>             /* fgets */
#include <string.h>		/* memset */
#include <sys/socket.h>		/* socket */
#include <fcntl.h>
#include <sys/epoll.h>          /* epoll */
#include <linux/if_packet.h>	/* AF_PACKET */
#include <net/ethernet.h>	/* ETH_* */
#include <arpa/inet.h>		/* htons */

#include "common.h"

int main(int argc, char *argv[])
{
	struct ifs_data local_ifs;
	int     raw_sock, rc;

	struct epoll_event ev, events[MAX_EVENTS];
	int epollfd;

	/* Set up a raw AF_PACKET socket without ethertype filtering */
	raw_sock = create_raw_socket();

	/* Walk through all interfaces of the node and store their addresses */
	init_ifs(&local_ifs, raw_sock);

	for (int i = 0; i < local_ifs.ifn; i++)
		print_mac_addr(local_ifs.addr[i].sll_addr, 6);

	epollfd = epoll_create1(0);
	if (epollfd == -1) {
		perror("epoll_create1");
		exit(EXIT_FAILURE);
	}

	ev.events = EPOLLIN|EPOLLHUP;
	ev.data.fd = raw_sock;
	if (epoll_ctl(epollfd, EPOLL_CTL_ADD, raw_sock, &ev) == -1) {
		perror("epoll_ctl: raw_sock");
		exit(EXIT_FAILURE);
	}

	while(1) {
		rc = epoll_wait(epollfd, events, MAX_EVENTS, -1);
		if (rc == -1) {
			perror("epoll_wait");
			exit(EXIT_FAILURE);
		} else if (events->data.fd == raw_sock) {
			printf("\n<info> The neighbor is initiating a handshake\n");
			printf("\n<info> epoll signal %d\n", events[0].events);

			rc = handle_arp_packet(&local_ifs);
			if (rc < 1) {
				perror("recv");
				exit(EXIT_FAILURE);
			}
		}
	}

	close(raw_sock);

	return 0;
}
