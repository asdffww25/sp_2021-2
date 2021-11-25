#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <time.h>

#define PORTNUM 9000

int main(void){
        char buf[BUFSIZ] = {0,};
        struct sockaddr_in sin, cli;
        int sock;
        int clientlen = sizeof(cli);
        int serverlen = sizeof(sin);

        printf("socket\n");
        if((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1){
                perror("socket");
                exit(EXIT_FAILURE);
        }

        printf("address\n");
        memset((char *)&sin, '\0', serverlen);
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORTNUM);
        sin.sin_addr.s_addr = inet_addr("127.0.0.1");

	printf("bind\n");
        if(bind(sock, (struct sockaddr *)&sin, serverlen)){
                perror("bind");
                exit(EXIT_FAILURE);
        }

        memset(buf,'\0',  BUFSIZ);
	if(recvfrom(sock, buf, sizeof(buf), 0, (struct sockaddr *)&cli, &clientlen) == -1){
        	perror("recv");
        	exit(EXIT_FAILURE);
        }
        printf("RECV: %s\n", buf);
	
        memset(buf,'\0',  BUFSIZ);
	time_t now;
	time(&now);
	sprintf(buf, "%s", ctime(&now));
        if(sendto(sock, buf, strlen(buf) + 1, 0, (struct sockaddr *)&cli, sizeof(cli)) == -1){
		perror("send");
                exit(EXIT_FAILURE);
	}
       	close(sock);

        return 0;
}

