#include <ncurses.h>

void initialization()
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
}
//  key code        description
//            KEY_DOWN        The four arrow keys ...
//            KEY_UP
//            KEY_LEFT
//            KEY_RIGHT
//            KEY_HOME        Home key
//            KEY_BACKSPACE   Backspace
//            KEY_F(n)        Function keys, for 0 <= n >= 63
//            KEY_DC          Delete character
//            KEY_IC          Insert char or enter insert mode
//            KEY_ENTER       Enter or send
int main()
{
	int w = 500, h = 500, x0 = 5, y0 = 5;
	int ch;
	initialization();
	nodelay(stdscr, TRUE);
	getmaxyx(stdscr, h, w);
	while (1)
	{
		if ((ch = getch()) != ERR)
		{
			if (ch == KEY_DOWN)
				y0 += 1;
			else if (ch == KEY_UP)
				y0 -= 1;
			else if (ch == KEY_RIGHT)
				x0 += 1;
			else if (ch == KEY_LEFT)
				x0 -= 1;
			else if (ch == KEY_BACKSPACE)
				whline(stdscr, ACS_BULLET, 250);
			wmove(stdscr, y0, x0);
			wrefresh(stdscr);
		}
	}

	// wrefresh(win);

	refresh(); /* Print it on to the real screen */
	getch();	 /* Wait for user input */

	endwin();
	return 0;
}
