#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include "time.h"

//#define SERV_TCP_PORT 5035
int main()
{


int sockfd,newsockfd,clength,len;
time_t tick;
struct sockaddr_in serv_addr,cli_addr;
char buffer[4096];

len=sizeof(serv_addr);

sockfd=socket(AF_INET,SOCK_STREAM,0);

serv_addr.sin_family=AF_INET;
serv_addr.sin_addr.s_addr=INADDR_ANY;
serv_addr.sin_port=htonl(0);

printf("\nstart");
bind(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

getsockname(sockfd, (struct sockaddr *)&serv_addr,&len);

printf("Port for client=%d\n",ntohs(serv_addr.sin_port));

printf("\nlistening...");
printf("\n");
listen(sockfd,5);
clength=sizeof(cli_addr);
newsockfd=accept(sockfd,(struct sockaddr*)&cli_addr,&clength);
printf("\nAccepted");
printf("\n");

tick=time(NULL);
snprintf(buffer,sizeof(buffer),"%s",ctime(&tick));
printf("Date & Time is:%s",buffer);
write(newsockfd,buffer,4096);
return 0;

}