#ifndef FT_IRENDERABLE_HPP
#define FT_IRENDERABLE_HPP

#include "ncurses.h"

class IRenderable
{
public:
	virtual void render() const = 0;
};

#endif /* FT_IRenderable_HPP */
