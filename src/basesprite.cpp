#include "../include/basesprite.h"

// constructer
BaseSprite::BaseSprite() {

}

// returns width of global bounding rectangle
int BaseSprite::getWidth() {
	return width;
} 

// returns the drawables
std::vector<sf::Transformable*> BaseSprite::getTransformables() {
	return transformables;
}
// returns the height of global bounding rectangle
int BaseSprite::getHeight() {
	return height;
}

// returns the x velocity 
int BaseSprite::getX_Velocity() {
  return x_Velocity;
}

// returns the y velocity
int BaseSprite::getY_Velocity() {
  return y_Velocity;
}

// destructer
BaseSprite::~BaseSprite() {

}
