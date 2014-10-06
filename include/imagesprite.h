#ifndef IMAGESPRITE_H
#define IMAGESPRITE_H

#include "basesprite.h"
#include <SFML/Graphics.hpp>
#include <iostream>

// class for image sprites, sprite with images
class ImageSprite :public BaseSprite {
  public:
  	// constructer
    ImageSprite();
	// creates the sprite in memory, sets all its atttributes
    void create(sf::RenderWindow* window, std::string s_textureFile, int s_xPos,int s_yPos, int s_xVelocity, int s_yVelocity);
    // moves the sprite
	void move(int s_xPos, int s_yPos);
	// checks for events
	void checkEvent();
	// updates the sprite
    void update();
	// draws the sprite
    void render();
	// destructer
    ~ImageSprite();
  protected:
  	sf::Texture texture;
	sf::Sprite sprite;
	std::string textureFile;
  private:
};

#endif

