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
	//g�ra om till private s� mycket som m�jligt, kanske m�ste flytta gameon bool till poo elr till dude f�r att det ska g�, det b�sta �r nog hit eftersom poo har en public Hit-bool.
private:
	int a = 358;
	int b = 268;
	
	static constexpr int speed = 2;
};
