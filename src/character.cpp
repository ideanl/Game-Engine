#include "../include/character.h"

// constructer
Character::Character() {

}

// creates the character in memory, sets all its attributes
void Character::create(sf::RenderWindow& window, std::string s_textureFile, int s_xPos, int s_yPs, int s_xVelocity, int s_yVelocity) {
	// setting all the member variables
	windowPointer = &window;
	textureFile = s_textureFile;
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	x_Velocity = s_xVelocity;
	y_Velocity = s_yVelocity;

	// creating the image
	image.create(windowPointer, textureFile, x_Pos, s_Pos, x_Velocity, y_Velocity);
}

// checks for events
void Character::checkEvent() {

}

// updates the character
void Character::update() {

}

// draws the character
void Character::render() {
	image.draw();
}

// destructer
Character::~Character() {

}
