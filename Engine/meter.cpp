#include "meter.h"

Meter::Meter(int in_x, int in_y)
	:
	x(in_x),
	y(in_y)
{
}

void Meter::increaselvl()
{
	++level;
}

float Meter::Getlvl() const
{
	return level;
}

void Meter::draw(Graphics & gfx) const
{
	gfx.drawRectdim(x, (int)(level*scale), y, girth, c);
}


void Meter::increaselevel(float dt)
{
	level = level + dt;
}