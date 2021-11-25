#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	srand(time(NULL));
	char mesg[]="Just a string";
	int row, col;
	initscr();
	getmaxyx(stdscr, row, col);
	
	mvprintw((rand()%row), (rand()%col), "%s", mesg);

	mvprintw(row-2, 0, "This screen has %d rows and %d columns\n", row, col);
	printw("Try resizing your window(if possible) and then run this program again");
	refresh();
	getch();
	endwin();

	return 0;
}
