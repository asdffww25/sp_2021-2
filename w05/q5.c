#include <stdio.h>
#include <dirent.h>

int main(int argc, char* argv[]){
	rename(argv[1], argv[2]);
	return 0;
}
