#include <netinet/in.h>
#include <sys/types.h>
#include <time.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORTNUM 9002

int main(void){
	int sd;
	char buf[BUFSIZ];
	struct sockaddr_in sin;
	printf("1\n");
	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	printf("socket\n");
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit(1);
	}
	printf("connect\n");
	if(connect(sd, (struct sockaddr *)&sin, sizeof(sin))){
		perror("connect");
		exit(1);
	}
	while(1){
		memset(buf,'\0',  BUFSIZ);
		fgets(buf, BUFSIZ, stdin);
		if(send(sd, buf, strlen(buf) + 1, 0) == -1){
        	perror("send");
            exit(1);
        }
		memset(buf,'\0',  BUFSIZ);
		if(recv(sd, buf, sizeof(buf), 0) == -1){
        	perror("recv");
            exit(1);
        }
		printf("recv:%s\n", buf);
		int a = strcmp(buf, "exit\n");
		if(a == 0){
				close(sd);
		}
	}
	return 0;

}

