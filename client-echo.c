#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#define SERV_TCP_PORT 5035
int main(int argc,char*argv[])
{
int sockfd;
struct sockaddr_in serv_addr;

//struct hostent *server;
char buffer[4096];

///define socket///
sockfd=socket(AF_INET,SOCK_STREAM,0);

///socket address structure
serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
serv_addr.sin_port=htons(SERV_TCP_PORT);
printf("\nReady for sending....");

/////Connect////
connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
printf("\nEnter the msg to send: \n");
printf("\nClient: ");

///read a line from the specified stream ////
fgets(buffer,4096,stdin);

///write///
write(sockfd,buffer,4096);
printf("Serverecho:%s",buffer);
printf("\n");

///close///
close(sockfd);
return 0;
}