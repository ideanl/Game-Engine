#include "../include/imagesprite.h"
#include <iostream>

// constructer
ImageSprite::ImageSprite() {
	spritePointer = &sprite;
	spriteAddress = &sprite;
	transformables.push_back(spritePointer);
}

// creates the sprite in memory, sets the attributes
void ImageSprite::create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message) { 
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

  // check to make sure the texture loads
  if(!texture.loadFromFile("./res/" + textureFile)) {
    std::cerr << "Failed to load: " << textureFile << std::endl;
  }
  else { 
  	// smooths out the texture so it is less sharp
    texture.setSmooth(true);
	  sprite.setTexture(texture);
    sf::IntRect textureRect(s_xPos, s_yPos, s_width, s_height);
    sprite.setTextureRect(textureRect);
    // sets color of the sprite
    sprite.setColor(color);
	  // finds the width and height of the global bounding rectangle of the sprite
	  setBoundaries<sf::Sprite>(sprite);
  }
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

// returns the sprite
sf::Sprite* ImageSprite::getSpriteAddress() {
	return spriteAddress;
}

// destructer
ImageSprite::~ImageSprite() {

}
