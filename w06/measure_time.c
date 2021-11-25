#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <limits.h>
#include <time.h>

#define SIZ 50000
void func_O1(int *arr){
		int len = sizeof(arr);
}
void func_ON(int *arr){
		long int sum = 0;
		for(int i = 0; i < SIZ; i++) sum += arr[i];
}
void func_ON2(int *arr){
		long int sum = 0;
		for(int i = 0; i < SIZ; i++)
				for(int i = 0; i < SIZ; i++)
						sum += arr[i];
}

int main(){
		int buf[SIZ];
		int i = 0;
		for(i = 0; i < SIZ; i++){
			buf[i] = i;
		}
		time_t t;
		struct tms mytms;
		clock_t t1, t2, t3, t4, t5, t6;

		if((t1 = times(&mytms)) == -1){
				perror("times 1");
				exit(1);
		}
		func_O1(buf);
		
		if((t2 = times(&mytms)) == -1){
				perror("times 2");
				exit(1);
		}
	printf("func_O1 takes %1f seconds\n", (double)(t2-t1) / CLOCKS_PER_SEC);
		if((t3 = times(&mytms)) == -1){
				perror("times 3");
				exit(1);
		}
		func_ON(buf);
		
		if((t4 = times(&mytms)) == -1){
				perror("times 4");
				exit(1);
		}
	printf("func_ON takes %1f seconds\n", (double)(t4-t3) / CLOCKS_PER_SEC);
		if((t5 = times(&mytms)) == -1){
				perror("times 5");
				exit(1);
		}
		func_ON2(buf);
		
		if((t6 = times(&mytms)) == -1){
				perror("times 6");
				exit(1);
		}
	printf("func_ON2 takes %1f seconds\n", (double)(t6-t5) / CLOCKS_PER_SEC);
	
	
	return 0;
}	
				
