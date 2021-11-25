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
	int sd;
	char *s1 = "exit";
	char buf[BUFSIZ];
	struct sockaddr_in sin;

	printf("socket\n");
	if((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit(1);
	}
	memset((char *)&sin, '\0', sizeof(sin));
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	printf("connect\n");
	if(connect(sd, (struct sockaddr *)&sin, sizeof(sin))){
		perror("connect");
		exit(1);
	}
	while(1){
		memset(buf, '\0', BUFSIZ);
		scanf("%s",buf);
		int a = strcmp(buf, "exit");
		if(a == 0){	
			close(sd);
			exit(1);
		}
		printf("USER INPUT : %s\n", buf);
		send(sd, buf, strlen(buf) + 1, 0);
		
		memset(buf, '\0', BUFSIZ);
		if(recv(sd, buf, sizeof(buf), 0)>0){
		printf("RECV : %s\n", buf);
		}else{
		close(sd);
		exit(1);
		}
	}

	return 0;
}
