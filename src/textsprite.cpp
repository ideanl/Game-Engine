#include "../include/textsprite.h"

// constructer
TextSprite::TextSprite() {
  textPointer = &text;
  textAddress = &text;
  transformables.push_back(textPointer);
}

// creates the sprite in memory, sets the attributes
void TextSprite::create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message, SpriteConfig* config) {

	// settting all the memeber variables
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
  fontFile = s_fontFile;
  message = s_message;
  charSize = width / message.length();
	// checks to make sure the font loads
	if(!font.loadFromFile("./res/" + fontFile))
		std::cerr << "Font " << fontFile << " failed to load" << std::endl;
	else {
		// creates the sprite
    text.setPosition(x_Pos, y_Pos);
		text.setFont(font);
		text.setString(message);
    text.setColor(color);
		text.setCharacterSize(charSize);
    // gets the width and height of the global bounding rectangle
    setBoundaries<sf::Text>(text);
    text.setOrigin(width * .50, height * .50);
	}
}

// sets the sprite position
void TextSprite::setPosition(int s_xPos, int s_yPos) {
  text.setPosition(s_xPos, s_yPos);
  x_Pos = s_xPos;
  y_Pos = s_yPos;
}

// moves the sprite along the horizontal axis
void TextSprite::move_x(int s_xPos) {
  while(x_Pos < s_xPos) {
	  text.move(x_Velocity, 0);
    x_Pos += x_Velocity;
  }
}
void TextSprite::move_x(bool isMoving) {
  while(isMoving) {
    text.move(x_Velocity, 0);
    x_Pos += x_Velocity;
  }
}

// moves the sprite along the vertical axis
void TextSprite::move_y(int s_yPos) {
  while(y_Pos < s_yPos) {
    text.move(0, y_Velocity);
    y_Pos += y_Velocity;
  }
}
void TextSprite::move_y(bool isMoving) {
  while(isMoving) {
    text.move(0, y_Velocity);
    y_Pos += y_Velocity;
  }
}

// checks for events
void TextSprite::checkEvent() {

}

// updates the sprite
void TextSprite::update() {

}

// draws the sprite
void TextSprite::render() {
	windowPointer->draw(text);
}

// returns the sprite
sf::Text* TextSprite::getTextAddress() {
	return textAddress;
}

// destructer
TextSprite::~TextSprite() {

}
