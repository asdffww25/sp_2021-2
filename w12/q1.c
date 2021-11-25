#include <stdlib.h>
#include <stdio.h>

int main(void){
	FILE *fp;
	int a;

	fp = popen("ls / | grep s", "w");
	if(fp == NULL){
		fprintf(stderr, "popen failed\n");
		exit(1);
	}

	pclose(fp);
	return 0;
}
