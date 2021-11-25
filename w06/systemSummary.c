#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define INFO_MSG "systemSummary available options:\n-s : print OS name\n-n : print nodename (hostname)\n-v : print version\n-m : print machine info\n"
#define SIZ 32
int main(int argc, char* argv[]){
	struct utsname uts;
	extern char *optarg;
	extern int optind;
	int n;
	char* add_n = "named ";
	char* add_s = " machine";
	char s_buf[SIZ] = {0,};
	char v_buf[SIZ] = {0,};
	char n_buf[SIZ] = {0,};
	char m_buf[SIZ] = {0,};
	if(uname(&uts) == -1) {
			perror("uname");
			exit(1);
	}
	if(argc == 1){
			printf(INFO_MSG);
			exit(EXIT_SUCCESS);
	}

	while((n = getopt(argc, argv, "snvm")) != -1){
	switch(n){
		case 's':
			strncpy(s_buf, uts.sysname, strlen(uts.sysname));
			strncat(s_buf, add_s, strlen(add_s));
			break;
		case 'n':
			strncpy(n_buf, add_n, strlen(add_n));
			strncat(n_buf, uts.nodename, strlen(uts.nodename));
			break;
		case 'v':
			strncpy(v_buf, uts.release, strlen(uts.release));
			break;
		case 'm':
			strncpy(m_buf, uts.machine, strlen(uts.machine));
			break;
		
		}
	}
	printf("this is a %s %s %s %s\n", m_buf, v_buf, s_buf, n_buf);

		return 0;
}
