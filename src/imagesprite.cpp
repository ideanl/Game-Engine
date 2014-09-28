#include "../include/imagesprite.h"

ImageSprite::ImageSprite() {

}

void ImageSprite::create(sf::RenderWindow& window, std::string s_textureFile, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity) {
  setWindowPointer(window);
  setX_Pos(s_xPos);
  setY_Pos(s_yPos);
  setX_Velocity(s_xVelocity);
  setY_Velocity(s_yVelocity);
  textureFile = s_textureFile;
  if(!texture.loadFromFile("./res/" + textureFile))
    std::cerr << "Failed to load" << textureFile << std::endl;
  else 
    sprite.setTexture(texture);
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
