#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>
#include <arpa/inet.h>

#define PORTNUM 9000

int main(void){
	char buf[BUFSIZ] = {0,};
	struct sockaddr_in sin, cli;
	int sd, ns, clientlen = sizeof(cli);
	printf("socket\n");
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit(EXIT_FAILURE);
	}
	printf("bind\n");
	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))){
		perror("bind");
		exit(EXIT_FAILURE);
	}
	printf("listen\n");
	if(listen(sd, 5)){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	printf("accept\n");
	if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) ==-1){
		perror("accept");
		exit(EXIT_FAILURE);
	}
	
	while(1){
		memset(buf, '\0', BUFSIZ);
		recv(ns, buf, sizeof(buf), 0);
		int a = strcmp(buf, "exit");
		if(a == 0){
			close(ns);
			close(sd);
		}
                printf("RECV : %s\n", buf);
	
		memset(buf, '\0', BUFSIZ);
		sprintf(buf, "Server received the message\n");	

		send(ns, buf, strlen(buf) + 1, 0);
		}	

	return 0;
}

