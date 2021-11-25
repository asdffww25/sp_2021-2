#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define TRUE 1
#define SIZ 32

int main(){
	//int row, col;
	//getmaxyx(stdscr, row, col);
	int i = 0;
	int cnt = 5;
	char buf[SIZ] = {0,};
	

	initscr();
	while(TRUE){
		mvprintw(0,0, "<Process Dashboard>");
		mvprintw(1,0, " ");
		sprintf(buf, "* Running Process (%d) :", cnt);
		mvprintw(2,0,"%s", buf);
		system("./extract-sleepFor-pids.sh > pids.txt");
		FILE* fp = fopen("pids.txt", "r");
		i = 0;
		while(fgets(buf, SIZ, fp)){
			mvprintw(3+i, 0, "%s", buf);
			i += 1;
			memset(buf, '\0', SIZ);
			if( i >= cnt ) break;
		}
		for (;i<= cnt; i++)
			mvprintw(3+i,0,"     ");
		fclose(fp);
		refresh();
		sleep(1);
	}
	
	endwin();

	return 0;
}
