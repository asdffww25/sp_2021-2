#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
	int pd, n, i, m, ps, rfd;
	char inmsg[80];

	char *arr[10] = {NULL, };
	char msg[] = "Hello, FIFO";
	char buf[BUFSIZ] = {0,};
	printf("server =====\n");
	if(mkfifo("./HAN_FIFO", 0666) == -1){
		perror("mkfifo");
		exit(1);
	}
	if(mkfifo("./MUN_FIFO", 0666) == -1){
		perror("mkfifo");
		exit(1);
	}
	
	if((pd = open("./HAN_FIFO", O_WRONLY)) == -1){
		perror("open");
		exit(1);
	}
	if((ps = open("./MUN_FIFO", O_RDONLY)) == -1){
		perror("open");
		exit(1);
	}
	while(1){
		memset(buf, '\0', BUFSIZ);
		memset(arr, '\0', 10);
		i = 0;
		write(1,"From Client :", 13);
		if((m = read(ps, buf, BUFSIZ)) > 0){
			write(1, buf, m);
		}
		if(m == -1){
			perror("read");
			exit(1);
		}
		printf("To Client : %s\n", buf);
		int a = strcmp(buf, "exit\n");
		if(a == 0){
			close(ps);
			close(pd);
			break;
		}
		char *ptr = strtok(buf, " ");
		while(ptr != NULL){
			arr[i] = ptr;
			i++;	

			ptr = strtok(NULL, " ");
		}
		char *ptr1 = strtok(arr[1], "\n");
		int b = strcmp(arr[0], "<get>");
			if(b == 0){
				printf("1\n");
				printf("%s\n", arr[1]);
				rfd = open(ptr1, O_RDONLY);
				if(rfd == -1){
					perror("noopen\n");
				}
				else{
					n = write(pd, &rfd, 128);
					if(n == -1){
						perror("write");
						exit(1);
					}
					printf("open\n");
				}
			}
		write(1, "\n", 1);
		n = write(pd, buf, strlen(buf)+1);
		if(n == -1){
			perror("write");
			exit(1);
		}
	}
	close(rfd);
	close(pd);
	close(ps);
	return 0;
}
