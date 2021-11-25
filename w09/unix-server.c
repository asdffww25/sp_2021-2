#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>


#define SOCKET_NAME	"hsocket"

int main(void){
	char buf[BUFSIZ];
	char buff[BUFSIZ];
	struct sockaddr_un ser, cli;
	int sd, nsd, len, clen, n;
	FILE *rfp;
	if((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit(1);
	}

	memset((char *)&ser, 0, sizeof(struct sockaddr_un));
	ser.sun_family = AF_UNIX;
	strcpy(ser.sun_path, SOCKET_NAME);
	len = sizeof(ser.sun_family) + strlen(ser.sun_path);
	
	if(bind(sd, (struct sockaddr *)&ser, len)){
		perror("bind");
		exit(1);
	}

	if(listen(sd, 5) < 0){
		perror("listen");
		exit(1);
	}

	printf("Waiting ...\n");
	if((nsd = accept(sd, (struct sockaddr *)&cli, &clen)) == -1){
		perror("accept");
		exit(1);
	}
	if(recv(nsd,buf,sizeof(buf),0)==-1){
		perror("recv");
		exit(1);
	}
	rfp = fopen(buf, "r");
	memset(buf,'\0', BUFSIZ);
	n = fread(buf, sizeof(char), 16, rfp);
	printf("%s\n", buf);
	
	
	fclose(rfp);	
	close(nsd);
	close(sd);

	return 0;
}
