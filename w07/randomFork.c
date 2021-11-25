#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
	srand(time(0));	
	if(argc != 2){
		printf("ERROR : needs two arg...\n");
		exit(EXIT_SUCCESS);
	}

	double prob = atof(argv[1]);
	double p;
	pid_t pid;
	pid_t pid4wait;
	int status;
	printf("Prob : %f\n", prob);
	while((p = rand() / (RAND_MAX * 1.0)) <= prob){
		pid = fork();		
		printf("My PID : %d, My Parent PPID : %d\n", getpid(), getppid());
		if(pid > 0){
			pid4wait = wait(&status);
			printf("Waited pid : %d\n", pid4wait);
		}
	}
	return 0;

}
