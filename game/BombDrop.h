//============================================================
// Natalie Killian
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
// File: BombFire.h
//		defines and handles all the dropped bombs; 
//		a BombFire has a list of Bombs
//============================================================

#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Weapon.h";
#include "AlienArmy.h"
#include "UI.h"
#include "Ship.h"
#include <list>
#include <cstdlib>

class BombDrop
{
private:
	list<Bomb> bombDrop;
	Texture bombTexture;
public:
	// constructor
	BombDrop()
	{
		// load the bombs texture
		if (!bombTexture.loadFromFile("greenBomb.png"))
		{
			cout << "Unable to load bomb texture!" << endl;
			exit(EXIT_FAILURE);
		}
	}
	// add dropped bombs to the group using a list
	void createBomb(Vector2f alienPos)
	{
		Bomb bomb(bombTexture);
		bomb.setPosition(alienPos);
		bombDrop.push_back(bomb);
	}
	// draw the bomb drop in the window
	void draw(RenderWindow &w)
	{
		list<Bomb>::iterator iter;
		for (iter = bombDrop.begin(); iter != bombDrop.end(); iter++)
		{
			iter->draw(w);
		}
	}
	// moves the bombs down the screen
	void moveDrop(float x, float y)
	{
		list<Bomb>::iterator iter;
		for (iter = bombDrop.begin(); iter != bombDrop.end(); iter++)
		{
			iter->move(x, y);
		}
	}
	// erases bombs from the list when they go off the bottom of screen
	void missDrop()
	{
		list<Bomb>::iterator iter;
		for (iter = bombDrop.begin(); iter != bombDrop.end();)
		{
			bool offScreen = false;
			Vector2f pos = iter->getPosition();
			if (pos.y > 600)
			{
				offScreen = true;
				iter = bombDrop.erase(iter);
			}
			if (!offScreen)
			{
				iter++;
			}
		}
	}
	// randomly picks an alien to drop the bomb from
	void randomDrop(AlienArmy &aliens, int &timer)
	{
		if (timer % 30 == 0)
		{
			int num = rand() % aliens.getSize();
			Sprite tempAlien = aliens.getSprite(num);
			Vector2f bombLocation = tempAlien.getPosition();
			createBomb(bombLocation);
			timer = 0;
		}
		timer++;
	}

	// detects if a bomb hits the ship
	bool isShipHit(Ship &ship, UI &menu)
	{
		int index;
		list<Bomb>::iterator iter;
		bool hit = false;
		// goes through and checks each bomb in the list for a hit with the ship
		for (iter = bombDrop.begin(); iter != bombDrop.end() && !hit; )
		{
			// checks if the missile location intersects with the alien location
			if ((iter)->getSprite().getGlobalBounds().intersects(ship.getSprite().getGlobalBounds()))
			{
				iter = bombDrop.erase(iter);
				hit = true;
				menu.loseLife();
			}
			if (!hit)		// if it hit nothing, check the next bomb
			{
				iter++;
			}
		}
		return hit;
	}

};