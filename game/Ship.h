//============================================================
// Natalie Killian
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
// File: Ship.h
//		defines and handles the ship in the game
//============================================================
#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Ship
{
private:
	Sprite ship;
	bool isHit;
public:
	Ship(RenderWindow &w, Texture &shipTexture);
	void setHit(bool hit);
	bool getHit();
	void setPosition(Vector2f loc);
	Vector2f getPosition();
	Sprite getSprite();
	void draw(RenderWindow &w);
	void moveShip(const int WINDOW_WIDTH, Texture shipTexture);
	FloatRect getGlobalBounds();
};