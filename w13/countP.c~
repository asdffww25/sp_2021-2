#include <sys/mman.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
        
        char buffer[BUFSIZ];
	FILE *fd = fopen(argv[1], "r");
	char *s;
	int a, cnt=0;

	fgets(buffer, sizeof(buffer), fd);
	for(int i = 0; i < 100; i++){
		if(buffer[i] >100){
			cnt++;
	}
	}
	printf("p = %d, c = %d\n", cnt, 100-cnt);
	if(cnt > 50){
		printf("Parent Won!\n");
	}
	else if(cnt < 50){
		printf("Child Won!\n");
	}
	else{
		printf("Even!\n");
	}

	return 0;
}
