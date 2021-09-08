# 2nd Plenary session: 06.09.2021 #

In the second plenary session we mainly talked about the following topics:

* Oblig
* UNIX sockets
* epoll()

## Oblig ##

We first talked about the Oblig and its main requirements. Through a
step-by-step example, we explained the MIP packets that the
client, server and MIP daemons need to exchange in order to ''establish'' a
communication path for ping-pong messages. More details about
the Oblig can be found
[here](https://www.uio.no/studier/emner/matnat/ifi/IN3230/h21/oblig/).

## UNIX sockets ##

We then talked about UNIX sockets and checked the implementations of
client/server applications that use such sockets to communicate to eath other.
UNIX sockets will be use as the interface between ping applications and MIP
daemons. Check the code example
[here](https://github.com/kr1stj0n/plenaries-in3230-h21/tree/main/p2_06-09-2021/unix_sockets).

## epoll() ##

Last but not least, we talked about `epoll`, the great tool which monitors
multiple file descriptors to see if `read()` can be called on any of them.
`epoll()` will be used heavily in the Oblig and Home Exams so that the daemons
can monitor both UNIX and RAW sockets for incoming data, asynchronously.

Here is an example from `man epoll`:

```c
#define MAX_EVENTS 10
           struct epoll_event ev, events[MAX_EVENTS];
           int listen_sock, conn_sock, nfds, epollfd;

           /* Code to set up listening socket, 'listen_sock',
              (socket(), bind(), listen()) omitted. */

           epollfd = epoll_create1(0);
           if (epollfd == -1) {
               perror("epoll_create1");
               exit(EXIT_FAILURE);
           }

           ev.events = EPOLLIN;
           ev.data.fd = listen_sock;
           if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
               perror("epoll_ctl: listen_sock");
               exit(EXIT_FAILURE);
           }

           for (;;) {
               nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
               if (nfds == -1) {
                   perror("epoll_wait");
                   exit(EXIT_FAILURE);
               }

               for (n = 0; n < nfds; ++n) {
                   if (events[n].data.fd == listen_sock) {
                       conn_sock = accept(listen_sock,
                                          (struct sockaddr *) &addr, &addrlen);
                       if (conn_sock == -1) {
                           perror("accept");
                           exit(EXIT_FAILURE);
                       }
                       ev.events = EPOLLIN | EPOLLET;
                       ev.data.fd = conn_sock;
                       if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock,
                                   &ev) == -1) {
                           perror("epoll_ctl: conn_sock");
                           exit(EXIT_FAILURE);
                       }
                   } else {
                       do_use_fd(events[n].data.fd);
                   }
               }
           }
```

## Next plenary ##

We didn't have time to talk about RAW sockets, but you can check a working
example on how to use them
[here](https://github.com/kr1stj0n/plenaries-in3230-h21/tree/main/p2_06-09-2021/raw_sockets).
https://beej.us/guide/bgnet/ is a good resource about socket programming in C.
Also, attend the next Orakel for more code examples about RAW sockets.  In the
next plenary session, we will hand code a simple implementation of MIP-ARP using
RAW socket, that helps three nodes (A --- B --- C) to get to know each other.
