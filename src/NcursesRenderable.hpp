#ifndef FT_NCURSESRENDERABLE_HPP
#define FT_NCURSESRENDERABLE_HPP

#include "IRenderable.hpp"
#include "IMoveable.hpp"

class NcursesRenderable : virtual public IRenderable, virtual public IMoveable
{
protected:
	WINDOW &screen;
	int height;
	int width;

public:
	NcursesRenderable(WINDOW &screen);
	~NcursesRenderable();
	NcursesRenderable(NcursesRenderable const &rhs);
	NcursesRenderable &operator=(NcursesRenderable const &rhs);

	void updateScreenSize();
	void moveByChar(int key);
	void moveByTime();
};

#endif /* FT_NcursesRenderer_HPP */
