#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t lock1;
pthread_mutex_t lock2;
pthread_mutex_t lock3;


void *func1(void *a){
	pthread_mutex_lock(&lock3);
	printf("func1 start\n");
	pthread_mutex_lock(&lock1);
	printf("func1 lock1\n");	
	sleep(1);
	pthread_mutex_lock(&lock2);
	printf("func1 lock2\n");	
	pthread_mutex_unlock(&lock1);
	pthread_mutex_unlock(&lock2);
	printf("func1 end\n");
	pthread_mutex_unlock(&lock3);

}
void *func2(void *b){
	pthread_mutex_lock(&lock3);
	printf("func2 start\n");
	pthread_mutex_lock(&lock2);
	printf("func2 lock2\n");
	sleep(1);
	pthread_mutex_lock(&lock1);
	printf("func2 lock1\n");
	pthread_mutex_unlock(&lock2);
	pthread_mutex_unlock(&lock1);
	printf("func2 end\n");
	pthread_mutex_unlock(&lock3);
}
int main(void){
	pthread_t thr1, thr2;
	printf("start\n");
	pthread_create(&thr1, NULL, func1,NULL);
	pthread_create(&thr2, NULL, func2,NULL);

	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);
	return 0;
}
