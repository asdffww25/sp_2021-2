#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct Account{
	int cnt;
	int balance;
	int saving;
	int amount1;
	int amount2;
};

void disburse_money(struct Account *account, int amount){
	if(account->saving < amount){
		printf("disburse no money\n");
		exit(1);
	}
	else{
		account->saving = account->saving - amount;
		account->balance = account->saving;
		printf("disb => amount : %d, saving : %d\n", amount, account->saving);
	}
}

void *withdraw(void *a){
	struct Account *account = a;
	
	if(account->cnt == 0){
		account->cnt++;
	printf("with1 => amount1 : %d, balance : %d\n", account->amount1, account->balance);
	if(account->balance < account->amount1 ){
		printf("withdraw no money\n");
		exit(0);
	}
	printf("agree\n");
	sleep(3);
	account->balance = account->balance - account->amount1;
	
	printf("with2 => amount1 : %d, balance : %d\n", account->amount1, account->balance);
	disburse_money(account, account->amount1);//saving
	}
	else if(account->cnt == 1){
		account->cnt++;
		printf("with1 => amount2 : %d, balance : %d\n", account->amount2, account->balance);
	if(account->balance < account->amount2 ){
		printf("withdraw no money\n");
		exit(0);
	}
	printf("agree\n");
	account->balance = account->balance - account->amount2;
	
	printf("with2 => amount2 : %d, balance : %d\n", account->amount2, account->balance);
	disburse_money(account, account->amount2);//saving
	}
}
int main(void){
	struct Account account;
       	pthread_t thr1, thr2;
	account.cnt = 0;
	account.balance = 500;
	account.saving = account.balance;
	account.amount1 = 300;
	printf("balance %d saving %d amount1 %d\n", account.balance, account.saving, account.amount1);
	pthread_create(&thr1, NULL, withdraw,(void *)&account);
	sleep(1);
	account.amount2 = 400;
	printf("balance %d saving %d amount2 %d\n", account.balance, account.saving, account.amount2);
	pthread_create(&thr2, NULL, withdraw,(void *)&account);
	
	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);
	return 0;
}

