#pragma once
#include "Graphics.h"

class Poo
{
public:
	void Init(int inX, int inY, int inVX, int inVY);
	void update();
	void Draw(Graphics& gfx) const;
	void consumtion(int dudex, int dudey, int dudeH, int dudeW); 
	bool Hit = false;
private:
	int x;
	int y;
	int vy;
	int vx;
	static constexpr int width = 24;
	static constexpr int height = 24;
	const int screenright = 600;
	const int screenleft = 200;
	
};
