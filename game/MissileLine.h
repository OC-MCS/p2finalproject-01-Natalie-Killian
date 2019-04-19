//============================================================
// Natalie Killian
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
// File: MissileLine.h
//		defines and handles all the fired missiles; 
//		a MissileLine has a list of Missiles
//============================================================

#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Weapon.h";
#include "AlienArmy.h"
#include "UI.h"
#include <list>;

class MissileLine
{
private:
	list<Missile> missileLine;
	Texture missileTexture;
public:
	// constructor
	MissileLine()
	{
		// load the missile texture
		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load alien texture!" << endl;
			exit(EXIT_FAILURE);
		}
	}
	// add fired missiles to the line of defense using a list
	void createMissile(Vector2f shipPos)
	{
		Missile missile(missileTexture);
		missile.setPosition(shipPos);
		missileLine.push_back(missile);
	}
	// draw the missile line in the window
	void draw(RenderWindow &w)
	{
		list<Missile>::iterator iter;
		for (iter = missileLine.begin(); iter != missileLine.end(); iter++)
		{
			iter->draw(w);
		}
	}
	// moves the missiles up the screen
	void moveLine(float x, float y)
	{
		list<Missile>::iterator iter;
		for (iter = missileLine.begin(); iter != missileLine.end(); iter++)
		{
			iter->move(x, y);
		}
	}
	// erases missiles from the list when they go off the top of the screen
	void missFire()
	{
		list<Missile>::iterator iter;
		for (iter = missileLine.begin(); iter != missileLine.end();)
		{
			bool offScreen = false;
			Vector2f pos = iter->getPosition();
			if (pos.y < 0)
			{
				offScreen = true;
				iter = missileLine.erase(iter);
			}
			if (!offScreen)
			{
				iter++;
			}
		}
	}
	// detects if/when a missile hits one of the aliens
	void isAlienHit(AlienArmy &aliens, UI &menu)
	{
		int index;
		list<Missile>::iterator iter;

		// goes through and checks each missile in the list for a hit
		for (iter = missileLine.begin(); iter != missileLine.end(); ) 
		{
			bool hit = false;
			// gets the size of the alien list to go through each alien 
			for (int k = 0; k < aliens.getSize() && !hit; k++) 
			{
				// checks if the missile location intersects with the alien location
				if ((iter)->getSprite().getGlobalBounds().intersects(aliens.getSprite(k).getGlobalBounds())) 
				{
					iter = missileLine.erase(iter);
					hit = true;
					menu.calcScore();
					if (aliens.getSize() > 1)	// deletes all aliens except for the last one in the list
					{	
						aliens.killAlien(k);
					}
					else	// makes sure there is never an empty list when trying to delete all the aliens
					{
						aliens.createAliens();
						aliens.killAlien(k);
					}
				}
			}
			if (!hit)	// if it hit nothing, check the next missile
			{
				iter++;
			}
		}
	}


};