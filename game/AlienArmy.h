//============================================================
// Natalie Killian
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
// File: AlienArmy.h
//		defines and handles all the aliens; 
//		an AlienArmy has a list of Aliens
//============================================================

#pragma once
#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Alien.h";
#include <list>;

class AlienArmy 
{
private:
	list<Alien> alienArmy;
	Texture alienTexture;
public:
	// constructor
	AlienArmy() 
	{
		// load the alien texture
		if (!alienTexture.loadFromFile("alien.png"))
		{
			cout << "Unable to load alien texture!" << endl;
			exit(EXIT_FAILURE);
		}
	}
	// adds 10 aliens to the army using a list
	void createAliens()
	{
		list<Alien>::iterator iter;
		for (iter = alienArmy.begin(); iter != alienArmy.end();)
		{
			iter = alienArmy.erase(iter);
		}
		// initial position of the enemy
		Vector2f alienPos; 
		int x = 80; 
		int y = 10;
		alienPos.y = y;

		for (int i = 0; i < 10; i++)
		{
			alienPos.x = (x * i) + 15;
			Alien alien(alienTexture);
			alien.setPosition(alienPos);
			alienArmy.push_back(alien);
		}
	}
	// getter function for the alien's sprite
	Sprite getSprite(int i)
	{
		list<Alien>::iterator iter = alienArmy.begin();
		advance(iter, i);
		return iter->getSprite();
	}
	// draw the alien army in the window
	void draw(RenderWindow &w)
	{
		list<Alien>::iterator iter;
		for (iter = alienArmy.begin(); iter != alienArmy.end(); iter++)
		{
			iter->draw(w);
		}
	}
	// moves the aliens down the screen
	void moveArmy(const int WINDOW_HEIGHT)
	{
		list<Alien>::iterator iter;
		for (iter = alienArmy.begin(); iter != alienArmy.end(); iter++)
		{
			iter->moveAlien(WINDOW_HEIGHT);
		}
	}
	// getter function for the size of the alien army (list)
	int getSize()
	{
		return alienArmy.size();
	}
	// deletes the aliens in the list 
	void killAlien(int i)
	{
		list<Alien>::iterator iter = alienArmy.begin();
		advance(iter, i);
		iter = alienArmy.erase(iter);
	}
};