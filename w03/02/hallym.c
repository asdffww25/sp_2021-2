#include <stdio.h>
#include <getopt.h>
int main(int argc, char *argv[]){
	int n;
	extern char* optarg;
	extern int optind;

	printf("Current Option : %d\n", optind);
	while((n = getopt(argc, argv, "au:h")) != -1){
	switch(n){
		case 'a':
			printf("Welcome to System Programming(2021-2)\n");
			break;
		case 'u':
			printf("Nice to meet yot, Argument=%s\n", optarg);
			break;
		case 'h':
			printf("option : a, u, h\n");
			break;
		}
	}
	if(argc == 1){
		printf("ERROR: please provide at least one option.\n");
	}
	return 0;
	}

