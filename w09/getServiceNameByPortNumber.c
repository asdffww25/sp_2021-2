#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	struct servent *port;
	int n;
	int i = 1;
	setservent(0);
	while(i < argc){
		n = atoi(argv[i]);
		port = getservbyport(htons(n),"tcp");
		printf("Name = %s, Port = %d\n", port->s_name, ntohs(port->s_port));
		i++;
	}
	endservent();
	
	return 0;
}
