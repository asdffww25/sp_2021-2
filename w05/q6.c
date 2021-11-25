#include <ncurses.h>

int main(){
	int ch;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	printw("Type any charcter to see it in bole\n");
	ch = getch();

	if(ch == KEY_F(1)){
			printw("F1 Key pressed");
	}

	else{
			printw("The pressed key is ");
			attron(A_BOLD);
			printw("%c", ch);
			attroff(A_BOLD);
		}
	refresh();
	getch();
	endwin();

	return 0;

}
