#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main()
{
	int listenfd,connfd,len,n,add;
	int buff,s1,s2;
	struct sockaddr_in servaddr,cliaddr;
	len=sizeof(servaddr);
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(0);
	listenfd=socket(AF_INET,SOCK_STREAM,0);
	bind(listenfd,(struct sockaddr *)&servaddr,len);
	getsockname(listenfd,(struct sockaddr *)&servaddr,&len);
	printf("Port for client=%ld\n",(long)ntohs(servaddr.sin_port));
	listen(listenfd,5);
	connfd=accept(listenfd,(struct sockaddr *)&cliaddr,&len);
	
	while(1)
	{
	recv(connfd,&buff,sizeof(buff),0);
	printf("server received the message=%d\n",buff);
	s1=buff*buff;
	s2=2*buff;
	// server writes
	send(connfd,&s1,sizeof(s1),0);
	send(connfd,&s2,sizeof(s2),0);
	recv(connfd,&add,sizeof(add),0);
	printf("Sum = %d\n",add);
	break;
	}
	return 0;
}