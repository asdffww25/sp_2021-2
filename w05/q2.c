#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
if(argc == 2){
		struct stat buf;
		stat(argv[1], &buf);

		printf("permission = %o\n", (unsigned int) buf.st_mode);
	}
	if(argc > 2){	
		struct stat buf;
		stat(argv[2], &buf);
		int a =atoi(argv[1]);
		int hund = a/100;
		int ten = a%100/10;
		int one = a%10;
		char *s1;
		char *s2;
		char *s3;
	
		buf.st_mode &= !(S_IRWXU | S_IRWXG | S_IRWXO);
	
		switch(hund){
			case 7:
				buf.st_mode |= S_IRWXU;
				s1 = "rwx";
				break;
			case 6:
				buf.st_mode |= S_IRUSR;
				buf.st_mode |= S_IWUSR;
				s1 = "rw-";
				break;
			case 5:
				buf.st_mode |= S_IRUSR;
				buf.st_mode |= S_IXUSR;
				s1= "r-x";
				break;
			case 4:
				buf.st_mode |= S_IRUSR;
				s1 = "r--";
				break;
			case 3:
				buf.st_mode |= S_IWUSR;
				buf.st_mode |= S_IXUSR;
				s1 = "-wx";
				break;
			case 2:
				buf.st_mode |= S_IWUSR;
				s1 = "-w-";
				break;
			case 1:
				buf.st_mode |= S_IXUSR;
				s1 = "--x";
				break;
			case 0:
				buf.st_mode &= ~(S_IRWXU);
				s1 = "---";
				break;
			}
		
		switch(ten){
			case 7:
				buf.st_mode |= S_IRWXG;
				s2 = "rwx";
				break;
			case 6:
				buf.st_mode |= S_IRGRP;
				buf.st_mode |= S_IWGRP;
				s2 = "rw-";
				break;
			case 5:
				buf.st_mode |= S_IRGRP;
				buf.st_mode |= S_IXGRP;
				s2 = "r-x";
				break;
			case 4:
				buf.st_mode |= S_IRGRP;
				s2 = "r--";
				break;
			case 3:
				buf.st_mode |= S_IWGRP;
				buf.st_mode |= S_IXGRP;
				s2 = "-wx";
				break;
			case 2:
				buf.st_mode |= S_IWGRP;
				s2 = "-w-";
				break;
			case 1:
				buf.st_mode |= S_IXGRP;
				s2 = "--x";
				break;
			case 0:
				buf.st_mode &= ~(S_IRWXG);
				s2 = "---";
				break;
			}
		
		switch(one){
			case 7:
				buf.st_mode |= S_IRWXO;
				s3 = "rwx";
				break;
			case 6:
				buf.st_mode |= S_IROTH;
				buf.st_mode |= S_IWOTH;
				s3 = "rw-";
				break;
			case 5:
				buf.st_mode |= S_IROTH;
				buf.st_mode |= S_IXOTH;
				s3 = "r-x";
				break;
			case 4:
				buf.st_mode |= S_IROTH;
				s3 = "r--";
				break;
			case 3:
				buf.st_mode |= S_IWOTH;
				buf.st_mode |= S_IXOTH;
				s3 = "-wx";
				break;
			case 2:
				buf.st_mode |= S_IWOTH;
				s3 = "-w-";
				break;
			case 1:
				buf.st_mode |= S_IXOTH;
				s3 = "--x";
				break;
			case 0:
				buf.st_mode &= ~(S_IRWXO);
				s3 = "---";
				break;
			}
		
		chmod(argv[2], buf.st_mode);
			
		
		printf("%o\n", (unsigned int)buf.st_mode);
		printf("%s", s1);
		printf("%s",s2);
		printf("%s\n",s3);
	}
}


