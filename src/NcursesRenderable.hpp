#ifndef FT_NCURSESRENDERABLE_HPP
#define FT_NCURSESRENDERABLE_HPP

#include "IRenderable.hpp"
#include "IMoveable.hpp"
#include <iostream>

class NcursesRenderable : virtual public IRenderable, virtual public IMoveable
{
protected:
	WINDOW &screen;
	int height;
	int width;
	int frame;

public:
	NcursesRenderable();
	NcursesRenderable(WINDOW &screen);
	~NcursesRenderable();
	NcursesRenderable(NcursesRenderable const &rhs);
	NcursesRenderable &operator=(NcursesRenderable const &rhs);

	void updateScreenSize();
	void moveByChar(int key);
	void moveByTime();
	void setRowCol(int r, int c);
	virtual bool render();
	virtual void renderPerSec();
	virtual void verticalScroll();
	virtual void detectCollision(int *&);
};

#endif /* FT_NcursesRenderer_HPP */
