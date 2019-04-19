//============================================================
// Natalie Killian
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
// File: Alien.h
//		defines and handles an alien in the game
//============================================================

#pragma once

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;

class Alien
{
private:
	Sprite alien;
	bool isHit;
public:
	Alien(Texture &alienTexture);
	void setHit(bool hit);
	bool getHit();
	void setPosition(Vector2f loc);
	Vector2f getPosition();
	Sprite getSprite();
	void draw(RenderWindow &w);
	void moveAlien(const int WINDOW_HEIGHT);
	FloatRect getGlobalBounds();
};
