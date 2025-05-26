/*
Running Program:
First start the server then client can be connected...
 
Client:
-> gcc client.c -o client
-> ./client 127.0.0.1 [port no.]
 
port number for client and server should be same.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc,char *argv[])
{
	
	int sockfd,portno,n;    //File descriptor for Sockets
	char buffer[256];       //Temporary buffer to read and write data
	
	struct sockaddr_in serv_addr;   //Structure to hold Server and Client details
	struct hostent *server;
	if(argc < 3){
	
		fprintf(stderr,"Error! no port number is provided");
		exit(1);
		
	}
    /* Create client socket */
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	server = gethostbyname(argv[1]);    //Resolving the host server and storing its details
	
	if(server == NULL){
	printf("Error! No such host");
	exit(1);
	}
	
	portno = atoi(argv[2]);
    /* Fill in server address */
	bzero((char *) &serv_addr,sizeof(serv_addr));   // Empty content of server address
	
	
	serv_addr.sin_family=AF_INET;   //Assign IPv4 family to server_address
    //Copy contents of host server address resolved into serv_addr
	bcopy((char *) server->h_addr,(char *) &serv_addr.sin_addr.s_addr,server->h_length);
	serv_addr.sin_port=htons(portno);
    /* Connect to server */
	if(connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr))<0){
		printf("connection failed");
	}
	
	while(1){
        
        /* Ask user for message to send to server */
        printf("Please enter the message to the server: \n");
		bzero(buffer,256);
		fgets(buffer,255,stdin);
        /* Write to server */
		n = write(sockfd,buffer,strlen(buffer));
        if(n<0)
            error("Error writing to the socket.");
        /* Read reply */
		bzero(buffer,256);
		n = read(sockfd,buffer,255);
        if(n<0)
            error("Error reading from socket.");
        printf("server replied: %s\n\n",buffer);
		
		int i = strncmp("Bye, Exit", buffer,3);
		if(i==0)
		break;
		
	}
	
	close(sockfd);
	return 0;
	
	
	




}

