#pragma once
#include "Graphics.h"
#include "Dude.h"

class Score
{
public:
	Score(int in_x, int in_y);
	void draw(Graphics& gfx) const;
	bool TestCollision(const Dude& dude) const;
	void respawn(int inx, int iny);
private:
	int x;
	int y;
	static constexpr int dimension = 20;
	static constexpr Color c = Colors::Blue; //blått eftersom man letar efter vatten på mars!

};
