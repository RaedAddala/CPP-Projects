# Socket Programming in C++

- Socket Programming refers to the method of communincation between two sockets on the network.  

- We use socket API to create communication between the two programs running on the network.  

- Socket programming allows the bidirectional communication between the nodes.  

## What are Sockets?

- A **socket** is an endpoint of a **two way** communication link between two programs running on the network

- Each socket has a specific address, composed of an IP address and a port number (155.92.4.16:1625)

## client-server communication process

1. The server creates a socket, attaches it to a network port address then waits for the client to contact it.  

2. The client creates a socket and then attempts to connect to the server socket.  

3. When the connection is estanlished, transfer of data takes place.

## Types of sockets

1. **Stream socket**: (like **TCP**) ensuring that all information is delivered correctly.  

2. **Datagram socket**: (like **UDP**) they are faster but might get lost.  
