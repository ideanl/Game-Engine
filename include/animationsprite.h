#ifndef ANIMATIONSPRITE_H
#define ANIMATIONSPRITE_H

#include <SFML/Graphics.hpp>
#include "basesprite.h"

class AnimationSprite :public BaseSprite {
  public:
    // constructer
    AnimationSprite();
    // creates the sprite in memory, sets all its atttributes
    void create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message, SpriteConfig* config = 0);  
    // checks for events
    void checkEvent();
    // updates the sprite
    void update();
    // draws the sprite
    void render();
    // sets position of the sprite
    void setPosition(int s_xPos, int s_yPos);
    // moves the sprite alongthe horizontal axis
    void move_x(int s_xPos);
    void move_x(bool isMoving);
    // moves the sprite along the vertical axis
    void move_y(int s_yPos);
    void move_y(bool isMoving);
    // flips the sprite
    void flip(bool isFlipped);
    bool curr_moving = false;

    bool end();

  protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string textureFile;
    sf::Transformable* spritePointer;
  private:
    sf::Sprite* spriteAddress;
    float animationSpeed, scale;
    int columns;
    int rows;
    int frame_width;
    int frame_height;
    int total_frames;
    bool always_moving;
    bool pauses;
    float index;
    float default_index;
    bool isFlipped;
    sf::IntRect createRect();
};

#endif
