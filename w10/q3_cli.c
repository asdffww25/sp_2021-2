#include <netdb.h>
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
    struct sockaddr_in sin;
    int sock;
    int serverlen = sizeof(sin);

    printf("socket\n");
    if((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket");
        exit(EXIT_FAILURE);
    }
	
	printf("address\n");
	memset((char *)&sin, '\0', serverlen);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORTNUM);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");

	printf("connect\n");
	if(connect(sock, (struct sockaddr *)&sin, serverlen)){
		perror("connect");
		exit(EXIT_FAILURE);
	}
	
	memset(buf, '\0', BUFSIZ);

	if(recv(sock, buf, sizeof(buf), 0) == -1){
		perror("recv");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", buf);

	memset(buf, '\0', BUFSIZ);
	fgets(buf, BUFSIZ, stdin);
	printf("buf = %s\n", buf);
	if(send(sock, buf, strlen(buf) + 1, 0) == -1){
		perror("send");
		exit(EXIT_FAILURE);
	}
	int a = strcmp(buf, "ECHO\n");
	int b = strcmp(buf, "SINFO\n");
    int c = strcmp(buf, "STIME\n");
 
	if(a==0){
			while(1){
				memset(buf, '\0',BUFSIZ);
				fgets(buf, BUFSIZ, stdin);
				printf("buf = %s\n", buf);
				if(send(sock, buf, strlen(buf) + 1, 0) == -1){
					perror("send");
					exit(EXIT_FAILURE);
				}
				memset(buf, '\0',BUFSIZ);
				if(recv(sock, buf, sizeof(buf), 0) == -1){
		            perror("recv");
		            exit(EXIT_FAILURE);
		        }
				printf("RECV: %s\n", buf);
			

		int a = strcmp(buf, "exit\n");
            if(a == 0){
                close(sock);
                exit(1);
			}
		}
	}
	else if(b == 0){
		memset(buf, '\0',BUFSIZ);
		if(recv(sock, buf, sizeof(buf), 0) == -1){
        	perror("recv");
            exit(EXIT_FAILURE);
        }
		printf("RECV: %s\n", buf);
		close(sock);
		exit(1);
	}
	else if(c == 0){
		memset(buf, '\0',BUFSIZ);
		if(recv(sock, buf, sizeof(buf), 0) == -1){
        	perror("recv");
            exit(EXIT_FAILURE);
        }
		printf("RECV: %s\n", buf);
		close(sock);
		exit(1);
	}
	return 0;
}
