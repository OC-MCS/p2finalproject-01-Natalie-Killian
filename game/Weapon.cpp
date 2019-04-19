#include "Weapon.h"
#include <cstdlib>

using namespace std;
using namespace sf;


//======================================
// Weapon Class Functions - Base Class
//======================================

// constructor
Weapon::Weapon(Texture &texture)
{
	weapon.setTexture(texture);
}
// move() moves the weapon across the screen; changes location every 
// frame to appear as if it is moving
void Weapon::move(float x, float y)
{
	weapon.move(x, y);
}
// getter function for weapon position
Vector2f Weapon::getPosition()
{
	return weapon.getPosition();
}
// sets the weapon position using two floats
void Weapon::setPosition(float x, float y)
{
	weapon.setPosition(x, y);
}
// overloaded function that sets the weapon position with a Vector2f
void Weapon::setPosition(Vector2f pos)
{
	weapon.setPosition(pos);
}
// getter function that returns weapon's global bounds
FloatRect Weapon::getGlobalBounds()
{
	return weapon.getGlobalBounds();
}
// getter function that returns the weapon's Sprite
Sprite Weapon::getSprite()
{
	return weapon;
}
// draws an instance of a weapon in the window
void Weapon::draw(RenderWindow &window)
{
	window.draw(weapon);
}


//==========================================
// Missile Class Functions - Derived Class
//==========================================

// constructor
Missile::Missile(Texture &missileTexture) : Weapon(missileTexture) {}


//==========================================
// Bomb Class Functions - Derived Class
//==========================================

// constructor
Bomb::Bomb(Texture &bombTexture) : Weapon(bombTexture) 
{
	getSprite().setScale(0.5, 0.5);
}
