#ifndef ANIMATIONSPRITE_H
#define ANIMATIONSPRITE_H

#include <SFML/Graphics.hpp>
#include "basesprite.h"

class AnimationSprite :public BaseSprite {
  public:
    // constructer
    AnimationSprite();
    void create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message);  
    // creates the sprite in memory, sets all its atttributes
    void createAnim(sf::RenderWindow* window, std::string s_textureFile, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, float s_animationSpeed, int s_total_frames, int s_columns, int s_rows, int s_frame_width, int s_frame_height, bool s_always_moving = false, float s_default_index = 0);
    // moves the sprite
    void move(int s_xPos, int s_yPos);
    // checks for events
    void checkEvent();
    // updates the sprite
    void update();
    // draws the sprite
    void render();
    bool curr_moving = false;

  protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string textureFile;
    sf::Transformable* spritePointer;
  private:
    sf::Sprite* spriteAddress;
    float animationSpeed;
    int columns;
    int rows;
    int frame_width;
    int frame_height;
    int total_frames;
    bool always_moving;
    float index;
    float default_index;
    sf::IntRect createRect();
};

#endif
