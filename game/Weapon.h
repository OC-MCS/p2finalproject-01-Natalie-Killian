//===================================================
// Natalie Killian
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
// File: Weapon.h
//		defines and handles the two types of 
//		weapons in the game
//===================================================
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
using namespace sf;

// Weapon is an abstract base class for Missile and Bomb
class Weapon
{
private:
	Sprite weapon;
public:
	Weapon(Texture &texture);
	void move(float x, float y);
	Vector2f getPosition();
	void draw(RenderWindow &window);
	void setPosition(float x, float y);
	void setPosition(Vector2f pos);
	FloatRect getGlobalBounds();
	Sprite getSprite();
};

// Missile class is derived from Weapon
class Missile : public Weapon
{
private:
public:
	// constructor
	Missile(Texture &missileTexture);
};

// Bomb class is derived from Weapon
class Bomb : public Weapon
{
private:
public:
	Bomb(Texture &bombTexture);
};