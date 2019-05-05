#ifndef FT_NCURSESRENDERABLE_HPP
#define FT_NCURSESRENDERABLE_HPP

#include "IRenderable.hpp"

class NcursesRenderable : public virtual IRenderable
{
protected:
	WINDOW &screen;
	int height;
	int width;
	int row;
	int col;

public:
	NcursesRenderable(WINDOW &screen);
	~NcursesRenderable();
	NcursesRenderable(NcursesRenderable const &rhs);
	NcursesRenderable &operator=(NcursesRenderable const &rhs);

	virtual void render() const;
	void updateScreenSize();
	void moveByChar(int key);
};

#endif /* FT_NcursesRenderer_HPP */