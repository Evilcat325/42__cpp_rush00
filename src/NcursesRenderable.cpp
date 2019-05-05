#include "NcursesRenderable.hpp"

NcursesRenderable::NcursesRenderable(WINDOW &screen)
<<<<<<< HEAD
	: screen(screen), row(0), col(0)
=======
		: screen(screen)
>>>>>>> 0a0eec4c99791ab0006bae18c73320d1f627a5b1
{
	row = 0;
	col = 0;
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
	else if (key == KEY_DOWN && row + 3 < height)
		++row;
	else if (key == KEY_LEFT && col - 1 >= 0)
		--col;
	else if (key == KEY_RIGHT && col + 3 < width)
		++col;
}
