#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct StudentInfo{
	char *name;
	char *major;
	char *univ;

};

void *start_thread(void *a){
	int i;
	struct StudentInfo *info = a;
	
	for( int i = 0; i < 10; i++){
//		sleep(1);
		printf("%s %s %s\n",info->name, info->major, info->univ);
//		sleep(1);
	}
	return a;
}
int main(void){
	pthread_t thr1, thr2;
	struct StudentInfo stu1, stu2;
	stu1.name = "Brad Pitt";
	stu1.major = "Computer Engineering";
	stu1.univ = "Holly University";
	
	stu2.name = "Angelina Jollie";
	stu2.major = "Computer Science";
	stu2.univ = "Wood University";

	printf("%s\n", stu1.name);	
	pthread_create(&thr1, NULL, start_thread,(void *)&stu1);
	pthread_create(&thr2, NULL, start_thread,(void *)&stu2);

	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);
	return 0;
}
