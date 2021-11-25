#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(){
	srand(time(0));
	int upper = 30;
	int lower = 10;
	int n = (rand() % (upper - lower +1)) + lower;

	printf("%d\n",n);

	printf("Hello world begins.\n");
	sleep(n);
	printf("Hello world ends\n");
	return 0;
}
