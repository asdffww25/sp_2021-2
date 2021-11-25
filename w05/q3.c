#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
	char *cwd;
	char wd[BUFSIZ];
	if(mkdir(argv[1], 0755) == -1){
		perror(argv[1]);
		exit(1);
	}
	chdir(argv[1]);

	int file = creat("README.txt", 0644);
}
