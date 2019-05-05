#include <ncurses.h>

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
	int nlines, ncols, y0, x0;
	x0 = 5;
	y0 = 5;
	nlines = 500;
	ncols = 500;
	initscr(); /* Start curses mode            */
	cbreak();
	keypad(stdscr, TRUE); /* We get F1, F2 etc..          */
	noecho();			  /* Don't echo() while we do getch */
	WINDOW *win = newwin(nlines, ncols, y0, x0);
	int ch;
	nodelay(stdscr, TRUE);
	while (1)
	{
		if ((ch = getch()) == ERR)
		{
			continue;
		}
		else
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
				whline(win, ACS_BULLET, 250);

			wmove(win, y0, x0);
			wrefresh(win);
		}
	}

	// wrefresh(win);

	refresh(); /* Print it on to the real screen */
	getch();   /* Wait for user input */
	endwin();  /* End curses mode                */

	return 0;
}
