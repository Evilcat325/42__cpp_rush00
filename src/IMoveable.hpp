#ifndef FT_IMOVEABLE_HPP
#define FT_IMOVEABLE_HPP

class IMoveable
{
protected:
	int row;
	int col;

public:
	virtual void moveByChar(int key) = 0;
};

#endif /* FT_IMoveable_HPP */
