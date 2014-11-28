#include "../include/character.h"

// constructer
Character::Character() {

}

// creates the character in memory, sets all its attributes
	void Character::create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message) {
  // setting all the member variables
	windowPointer = window;
  x_Pos = s_xPos;
  y_Pos = s_yPos;
  x_Velocity = s_xVelocity;
  y_Velocity = s_yVelocity;
  width = s_width;
  height = s_height;
  color.r = s_color.x;
  color.g = s_color.y;
  color.b = s_color.z;
  textureFile = s_textureFile;

	// creating the image
	image.create(windowPointer, s_xPos, s_yPos, s_xVelocity, s_yVelocity, s_width, s_height, s_color, s_textureFile, s_fontFile, s_message);
}

// checks for events
void Character::checkEvent() {

}

// updates the character
void Character::update() {

}

// draws the character
void Character::render() {
	image.render();
}

// deconstructer
Character::~Character() {

}
