//============================================================
// Natalie Killian
// April 19th, 2019
// Programming Assignment #7
// Description: Space Invaders
// File: UI.h
//		handles user interaction and showing stats
//============================================================

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

// function prototypes
void die(string msg);

class UI
{
private:
	int lives;
	int score;
	RectangleShape startBtn;
public:
	// constructor that defines the start button
	UI()
	{
		score = 0;
		lives = 3;

		Vector2f pos1(250, 300);
		startBtn.setPosition(pos1);
		startBtn.setSize(Vector2f(300, 150));
		startBtn.setOutlineThickness(5);
		startBtn.setOutlineColor(Color::Green);
		startBtn.setFillColor(Color::Transparent);
	}
	// function that checks if the start button has been pressed to begin the game
	bool handleMouseUp(Vector2f mouse)
	{
		bool clicked = false;
		// check if mouse is currently over blueBtn
		if (startBtn.getGlobalBounds().contains(mouse))
		{
			clicked = true;
		}
		return clicked;
	}
	// increments the player's score every time an alien is hit
	void calcScore()
	{
		score++;
	}
	// decrement the player's lives every time a bomb hits them
	void loseLife()
	{
		lives--;
	}
	// draws the button and the beginning stats onto the window
	void draw(RenderWindow &w, int i)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		w.draw(startBtn);

		Text title("Click to Play!", font, 45);
		title.setFillColor(Color::Magenta);
		title.setPosition(startBtn.getPosition().x + (startBtn.getSize().x - title.getLocalBounds().width) / 2,				
			startBtn.getPosition().y + (startBtn.getSize().y) / 2 - title.getLocalBounds().height);
		w.draw(title);

		if (i == 1)
		{
			Text title1("SPACE INVADERS!", font, 75);
			title1.setFillColor(Color::Cyan);
			title1.setPosition(70, 100);
			w.draw(title1);

		}
		else if (i == 2)
		{
			Text title1("You are a WINNER!", font, 75);
			title1.setFillColor(Color::Cyan);
			title1.setPosition(70, 100);
			w.draw(title1);
		}
		else if (i == 3)
		{
			Text title1("You are a LOSER!", font, 75);
			title1.setFillColor(Color::Cyan);
			title1.setPosition(70, 100);
			w.draw(title1);
		}
	}
	// draws the player's stats on the game window
	void showStats(RenderWindow& win) 
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		// Color Title
		Text title("Score: ", font, 50);
		title.setFillColor(Color::Green);
		title.setPosition(0, 0);
		win.draw(title);

		Text title1(to_string(score), font, 50);
		title1.setFillColor(Color::Green);
		title1.setPosition(title.getLocalBounds().width, 0);
		win.draw(title1);

		Text title2("Lives: ", font, 50);
		title2.setFillColor(Color::Green);
		title2.setPosition(600, 0);
		win.draw(title2);

		Text title3(to_string(lives), font, 50);
		title3.setFillColor(Color::Green);
		title3.setPosition(600 + title2.getLocalBounds().width, 0);
		win.draw(title3);

	}
	// setter function to set the score back and restart the level
	void setScore(int redo)
	{
		score = redo;

	}
	// setter function to set the lives back and restart the level
	void setLives(int redo)
	{
		lives = redo;
	}
	// getter function for lives
	int getLives()
	{
		return lives;
	}
	// getter function that returns the score
	int getScore()
	{
		return score;
	}
};


// Function that ends program if there is an error
void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}