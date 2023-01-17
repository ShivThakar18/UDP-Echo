UDP Client Server Echo Program
===========================================================================================================================
In a client-server paradigm, communication is between two programs, a client and a server. A client sends a request to the server to begin communication. The server program waits for a request, once received will send a response. 

In this part of the project, a simple client and server program was developed using C. This program implements a "time server", which uses socket programming and communicates using User Datagram Protocol (UDP).

UDP Time Client Implementation
---------------------------------------------------------------------------------------------------------------------------
* IP Address and Port 9988 specified as command-line parameters
* The client program creates a socket using the IP address and Port number
* Client sends time request using sendto() function
* Client receives current time from server using recvfrom() function

UDP Time Server Implementation
---------------------------------------------------------------------------------------------------------------------------
* Server creates socket using default IP address and port 9988
* Server binds the socket to port 8899
* Recevies time request from client using recvfrom() function
* Sends the current time using the sendto() function

Project Requirements 
---------------------------------------------------------------------------------------------------------------------------
Modify the source code files to implement the following changes

1. Change server port number from 8899 to 9988
2. Change the message sent by client to include name
3. Ensure the server echos name and current time

Compile and Run
---------------------------------------------------------------------------------------------------------------------------
1. Compile server 
2. Run Server
3. Compile Client
4. Run client with IP Address and Port Number on the command line arguements (127.0.0.1 9988)
