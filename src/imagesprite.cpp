#include "../include/imagesprite.h"
#include <iostream>

// constructer
ImageSprite::ImageSprite() {
	spritePointer = &sprite;
	transformables.push_back(spritePointer);
}

// creates the sprite in memory, sets the attributes
void ImageSprite::create(sf::RenderWindow* window, std::string s_textureFile, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity) {
  
  // setting all the member variables
  windowPointer = window;
  x_Pos = s_xPos;
  y_Pos = s_yPos;
  x_Velocity = s_xVelocity;
  y_Velocity = s_yVelocity;
  textureFile = s_textureFile;

  // check to make sure the texture loads
  if(!texture.loadFromFile("./res/" + textureFile))
    std::cerr << "Failed to load" << textureFile << std::endl;
  else { 
  	// smooths out the texture so it is less sharp
    texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setPosition(x_Pos, y_Pos);
	}
	// finds the width and height of the global bounding rectangle of the sprite
	setBoundaries<sf::Sprite>(sprite);
}

// moves the sprite
void ImageSprite::move(int s_xPos, int s_yPos) {
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	sprite.move(x_Pos, y_Pos);
}

// checks for events
void ImageSprite::checkEvent() {

}

// updates the sprite
void ImageSprite::update() {

}

// draws the sprite
void ImageSprite::render() {
  windowPointer->draw(sprite);
}

// destructer
ImageSprite::~ImageSprite() {

}
