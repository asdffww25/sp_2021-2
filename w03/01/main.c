#include <stdio.h>
extern int add(int a, int b);
extern int sub(int a, int b);
extern int mul(int a, int b);

int main(void){
	int num, num1, num2;
	int result=0;
	printf("Calculator Menu\n");
	printf("1. Add\n");
	printf("2. Sub\n");
	printf("3. Mul\n");
	printf("Enter : ");
	scanf("%d", &num);
	printf("Enter two numbers : ");
	scanf("%d%d", &num1, &num2);
	switch(num){
		case 1:
			result = add(num1, num2);
			printf("Result : %d + %d = %d\n", num1, num2, result);
			break;
		case 2:
			result = sub(num1, num2);
			printf("Result : %d - %d = %d\n", num1, num2, result);
			break;
		case 3:
			result = mul(num1, num2);
			printf("Result : %d * %d = %d\n", num1, num2, result);
			break;
	}
			
	return 0;
	}	

