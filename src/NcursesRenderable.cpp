#include "NcursesRenderable.hpp"

NcursesRenderable::NcursesRenderable(WINDOW &screen)
	: screen(screen), row(0), col(0)
{
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

NcursesRenderable &NcursesRenderable::operator=(NcursesRenderable const &)
{
	return *this;
}

void NcursesRenderable::updateScreenSize()
{
	getmaxyx(&screen, height, width);
}

void NcursesRenderable::moveByChar(int key)
{
	if (key == KEY_UP && row - 1 >= 0)
		--row;
	else if (key == KEY_DOWN && row + 1 < height)
		++row;
	else if (key == KEY_LEFT && col - 1 >= 0)
		--col;
	else if (key == KEY_RIGHT && col + 1 < width)
		++col;
}
