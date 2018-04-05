#include "Score.h"
#include <iostream>


Score::Score(int in_x, int in_y)
	:
	x(in_x),
	y(in_y)
{
}

void Score::draw(Graphics & gfx) const
{

	gfx.drawRectdim(x, dimension, y, dimension, c);
}

bool Score::TestCollision(const Dude & dude) const
{
	const int duderight = dude.x + dude.width;
	const int dudebottom = dude.y + dude.height;
	const int scoreright = x + dimension;
	const int scorebottom = y + dimension;

	return duderight >= x && dude.x <= scoreright && dudebottom >= y && dude.y <= scorebottom;
}

void Score::respawn(int inx, int iny)
{
	x = inx;
	y = iny;
}
