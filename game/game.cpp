//============================================================
// Natalie Killian
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
//============================================================

#include <iostream>
#include "Ship.h"
#include "Weapon.h"
#include "Alien.h"
#include "AlienArmy.h"
#include "MissileLine.h"
#include "BombDrop.h"
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 

// note: a Sprite represents an image on screen. A sprite knows and remembers its own position 
// x is horizontal, y is vertical. 
// 0,0 is in the UPPER LEFT of the screen, y increases DOWN the screen

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	enum gamestate {START, LEVEL1, LEVEL2START, LEVEL2, WINNER, LOSER};
	gamestate game = START;

	int timer = 0;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SPACE INVADERS!!!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	// Load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}
	
	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like
	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);
	
	UI menu;
	Ship ship(window, shipTexture);		// Create a ship
	MissileLine missiles;				// Set up a line of missiles
	BombDrop bombs;					// Set up a group of bombs
	AlienArmy aliens;                 
	aliens.createAliens();				// Create an alien Army
	
	
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else
			{
				if (event.type == Event::KeyPressed)
				{
					if (event.key.code == Keyboard::Space)
					{
						Vector2f pos = ship.getPosition();
						missiles.createMissile(pos);
					}
				}
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);
		
		if (game == START)
		{
			menu.draw(window, 1);
			if (event.type == Event::MouseButtonReleased)
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (menu.handleMouseUp(mousePos))
				{
					game = LEVEL1;
				}
			}
			
		}
		else if (game == LEVEL1)
		{
			ship.moveShip(WINDOW_WIDTH, shipTexture);
			aliens.moveArmy(WINDOW_HEIGHT);
			bombs.randomDrop(aliens, timer);

			// draw the user's stats in the window
			// shows the number of lives left and points scored
			menu.showStats(window);

			// draw the ship on top of background 
			// (the ship from previous frame was erased when we drew background)
			ship.draw(window);
			// draw an alien
			aliens.draw(window);

			// draw missiles
			missiles.draw(window);
			missiles.moveLine(0, -10);
			missiles.missFire();
			missiles.isAlienHit(aliens, menu);

			// draw bombs
			bombs.draw(window);
			bombs.moveDrop(0, 3);
			bombs.missDrop();
			if (bombs.isShipHit(ship, menu))
			{
				aliens.createAliens();
				menu.setScore(0);
			}
			if (menu.getLives() < 1)
			{
				game = LOSER;
				cout << menu.getLives();
			}
			else if (menu.getScore() == 10) 
			{
				game = LEVEL2;
			}
			
		}
		else if (game == LEVEL2)
		{
			ship.moveShip(WINDOW_WIDTH, shipTexture);
			aliens.moveArmy(WINDOW_HEIGHT);
			bombs.randomDrop(aliens, timer);

			// draw the user's stats in the window
			// shows the number of lives left and points scored
			menu.showStats(window);

			// draw the ship on top of background 
			// (the ship from previous frame was erased when we drew background)
			ship.draw(window);
			// draw an alien
			aliens.draw(window);

			// draw missiles
			missiles.draw(window);
			missiles.moveLine(0, -10);
			missiles.missFire();
			missiles.isAlienHit(aliens, menu);

			// draw bombs
			bombs.draw(window);
			bombs.moveDrop(0, 7);
			bombs.missDrop();
			if (bombs.isShipHit(ship, menu))
			{
				aliens.createAliens();
				menu.setScore(0);
			}
			if (menu.getLives() <= 0)
			{
				game = LOSER;
			}
			else if (menu.getScore() == 20)
			{
				game = WINNER;
			}
		}
		else if (game == WINNER)
		{
			menu.draw(window, 2);
			if (event.type == Event::MouseButtonReleased)
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (menu.handleMouseUp(mousePos))
				{
					menu.setScore(0);
					menu.setLives(3);
					game = LEVEL1;
				}
			}
		}
		else if (game == LOSER)
		{
			menu.draw(window, 3);
			if (event.type == Event::MouseButtonReleased)
			{
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
				if (menu.handleMouseUp(mousePos))
				{
					menu.setScore(0);
					menu.setLives(3);
					game = LEVEL1;
				}
			}
		}
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

