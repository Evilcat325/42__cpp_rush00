#include "NcursesRenderable.hpp"

NcursesRenderable::NcursesRenderable()
		: screen(*stdscr)
{
	row = 0;
	col = 0;
	frame = 0;
	updateScreenSize();
}

NcursesRenderable::NcursesRenderable(WINDOW &screen)
		: screen(screen)
{
	row = 0;
	col = 0;
	frame = 0;
	updateScreenSize();
}

NcursesRenderable::~NcursesRenderable()
{
}

NcursesRenderable::NcursesRenderable(NcursesRenderable const &rhs)
		: screen(rhs.screen)
{
	*this = rhs;
}

NcursesRenderable &NcursesRenderable::operator=(NcursesRenderable const &rhs)
{
	row = rhs.row;
	col = rhs.col;
	frame = rhs.frame;
	return *this;
}

void NcursesRenderable::updateScreenSize()
{
	getmaxyx(&screen, height, width);
}

void NcursesRenderable::moveByChar(int key, bool check)
{
	if (key == KEY_UP && (!check || row - 1 >= 0))
		--row;
	else if (key == KEY_DOWN && (!check || row + 3 < height))
		++row;
	else if (key == KEY_LEFT && (!check || col - 1 >= 0))
		--col;
	else if (key == KEY_RIGHT && (!check || col + 3 < width))
		++col;
}

bool NcursesRenderable::render()
{
	frame++;
	return true;
}

void NcursesRenderable::verticalScroll()
{
	row++;
}

bool NcursesRenderable::movedOffScreen()
{
	if (row < -2 || row > height || col < -2 || col > width)
	{
		onScreen = false;
		return true;
	}
	return false;
}

void NcursesRenderable::detectCollision(int *&)
{
}

void NcursesRenderable::setRowCol(int r, int c)
{
	row = r;
	col = c;
}

bool NcursesRenderable::isOnScreen()
{
	return onScreen;
}
