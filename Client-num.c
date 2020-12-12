#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int sock;
	struct sockaddr_in server;
	int server_reply;
	int number, i, temp;

	// Create socket
	sock = socket(AF_INET, SOCK_STREAM,0);
	if (sock==-1) {
		printf("could not create socket\n");
	}
	puts("socket created\n");

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8880);

	// Connect to remote server
	if (connect(sock, (struct sockaddr*)&server, sizeof(server)) <0) {
		perror("Connection failed, Error occured\n");
		return 1;
	}
	puts("Connected\n");
	printf("Enter operands:\n");
	scanf("%d", &number);
	if(send(sock, &number, sizeof(int), 0)<0) {
		puts("send failed\n");
		return 1;
	}

	// Receive a reply from the server
	if (recv(sock, &server_reply, sizeof(int),0)<0) {
	puts("recv failed");
		return 0;
	}

	puts("Server reply:\n");
	printf("%d\n",server_reply);

	close(socket);
	return 0;
}







