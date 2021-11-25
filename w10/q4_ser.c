#include <sys/types.h>
#include <time.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORTNUM 9002

int main(void){
	char buf[BUFSIZ];
	struct sockaddr_in sin, cli;
	int sd, ns, clientlen = sizeof(cli);
	printf("socket\n");
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
			perror("socket");
			exit(1);
	}

	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	printf("bind\n");
	if(bind(sd, (struct sockaddr *)&sin, sizeof(sin))) {
			perror("bind");
			exit(1);
	}
	printf("listen\n");
	if(listen(sd, 5)){
			perror("lisiten");
			exit(1);
	}
	while(1){
			printf("accept\n");
		if((ns = accept(sd, (struct sockaddr *)&cli, &clientlen)) == -1){
				perror("accept");
				exit(1);
		}
		switch(fork()){
			case 0:
				close(sd);
				while(1){
					memset(buf,'\0',  BUFSIZ);
					if(recv(ns, buf, sizeof(buf), 0) == -1){
						perror("recv");
						exit(1);
					}
					printf("recv:%s\n", buf);
					if(send(ns, buf, strlen(buf) + 1, 0) == -1){
						perror("send");
						exit(1);
					}
					int a = strcmp(buf, "exit\n");
					if(a == 0){
							close(ns);
					}
		}
		}
	}
	return 0;
}

