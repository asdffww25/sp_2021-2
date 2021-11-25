#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	DIR *dp;
	struct dirent *dent;
	int kind1;
	int kind2;
	struct stat buf;
	
	if((dp = opendir(".")) ==NULL){
		perror("opendir: ..");
		exit(1);
	}
	printf("<Regular Files>\n");
	while((dent = readdir(dp))){
		stat(dent ->d_name, &buf);
		kind1 = buf.st_mode & S_IFMT;		
		if(dent -> d_name[0] == '.'){
			continue;
		}
		if(kind1 == S_IFREG){
			printf("%s\n", dent ->d_name);	
		}
	}
	closedir(dp);
	if((dp = opendir(".")) == NULL){
		perror("opendir: ..");
		exit(1);
	}
	printf("<Directories>\n");
	while((dent = readdir(dp))){
		stat(dent ->d_name, &buf);
		kind2 = buf.st_mode & S_IFMT;
		if(dent -> d_name[0] == '.'){
			continue;
		}
		if(kind2 == S_IFDIR){
			printf("%s\n", dent -> d_name);
		}
	
	}
	closedir(dp);
	return 0;
}

