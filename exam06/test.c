#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
	int sockfd;
	struct sockaddr_in servaddr;

	// Create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		perror("socket failed");
		exit(1);
	}

	// Configure server address the client will connect to
    memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(8080);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	// Connect to server
	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		printf("connect failed");
		close(sockfd);
		exit(1);
	}

	send(sockfd, "hello", 5, 0);
	sleep(1);

	send(sockfd, " world\n", 7, 0);
	sleep(3);

	send(sockfd, "this is", 7, 0);
	sleep(1);

	send(sockfd, " a test\n", 8, 0);
    sleep(6);

    send(sockfd, " _ooo_", 6, 0);
    sleep(1);

	send(sockfd, "\n\n\n", 3, 0);
    sleep(1);

	close(sockfd);
	return 0;
}
