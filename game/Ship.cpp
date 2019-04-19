//============================================================
// Natalie Killian
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
// File: Ship.cpp
//		implementation file for the ship
//============================================================

#include "Ship.h";

using namespace std;
using namespace sf;

// constructor for a ship
Ship::Ship(RenderWindow &w, Texture &shipTexture)
{
	// initial position of the ship will be centered horizontally at bottom of screen
	float shipX = w.getSize().x / 2.0f;
	float shipY = w.getSize().y - 50;
	ship.setPosition(shipX, shipY);

	ship.setTexture(shipTexture);
	isHit = false;
}

// getter function for hit
bool Ship::getHit()
{
	return isHit;
}

// getter function for Sprite
Sprite Ship::getSprite()
{
	return ship;
}

// setter function for hit
void Ship::setHit(bool hit)
{
	isHit = hit;
}

// setter function for location
void Ship::setPosition(Vector2f loc)
{
	ship.setPosition(loc);
}

// getter function for location
Vector2f Ship::getPosition()
{
	return ship.getPosition();
}

// draws the ship in the window
void Ship::draw(RenderWindow &w)
{
	w.draw(ship);
}

// moves the ship if the arrow keys are pressed
void Ship::moveShip(const int WINDOW_WIDTH, Texture shipTexture)
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left) && ship.getPosition().x > 0)
	{
		// left arrow is pressed: move our ship left 5 pixels
		// 2nd parm is y direction. We don't want to move up/down, so it's zero.
		ship.move(-DISTANCE, 0);
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) && ship.getPosition().x < (WINDOW_WIDTH - shipTexture.getSize().x))
	{
		// right arrow is pressed: move our ship right 5 pixels
		ship.move(DISTANCE, 0);
	}
}

// getter function that returns the ship's global bounds
FloatRect Ship::getGlobalBounds()
{
	return ship.getGlobalBounds();
}