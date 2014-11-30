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
    void create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message, SpriteConfig* config = 0);  
    // moves the sprite
	  void move(int s_xPos, int s_yPos);
	  // checks for events
	  void checkEvent();
	  // updates the sprite
    void update();
	  // draws the sprite
    void render();
	  // returns the sprite
	  sf::Sprite* getSpriteAddress();
	  // destructer
    ~ImageSprite();
  protected:
  	sf::Texture texture;
	  sf::Sprite sprite;
	  sf::Transformable* spritePointer;
  private:
  	sf::Sprite* spriteAddress;
};

#endif

