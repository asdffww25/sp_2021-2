#include <stdio.h>
#include <stdlib.h>

int main(void){
        int size = 10;
        int n = 0;
        int* arr;
        int sum = 0;
        int after, before;
        arr = malloc(sizeof(int)*size);
        for(int i =0; i < size; i++){
                arr[i] = n++;
		sum += n;
                if(n==size){
                        before = size;
                        size = size *2;
                        after = size;
                        arr = realloc(arr, sizeof(int)*size);
#ifdef DEBUG
                        printf("Size up: %d => %d\n", before, after);
#endif
                }
      
                if(n==100){
                        break;
                }
	}
		printf("n = %d, size = %d, sum = %d\n", n, size, sum);
	for(int i = n; i>10; i--){
		arr[i] = 0;
		n--;
		if(n <= size/4){
			before = size;
			size = size/2;
			after = size;
			arr = realloc(arr, sizeof(int)*size);
#ifdef DEBUG
			printf("Size down = %d => %d\n", before, after);
#endif
		}
	}
	sum=0;
	for(int i = 0; i <= n; i++){
		
		sum += arr[i];
		}

	printf("n = %d, size = %d, sum = %d\n", n, size, sum);
}
