#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
	struct stat buf;
	int kind;
	stat(argv[1], &buf);
	
        kind = buf.st_mode & S_IFMT;
	printf("Filename : %s\n", argv[1]);
	printf("- inode number : %d\n", (int)buf.st_ino); 
	switch(kind){
		case S_IFIFO:
			printf("- File type : FIFI\n");
			break;
		case S_IFDIR:
			printf("- File type : Directory\n");
			break;
		case S_IFREG:
			printf("- File type : Tegular File\n");
			break;	
	}
	printf("- Permission : %o\n", (unsigned int)buf.st_mode -(unsigned int)pow(8,5));
	printf("- Number of links : %o\n", (int)buf.st_nlink); 

	printf("- Size : %d\n", (int)buf.st_size); 
}
