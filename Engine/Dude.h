#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "GameOver.h"


class Dude
{
public:
	void updatedude(const Keyboard& kbd);
	void draw(Graphics& gfx) const;
	void clampToScreen();
	int getX();
	int getY();
	int getA();
	int getB();
	void respawn(int inx, int iny);
	static constexpr int height = 20;
	static constexpr int width = 20;
	int x0 = 400;
	int y0 = 300;
	int x = 400;
	int y = 100;
	//göra om till private så mycket som möjligt, kanske måste flytta gameon bool till poo elr till dude för att det ska gå, det bästa är nog hit eftersom poo har en public Hit-bool.
private:
	int a = 358;
	int b = 268;
	
	static constexpr int speed = 2;
};
