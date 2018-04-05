/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Dude.h"
#include "GameOver.h"
#include "Poo.h"
#include "Score.h"
#include "meter.h"
#include "timer.h"
#include "Titel.h"
#include <random>

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
	
public:
	enum class planetState
	{
		jorden,
		mars,
		inget
	};
private:
	void ComposeFrame();
	void UpdateModel();
	void Mars();
	void Jorden();
	void Inget();
	/********************************/
	/*  User Functions              */
	/********************************/
public:
	enum class State
	{
		start,
		game,
		over
	};
public:
		enum class titleogame
		{
			title,
			gaming
		};
private:
	
	MainWindow& wnd;
	Graphics gfx;
	timer tt;
	Dude dude;
	GameOver GOver;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist0;
	std::uniform_int_distribution<int> yDist1;
	std::uniform_int_distribution<int> vDist;
	Score score;
	Meter meter;
	State state = State::start;
	planetState Pstate = planetState::inget;
	titleogame titG = titleogame::title;
	int x0 = 0;
	int y0 =0;
	int x1 = 200;
	int y1 = 599;
	int x2 = 600;
	int y2 = 0;
	int width = 200;
	int height = 599;
	static constexpr int nPoo0 = 10;
	static constexpr int nPoo1 = 20;
	Poo poo[nPoo0];
	Poo poo1[nPoo1];
	titel title;
	/*Poo poo0;
	Poo poo1;
	Poo poo2;
	Poo poo3;
	Poo poo4;*/
	bool gameon;

};


