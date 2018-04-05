#pragma once
#include "Graphics.h"

class Meter
{
public:
	Meter(int in_x, int in_y);
	void increaselvl();
	float Getlvl()const;
	void draw(Graphics& gfx) const;
	void increaselevel(float dt);
private:
	static constexpr Color c = Colors::White;
	static constexpr int girth = 12;
	static constexpr float scale = 4.0f;
	float level = 0.0f;
	int x;
	int y;

};
