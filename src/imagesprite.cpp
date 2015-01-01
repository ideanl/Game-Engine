#include "../include/imagesprite.h"
#include <iostream>

// constructer
ImageSprite::ImageSprite() {
	spritePointer = &sprite;
	spriteAddress = &sprite;
	transformables.push_back(spritePointer);
}

// creates the sprite in memory, sets the attributes
void ImageSprite::create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message, SpriteConfig* config) { 
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
  scale = 1.0;
  // check to make sure the texture loads
  if(!texture.loadFromFile("./res/" + textureFile)) {
    std::cerr << "Failed to load: " << textureFile << std::endl;
  }
  else {
    // if too big
    if(texture.getSize().x > s_width || texture.getSize().y > s_height) {
      scale = static_cast<float>(s_width) / texture.getSize().x;
      if(scale < static_cast<float>(s_height) / texture.getSize().y) {
        scale = static_cast<float>(s_height) / texture.getSize().y;
      }
    }
    // if too small
    else if(texture.getSize().x < s_width || texture.getSize().y < s_height) {
      scale = static_cast<float>(texture.getSize().x) / s_width;
      if(scale > static_cast<float>(texture.getSize().y) / s_height) {
        scale = static_cast<float>(texture.getSize().y) / s_height;
      }
    }
  	// smooths out the texture so it is less sharp
    texture.setSmooth(true);
	  sprite.setTexture(texture);
    sprite.setScale(scale, scale);
    sprite.setOrigin(sprite.getTexture()->getSize().x * scale * .50, sprite.getTexture()->getSize().y * scale * .50);
    sf::IntRect textureRect(s_xPos, s_yPos, s_width, s_height);
    sprite.setTextureRect(textureRect);
    // sets color of the sprite
    // to keep default color just enter values over 255
    if(color.r <= 255 && color.g <= 255 && color.b <= 255) {
      sprite.setColor(color);
    }
	  // finds the width and height of the global bounding rectangle of the sprite
	  setBoundaries<sf::Sprite>(sprite);
  }
}

// sets the sprite position
void ImageSprite::setPosition(int s_xPos, int s_yPos) {
  sprite.setPosition(s_xPos, s_yPos);
  x_Pos = s_xPos;
  y_Pos = s_yPos;
}

// moves the sprite along the vertical axis
void ImageSprite::move_x(int s_xPos) {
  while(x_Pos < s_xPos) {
    sprite.move(x_Velocity, 0);
    x_Pos += x_Velocity;
  }
}
void ImageSprite::move_x(bool isMoving) {
  while(isMoving) {
    sprite.move(x_Velocity, 0);
    x_Pos += x_Velocity;
  }
}

// moves the sprite along the vertical axis
void ImageSprite::move_y(int s_yPos) {
  while(y_Pos < s_yPos) {
    sprite.move(0, y_Velocity);
    y_Pos += y_Velocity;
  }
}
void ImageSprite::move_y(bool isMoving) {
  while(isMoving) {
    sprite.move(0, y_Velocity);
    y_Pos += y_Velocity;
  }
}

// flips the sprite
void ImageSprite::flip(bool isFlipped) {
  if(isFlipped == true) {
    sprite.setScale(-scale, scale);
  }
  else
    sprite.setScale(scale, scale);
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
