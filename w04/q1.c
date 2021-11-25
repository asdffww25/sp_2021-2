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
	int opt_arg_int	= 0;
	if(argc == 3){
		src_filename = argv[1];
		dst_filename = argv[2];
	}
	else if(argc == 5){
		opt = argv[1];
		assert(strlen(opt)==2);
		assert(opt[0]=='-');
		assert(opt[1] == 'c');
		opt_arg_char = argv[2];
		opt_arg_int = atoi(opt_arg_char);
		src_filename = argv[3];
		dst_filename = argv[4];
	}
	else{
		printf("ERROR: 2 or 4 args...\n");
        exit(EXIT_FAILURE);

	}
	int rfd, wfd, n;
	char buf[BUF_SZ];

	rfd = open(src_filename, O_RDONLY);

	if(rfd == -1){
		perror("Open src_filename");
		exit(1);
	}
	wfd = open(dst_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if(wfd == -1){
		perror("Open dst_filename");
		exit(1);
	}
	while((n = read(rfd, buf, N_BYTE)) > 0){
		if(isalpha(buf[0]) > 0)
			buf[0] = buf[0] + opt_arg_int;
		if(write(wfd, buf, n) != n) perror("Write");
	}
	if(n == -1) perror("Read");
	close(rfd);
	close(wfd);
	return 0;
}
