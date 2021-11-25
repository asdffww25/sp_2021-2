#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char* argv[]){
	if(argc != 4){
		printf("USAGE: ./a.out <filename> <start> <n bytes>\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp;
	int n;
	long cur;
	char buf[BUFSIZ] =  {0,};
	char bufnew[BUFSIZ] =  {0,};
	char* filename = argv[1];	
	char* start_pos_char = argv[2];
	int start_pos_int = 0;
	int char0_int1 = -1;

	if(isalpha(start_pos_char[0]) > 0){
		char0_int1 = 0;
	}
	else{
		start_pos_int = atoi(start_pos_char);
		char0_int1 = 1;
	}
	int n_bytes_to_read = atoi(argv[3]);
	

	if((fp = fopen(filename, "r")) == NULL){
			perror("fopen");
			exit(1);
	}
	cur = ftell(fp);

	if(char0_int1 == 1){
		if(start_pos_int >= 0){
			fseek(fp, start_pos_int, SEEK_CUR);
			} 
		else{
			fseek(fp, start_pos_int, SEEK_END);
		}
	}
	else{
		if(strcmp(start_pos_char, "begin") == 0){
			rewind(fp);
		}
		else if(strcmp(start_pos_char, "mid") == 0){
			fseek(fp, start_pos_int, SEEK_END);
			cur = ftell(fp);	

			fseek(fp, cur/2, SEEK_SET);
		}
		else if(strcmp(start_pos_char, "end") == 0){
			fseek(fp, start_pos_int , SEEK_END);
		}
	}

	cur = ftell(fp);
	
	n = fread(buf, sizeof(char), n_bytes_to_read, fp);
	printf("%d\n", n);
	buf[n] = '\0';
	int m = 0;
	do{
	if(n < n_bytes_to_read){
		rewind(fp);
		m = fread(bufnew, sizeof(char), n_bytes_to_read-n, fp);
		n_bytes_to_read = n_bytes_to_read - n;
		bufnew[m] = '\0';
		strncat(buf, bufnew, strlen(bufnew));
		if(n==0)	
			n_bytes_to_read = n_bytes_to_read - m;
	}
	}while(n_bytes_to_read > n);


	printf("Read = %s\n", buf);
/*
	n = fread(buf, sizeof(char), 4, fp);
	buf[n] = '\0';
	printf("-- Read Str = %s\n", buf);

	fseek(fp, 1, SEEK_CUR);
*/
	return 0;
}
