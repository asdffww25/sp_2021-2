#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]){
	in_addr_t addr;
	struct hostent *hp;
	struct in_addr in;
	sethostent(0);
	hp = gethostbyname(argv[1]);
	if(hp == NULL){
		printf("Not Found\n");
		exit(2);
	}
	memcpy(&in.s_addr, *hp->h_addr_list, sizeof(in.s_addr)); 0;
	printf("Name = %s, IP = %s\n", hp->h_name, inet_ntoa(in));
	endhostent();
        return 0;
}

