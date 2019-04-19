//============================================================
// Natalie Killian
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
// File: Alien.cpp
//		implementation file for an alien
//============================================================

#include "Alien.h";

using namespace std;
using namespace sf;

// constructor for a ship
Alien::Alien(Texture &alienTexture)
{
	alien.setTexture(alienTexture);
	isHit = false;
}

// setter function for hit
void Alien::setHit(bool hit)
{
	isHit = hit;
}

// getter function for hit
bool Alien::getHit()
{
	return isHit;
}

// setter function for location
void Alien::setPosition(Vector2f loc)
{
	alien.setPosition(loc);
}

// getter function for location
Vector2f Alien::getPosition()
{
	return alien.getPosition();
}

// getter function for Sprite
Sprite Alien::getSprite()
{
	return alien;
}

// draws the alien in the window
void Alien::draw(RenderWindow &w)
{
	w.draw(alien);
}

void Alien::moveAlien(const int WINDOW_HEIGHT)
{
	const float MOVE = 0.5f;

	alien.move(0, MOVE);
}

// getter function that returns the alien's global bounds
FloatRect Alien::getGlobalBounds() 
{
	return alien.getGlobalBounds();
}