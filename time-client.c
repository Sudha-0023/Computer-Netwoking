#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
int main()
{
	
	int sockfd;
	int port;
	struct sockaddr_in serv_addr;
	// struct hostent *server;
	char buffer[4096], buffer1[4096];
	sockfd=socket(AF_INET,SOCK_STREAM,0);

	printf("Enter the port number you got from server side:");
	scanf("%d",&port);

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
	serv_addr.sin_port=htons(port);

	connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

	read(sockfd,buffer1,4096);
	printf("Date & Time received from server:%s",buffer1);
	printf("\n");
	close(sockfd);
	return 0;
}