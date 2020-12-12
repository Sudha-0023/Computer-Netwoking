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
	int sockfd,len,n,r,r1,add=0;
	long port;
	int buff;
	struct sockaddr_in cliaddr;
	len=sizeof(cliaddr);
	printf("Enter the port number you got from the server side:");
	scanf("%ld",&port);
	cliaddr.sin_family=AF_INET;
	cliaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	cliaddr.sin_port=htons(port);
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	connect(sockfd,(struct sockaddr *)&cliaddr,len);
	printf("Enter a number for server:");
	scanf("%d",&buff);
	send(sockfd,&buff,sizeof(buff),0);
	recv(sockfd,&r,sizeof(r),0);
	recv(sockfd,&r1,sizeof(r1),0);
	printf("client received the message square number = %d\n",r);
	printf("client received the message twice of number = %d\n",r1);
	add=(r+r1);
	send(sockfd,&add,sizeof(add),0);
	return 0;
}