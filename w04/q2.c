#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define BUF_SZ 16
#define N_BYTE 1
int main(int argc, char* argv[]){
	char* src_filename = NULL;
	char* dst_filename = NULL;
	char* opt = NULL;
	char* opt_arg_char = NULL;
	int opt_arg_int = 0;
	if(argc == 3){
		src_filename = argv[1];
		dst_filename = argv[2];
	}
	else if(argc == 5){
			opt = argv[1];
			assert(strlen(opt)==2);
			assert(opt[0]=='-');
			assert(opt[1] == 'd');
			opt_arg_char = argv[2];
			opt_arg_int = atoi(opt_arg_char);
			src_filename = argv[3];
			dst_filename = argv[4];
	}
	else{
			printf("ERROR: 2 or 4 args...\n");
			exit(EXIT_FAILURE);
	}
	int n = 0;
	int c = 0;
	char buf[BUF_SZ];

	FILE* rfp = fopen(src_filename, "r");
	assert(rfp != NULL);

	FILE* wfp = fopen(dst_filename, "w");
	assert(wfp != NULL);

	
	while((c =fgetc(rfp)) != EOF){
		if(isalpha(c) > 0)
			c = c - (char) opt_arg_int;
		fputc(c, wfp);
	}
	if(n == -1) perror("Read");
	fclose(rfp);
	fclose(wfp);
	return 0;
}
      
