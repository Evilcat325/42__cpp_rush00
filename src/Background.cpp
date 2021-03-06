#include "Background.hpp"

Background::Background(WINDOW &screen)
	: NcursesRenderable(screen)
{

	for (int i = 0; i < 20; i++)
	{
		star_loc[i].x = rand() % width;
		star_loc[i].y = rand() % height;
	}
	init_pair(PLAYER1_PAIR, COLOR_BLUE, COLOR_BLACK);
	init_pair(PLAYER2_PAIR, COLOR_GREEN, COLOR_BLACK);
	init_pair(ENEMY_PAIR, COLOR_RED, COLOR_BLACK);
	init_pair(STAR_PAIR, COLOR_WHITE, COLOR_BLACK);
	init_pair(HP_PAIR, COLOR_GREEN, COLOR_RED);
	init_pair(P1_REST_HP_PAIR, COLOR_BLUE, COLOR_BLUE);
	init_pair(P2_REST_HP_PAIR, COLOR_GREEN, COLOR_GREEN);
}

Background::~Background()
{
}

Background::Background(Background const &rhs)
	: NcursesRenderable(rhs.screen)
{
	*this = rhs;
}

Background &Background::operator=(Background const &)
{
	return *this;
}

void Background::draw_star()
{
	static int c = 0;
	c++;
	for (int i = 0; i < 20; i++)
	{
		if (c % 60 == 0)
		{
			if (star_loc[i].y == height - 3)
			{
				star_loc[i].y = 0;
				star_loc[i].x = rand() % width;
			}
			else
				star_loc[i].y += 1;
			c = 0;
		}
		attron(COLOR_PAIR(STAR_PAIR));
		mvprintw(star_loc[i].y, star_loc[i].x, ".");
		attroff(COLOR_PAIR(STAR_PAIR));
	}
}

void Background::draw_hp(Player &p, int n)
{

	if (n == 1)
	{
		mvwaddstr(&screen, 1, 2, "HP ");
		attron(COLOR_PAIR(HP_PAIR));
		mvhline(1, 5, ' ', 10);
		attroff(COLOR_PAIR(HP_PAIR));
		attron(COLOR_PAIR(P1_REST_HP_PAIR));
		int rest = p.getHP() / 10;
		mvhline(1, 5, ' ', rest);
		attroff(COLOR_PAIR(P1_REST_HP_PAIR));
	}
	else if (n == 2)
	{
		mvwaddstr(&screen, 1, 18, "HP ");
		attron(COLOR_PAIR(HP_PAIR));
		mvhline(1, 21, ' ', 10);
		attroff(COLOR_PAIR(HP_PAIR));
		attron(COLOR_PAIR(P2_REST_HP_PAIR));
		int rest = p.getHP() / 10;
		mvhline(1, 21, ' ', rest);
		attroff(COLOR_PAIR(P2_REST_HP_PAIR));
	}
}
