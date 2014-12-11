#include "../include/button.h"

// constructer
Button::Button() {
	textSpritePointer = text.getTextAddress();
	imageSpritePointer = image.getSpriteAddress();
	transformables.push_back(textSpritePointer);
	transformables.push_back(imageSpritePointer);
}

// creates the button in memory, sets the attributes
void Button::create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message, SpriteConfig* config) {	
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
  fontFile = s_fontFile;
	message = s_message;
	
	// creating the button image
	image.create(windowPointer, s_xPos, s_yPos, s_xVelocity, s_yVelocity, s_width, s_height, s_color, s_textureFile, s_fontFile, s_message);
	// creates the button text
	text.create(windowPointer, s_xPos, s_yPos, s_xVelocity, s_yVelocity, s_width, s_height, s_color, s_textureFile, s_fontFile, s_message);
}

// checks for events
void Button::checkEvent() {
	// if(isClicked() {
	// do this 
	// }
}

// tells if button was clicked
bool Button::isClicked() {

}

// sets the button position
void Button::setPosition(int s_xPos, int s_yPos) {
  image.setPosition(s_xPos, s_yPos);
  text.setPosition(s_xPos, s_yPos);
}

// moves the button along the horizontal axis
void Button::move_x(int s_xPos) {
  while(x_Pos < s_xPos) {
    image.move_x(s_xPos);
    text.move_x(s_xPos);
    x_Pos = s_xPos;
  }
}
void Button::move_x(bool isMoving) {
  while(isMoving) {
    image.move_x(isMoving);
    text.move_x(isMoving);
    x_Pos += x_Velocity;
  }
}

// moves the sprite along the vertical axis
void Button::move_y(int s_yPos) {
  while(y_Pos < s_yPos) {
    image.move_y(s_yPos);
    text.move_y(s_yPos);
    y_Pos = s_yPos;
  }
}
void Button::move_y(bool isMoving) {
  while(isMoving) {
    image.move_y(isMoving);
    text.move_y(isMoving);
    y_Pos += y_Velocity;
  }
}

// updates the button
void Button::update() {

}

// draws the button
void Button::render() {
	image.render();
	text.render();
}

// destructer
Button::~Button() {

}
