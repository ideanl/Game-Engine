#include "../include/imagesprite.h"
#include <iostream>

ImageSprite::ImageSprite() {

}

void ImageSprite::create(sf::RenderWindow& window, std::string s_textureFile, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity) {
  windowPointer = &window;
  x_Pos = s_xPos;
  y_Pos = s_yPos;
  x_Velocity = s_xVelocity;
  y_Velocity = s_yVelocity;
  textureFile = s_textureFile;
  if(!texture.loadFromFile("./res/" + textureFile))
    std::cerr << "Failed to load" << textureFile << std::endl;
  else { 
    texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setPosition(x_Pos, y_Pos);
	}
 setBoundaries<sf::Sprite>(sprite);
}

void ImageSprite::checkEvent() {

}

void ImageSprite::update() {
}

void ImageSprite::render() {
  windowPointer->draw(sprite);
}

ImageSprite::~ImageSprite() {

}
