#include "../include/animationsprite.h"
#include <iostream>

AnimationSprite::AnimationSprite() {
  spritePointer = &sprite;
  spriteAddress = &sprite;
}

void AnimationSprite::create(sf::RenderWindow* window, int s_xPos, int s_yPos, int s_xVelocity, int s_yVelocity, int s_width, int s_height, sf::Vector3f s_color, std::string s_textureFile, std::string s_fontFile, std::string s_message, SpriteConfig* config) {
  windowPointer = window;
  x_Pos = s_xPos;
  y_Pos = s_yPos;
  x_Velocity = s_xVelocity;
  y_Velocity = s_yVelocity;
  textureFile = s_textureFile;

  animationSpeed = static_cast<AnimationConfig*>(config)->getAnimationSpeed();
  total_frames = static_cast<AnimationConfig*>(config)->getTotalFrames();
  columns = static_cast<AnimationConfig*>(config)->getColumns();
  rows = static_cast<AnimationConfig*>(config)->getRows();
  frame_width = static_cast<AnimationConfig*>(config)->getFrameWidth();
  frame_height = static_cast<AnimationConfig*>(config)->getFrameHeight();
  always_moving = static_cast<AnimationConfig*>(config)->getAlwaysMoving();
  default_index = static_cast<AnimationConfig*>(config)->getDefaultIndex();
  index = default_index;

  if (!texture.loadFromFile("./res/" + textureFile)) {
    std::cerr << "Failed to load" << textureFile << std::endl;
  } else {
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(createRect());
    sprite.setPosition(x_Pos, y_Pos);
  }

  setBoundaries<sf::Sprite>(sprite);
}

void AnimationSprite::update() {
  if (!always_moving && !curr_moving) {
    index = default_index;
  } else {
    index += animationSpeed;
    if (index > total_frames) index = 0;
  }

  sprite.setTextureRect(createRect());
}

sf::IntRect AnimationSprite::createRect() {
  int row = floor(floor(index) / columns);
  int column = static_cast<int>(floor(index)) % columns;
  int sx = column * frame_width;
  int sy = row * frame_height;
  return sf::IntRect(sx, sy, frame_width, frame_height);
}

void AnimationSprite::move(int s_xPos, int s_yPos) {
	x_Pos = s_xPos;
	y_Pos = s_yPos;
	sprite.move(x_Pos, y_Pos);
}

// checks for events
void AnimationSprite::checkEvent() {

}

// draws the sprite
void AnimationSprite::render() {
  windowPointer->draw(sprite);
}
