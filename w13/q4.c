#include <sys/mman.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	int fd;
	pid_t pid;
	caddr_t addr;
	struct stat statbuf;
	int rand;
	int n=0;
	if(argc !=2){
		fprintf(stderr, "Usage : %s filename\n", argv[0]);
		exit(1);
	}
	if(stat(argv[1], &statbuf) == -1){
		perror("stat");
		exit(1);
	}

	if((fd = open(argv[1], O_RDWR)) == -1){
		perror("open");
		exit(1);
	}

	addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0);
	if(addr == MAP_FAILED){
		perror("mmap");
		exit(1);
	}
	close(fd);
	switch(pid = fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			srand(time(NULL));
			while(n<100){
				rand = random()%100+1;
				//printf("child %d\n", rand);
				if(addr[rand] == 'c'){
					continue;
				}
				n++;
				addr[rand] = 'c';
				sleep(1);
				}
			break;
		default:
			for(int i = 0; i < 100; i++){
				rand = random()%100+1;
				//printf("parent %d\n", rand);
			
				addr[rand] = 'p';
				sleep(1);
			}
			break;
	}
	return 0;
}
	
