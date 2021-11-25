#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main(void){
	int ps, pd, n, m, rfd;
	char inmsg[80];
	char msg[] = "hello";
	char buf[BUFSIZ] = {0,};
	if((pd = open("./HAN_FIFO", O_RDONLY)) == -1){
		perror("open");
		exit(1);
	}
	if((ps = open("./MUN_FIFO", O_WRONLY)) == -1){
		perror("open");
		exit(1);
	}
	while(1){
		printf("Client =====\n");
		memset(buf, '\0', BUFSIZ);
		fgets(buf, BUFSIZ, stdin);
		printf("To Server : %s\n", buf);
		m = write(ps, buf, strlen(buf)+1);
		if(m == -1){
			perror("write");
			exit(1);
		}
		int a = strcmp(buf, "exit\n");
		if(a==0){
			close(ps);
			close(pd);
			break;
		}
		write(1, "From Server :", 13);
		memset(buf, '\0', BUFSIZ);

		if((n=read(pd, buf, BUFSIZ)) > 0){
			write(1, buf, n);
		}
		if(n == -1){

			exit(1);
		}

	}
	return 0;
}

