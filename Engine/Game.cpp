/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"
#include <iostream>
#include <random>
#include <chrono>


Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng( rd ()),
	xDist(200, 570),
	yDist0(200, 570),
	yDist1(0, 570),
	vDist(-3, 3), // ändring till float istället för int 
	score(xDist(rng), yDist1(rng)),
	meter(20, 20)
{
	
	for (int i = 0; i < nPoo1; i++)
	{
		poo1[i].Init(xDist(rng), yDist0(rng), vDist(rng), vDist(rng));
	}
	for (int i = 0; i < nPoo0; i++)
	{
		poo[i].Init(xDist(rng), yDist0(rng), vDist(rng), vDist(rng));
	} //memoryleak borde egentligen bara skapas ifall rätt planet väljs, men detta har låg prioritering
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}


void Game::UpdateModel()
{
	const float dt = tt.mark();
	dude.clampToScreen();
	bool träff = false;
	bool träff0 = false;
	for (int i = 0; i < nPoo1; i++)
	{
		träff = träff || poo1[i].Hit;
	}
	
	for (int i = 0; i < nPoo0; i++)
	{
		träff = träff || poo[i].Hit;
	}
	

	
	if (titG == titleogame::gaming)
	{
		if (Pstate == planetState::mars && state == State::game)
		{

			for (int i = 0; i < nPoo0; i++)
			{
				poo[i].update();
				poo[i].consumtion(dude.x, dude.y, dude.height, dude.width);
			}
			//if (state == State::game)
			//{
			if (dude.x <= 200 || (dude.x + dude.width) >= 600 || träff || träff0)
			{
				state = State::over;

			}
			dude.updatedude(wnd.kbd);


			if (score.TestCollision(dude))
			{
				score.respawn(xDist(rng), yDist1(rng));
				meter.increaselvl();
			}
		}
		
		else if (Pstate == planetState::jorden && state == State::game) 
		{

			for (int i = 0; i < nPoo1; i++)
			{
				poo1[i].update();
				poo1[i].consumtion(dude.x, dude.y, dude.height, dude.width);
			}
		
			if (dude.x <= 200 || (dude.x + dude.width) >= 600 || träff || träff0)
			{
				state = State::over;

			}
			else
			{
				dude.updatedude(wnd.kbd);
				meter.increaselevel(dt);
			}
			//}

		}
		
		else if (state == State::over )
		{

			if (wnd.kbd.KeyIsPressed(VK_BACK))
			{
				dude.respawn(400, 100);
				state = State::start;
				titG = titleogame::title;
				Pstate = planetState::inget;	
				//delete pointplanet;
				//pointplanet = nullptr;
			}
		}
	}
	else if (titG == titleogame::title)
	{
		if (wnd.kbd.KeyIsPressed(VK_RETURN))
		{
			Pstate = planetState::jorden;
			state = State::game;
			titG = titleogame::gaming;
			//pointplanet = Jorden();
		}
		else if (wnd.kbd.KeyIsPressed(VK_SHIFT))
		{
			Pstate = planetState::mars;
			titG = titleogame::gaming;
			state = State::game;
			//pointplanet = Mars();
		}
	}
}


void Game::Mars()
{

	gfx.drawRect(x0, x1, y0, y1, Colors::Red);
	gfx.drawRectdim(x2, width, y2, height, Colors::Red);
	meter.draw(gfx);
	for (int i = 0; i < nPoo0; i++)
	{
		poo[i].Draw(gfx);
	}
	if (state == State::game)
	{
		dude.draw(gfx);
		score.draw(gfx);
	}
	else if (state == State::over)
	{
		GOver.draw(gfx);

	}

}

void Game::Jorden()
{

	gfx.drawRect(x0, x1, y0, y1, Colors::Blue);
	gfx.drawRectdim(x2, width, y2, height, Colors::Blue);
	meter.draw(gfx);
	for (int i = 0; i < nPoo1; i++)
	{
		poo1[i].Draw(gfx);
	}
	if (state == State::over)
	{
		GOver.draw(gfx);

	}
	else if (state == State::game)
	{
		dude.draw(gfx);

	}
	

	
}

void Game::Inget()
{
}


void Game::ComposeFrame()
{
	/*if (state == State::start)
	{

	}*/
	if (titG == titleogame::gaming)
	{
		if (Pstate == planetState::mars)
		{
			Mars();
			//pointplanet;
		}

		else if (Pstate == planetState::jorden)
		{
			Jorden();//gör pointer till jorden och mars, och radera dessa ifall gameover.
		}
	}
	else if (titG == titleogame::title)
	{ 
		title.draw(gfx);
	}
}