#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 0
int main(int argc, char* argv[]){
	if( argc != 3){
		printf("ERROR, not enough argument!\n");
		exit(EXIT_FAILURE);
	}
	char *user_env = argv[1];
	char *keyword = argv[2];
	char *ret;
	int v = -1;
	
	ret =  getenv(user_env);

	if( ret == NULL)
		printf("%s: not defined\n", user_env);
	else{
		//printf("%s: %s\n", user_env, ret);
		int len = strlen(ret);
		for(int i = 0; i < len-strlen(keyword); i++){
			int v = strncmp(keyword, ret+i, strlen(keyword));
			if(v == TRUE){
				printf("%s has %s\n", user_env, keyword);
				exit(EXIT_SUCCESS);
				break;
			}
		}	
	}
	printf("%s does not have %s\n", user_env, keyword);
	return 0;
}

