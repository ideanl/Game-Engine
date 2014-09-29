#ifndef IMAGESPRITE_H
#define IMAGESPRITE_H

#include "basesprite.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class ImageSprite :public BaseSprite {
  public:
    ImageSprite();
    void create(sf::RenderWindow& window, std::string s_textureFile, int s_xPos,int s_yPos, int s_xVelocity, int s_yVelocity);
    void checkEvent();
    void update();
    void render();
    ~ImageSprite();
  protected:
  private:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string textureFile;
};

#endif

