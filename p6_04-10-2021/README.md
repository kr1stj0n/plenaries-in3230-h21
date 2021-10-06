# 6th plenary session: 04.10.2021 #

In this plenary session we focuse onthe following topics:

* Queues using doubly linked lists
* Finite State Machine

## Queue ##

One requirement for the MIP and Routing daemon is that they MUST operate
asynchronously, which means that they must not block the execution flow while
waiting for response packets. In order to achieve this, one may combine several
methods like non-blocking sockets, epoll() and queues.
[Here](https://github.com/kr1stj0n/plenaries-in3230-h21/tree/main/p6_04-10-2021/libqueue)
you may find a complete implementation of a queue library that can be used in
your Home Exam 1. When the MIP daemon receives a MIP packet that needs to be
forwarded, it can store the packet in the queue, initiate a route lookup using
the forwarding engine, and then retrieve that packet from the queue. At the same
time, MIP daemon MUST be able to process incoming and send outgoing MIP packets.

## FSM (Finite State Machine) ##

A Routing daemon that runs a Routing Protocol can be modeled as a Finite State
Machine. The FSM can change from one state to another in response to some
inputs; the change from one state to another is called a transition. Examples of
transitions in our Home Exam 1 are when HELLO message is sent to all neighbors
or when a neighbor is down and the Routing table needs to be updated.  In this
example
[here](https://github.com/kr1stj0n/plenaries-in3230-h21/tree/main/p6_04-10-2021/libqueue),
we implement a simple FSM that keeps track of the states between the client and
server. Both the client and server send HELLO messages every 5 seconds. HELLO
timeout is set 10 seconds.

Usage:

  `make all` to compile the programs.

Run the server first using `./server`, and then `./client` to run the client.

Practise and implement new features in the applications.
Good luck! :-)
