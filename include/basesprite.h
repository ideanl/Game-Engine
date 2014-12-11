#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../include/spriteconfig.h"

// The Base class for all other sprites
class BaseSprite {
  public:
  	// construter
    BaseSprite();
	// creates the button in memory, stores all its attributes
  virtual void create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message, SpriteConfig* config = 0) = 0;
	// checks for events
	virtual void checkEvent() = 0;
	// updates the sprite position and such
  virtual void update() = 0;
	// draws the sprite
  virtual void render() = 0;
  // sets position of the sprite
  virtual void setPosition(int s_xPos, int s_yPos) = 0;
	// moves the sprite along the horizontal axis
	virtual void move_x(int s_xPos) = 0;
  virtual void move_x(bool isMoving) = 0;
  // moves the sprite along the vertical axis
  virtual void move_y(int s_yPos) = 0;
  virtual void move_y(bool isMoving) = 0;
	// reutns the gobal bouding rectangle width
	int getWidth();
	// returns the gobal bouding rectange height
	int getHeight();
  // returns x velocity of sprite
  int getX_Velocity();
  // returns the y velocity of sprite
  int getY_Velocity();
	// returns the drawables
	std::vector<sf::Transformable*> getTransformables();
	// gets and sets the rectangle surrounding the sprite
	template <class Type> void setBoundaries(Type& object) {
		sf::FloatRect boundaries = object.getGlobalBounds();
		width = boundaries.width;
		height = boundaries.height;
	}
  // moves the sprite
  template <class s_type> void move(int s_xPos, int s_yPos, s_type object) {
    sf::Vector2f movedDistance(0.0, 0.0);
    while(movedDistance.x < s_xPos) {
      for(int i = 0; i < object->getTransformables().size(); i++) { 
	      object->getTransformables()[i]->move(object->getX_Velocity(), 0);
	    }
      movedDistance.x += object->getX_Velocity();
    }
    while(movedDistance.y < s_yPos) {
      for(int i = 0; i < object->getTransformables().size(); i++) {
        object->getTransformables()[i]->move(0, object->getY_Velocity());
      }
      movedDistance.y += object->getY_Velocity();
    }
  }
  template <class s_type> void setPosition(int s_xPos, int s_yPos, s_type object) {
    for(int i = 0; i < object->getTransformables().size(); i++) {
      object->getTransformables()[i]->setPosition(s_xPos, s_yPos);
    }
  }
	// destructer
    ~BaseSprite();
  protected:
    int x_Velocity, y_Velocity, x_Pos, y_Pos, width, height;
    std::string textureFile, fontFile, message;
    sf::RenderWindow* windowPointer;
    sf::Color color;
	  sf::FloatRect boundaries;
	  std::vector<sf::Transformable*> transformables;
  private:
};

#endif
