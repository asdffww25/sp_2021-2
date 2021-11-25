#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int rand = 0;

	for(int i = 0; i < 10; i++){
		rand = random()%100;
	
		printf("%d\n", rand);
	}
	return 0;
}
