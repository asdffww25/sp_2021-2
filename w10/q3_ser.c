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

#define PORTNUM 9000

int main(void){
	struct servent *port;
	struct hostent *hp;
	struct in_addr in;
	char buf[BUFSIZ] = {0,};
	struct sockaddr_in sin, cli;
	int access_socket, comm_socket;
	int clientlen = sizeof(cli);
	int serverlen = sizeof(sin);

	printf("socket\n");
	if((access_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	printf("address\n");
	memset((char *)&sin, '\0', serverlen);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(PORTNUM);
	sin.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	printf("bind\n");
	if(bind(access_socket, (struct sockaddr *)&sin, serverlen)){
		perror("bind");
		exit(EXIT_FAILURE);
	}

	printf("listen\n");
	if(listen(access_socket, 5)){
		perror("listen");
		exit(EXIT_FAILURE);
	}

	printf("accept\n");
	if((comm_socket = accept(access_socket, (struct sockaddr *)&cli, &clientlen)) ==-1){
		perror("accept");
		exit(EXIT_FAILURE);
	}
	printf("client is now accepted\n");
	
	memset(buf,'\0',  BUFSIZ);
	sprintf(buf, "<Available Services>\n1. Echo server <ECHO>\n2. Get server info <SINFO>\n3. Get server time <STIME>\n");
	if(send(comm_socket, buf, strlen(buf) + 1, 0) == -1){
		perror("send");
		exit(EXIT_FAILURE);
	}
	memset(buf,'\0',  BUFSIZ);
	if(recv(comm_socket, buf, sizeof(buf), 0) == -1){
            	    perror("recv");
        	    exit(EXIT_FAILURE);
	        }
	printf("RECV: %s\n", buf);
	int a = strcmp(buf, "ECHO\n");
	int b = strcmp(buf, "SINFO\n");
	int c = strcmp(buf, "STIME\n");

	if(a == 0){
		while(1){
			memset(buf,'\0',  BUFSIZ);
			if(recv(comm_socket, buf, sizeof(buf), 0) == -1){
            	    perror("recv");
        		    exit(EXIT_FAILURE);
	       		}
			printf("RECV: %s\n", buf);
			if(send(comm_socket, buf, strlen(buf) + 1, 0) == -1){
				perror("send");
				exit(EXIT_FAILURE);
			}
			int a = strcmp(buf, "exit\n");
			if(a == 0){
				close(comm_socket);
				close(access_socket);
				exit(1);
			}	
		}
	}
	else if(b == 0){
		memset(buf,'\0',  BUFSIZ);
		hp = gethostent();
		sprintf(buf, "host_name = %s\nIP = %s\nport_num = %d\n",hp->h_name, inet_ntoa(sin.sin_addr), sin.sin_port);
		if(send(comm_socket, buf, strlen(buf) + 1, 0) == -1){
			perror("send");
			exit(EXIT_FAILURE);
		}
		close(comm_socket);
		close(access_socket);			
		}
	else if(c == 0){
		memset(buf,'\0',  BUFSIZ);
		time_t now;
		time(&now);
		sprintf(buf, "%s", ctime(&now));
		if(send(comm_socket, buf, strlen(buf) + 1, 0) == -1){
			perror("send");
			exit(EXIT_FAILURE);
		}
		close(comm_socket);
		close(access_socket);	        
	}
	return 0;
}
