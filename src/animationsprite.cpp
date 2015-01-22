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
  color.r = s_color.x;
  color.g = s_color.y;
  color.b = s_color.z;
  x_Velocity = s_xVelocity;
  y_Velocity = s_yVelocity;
  textureFile = s_textureFile;
  scale = 1.0;
  animationSpeed = static_cast<AnimationConfig*>(config)->getAnimationSpeed();
  total_frames = static_cast<AnimationConfig*>(config)->getTotalFrames();
  columns = static_cast<AnimationConfig*>(config)->getColumns();
  rows = static_cast<AnimationConfig*>(config)->getRows();
  always_moving = static_cast<AnimationConfig*>(config)->getAlwaysMoving();
  pauses = static_cast<AnimationConfig*>(config)->getPauses();
  default_index = static_cast<AnimationConfig*>(config)->getDefaultIndex();
  frame_width = s_width;
  frame_height = s_height;
  index = default_index;

  delete config;
  if (!texture.loadFromFile("./res/" + textureFile)) {
    std::cerr << "Failed to load" << textureFile << std::endl;
  } else {
      // if too big
      if(texture.getSize().x > s_width*columns || texture.getSize().y > s_height*rows) {
        scale = static_cast<float>(s_width) * columns / texture.getSize().x;
        if(scale < static_cast<float>(s_height) * rows / texture.getSize().y) {
          scale = static_cast<float>(s_height) * rows / texture.getSize().y;
        }
      }  
      // if too small
      else if(texture.getSize().x < s_width*columns || texture.getSize().y < s_height*rows) {
        scale = static_cast<float>(texture.getSize().x) * columns / s_width;
        if(scale > static_cast<float>(texture.getSize().y) * rows / s_height) {
          scale = static_cast<float>(texture.getSize().y) * rows / s_height;
        }
      }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setScale(scale, scale);
    sprite.setOrigin(sprite.getTexture()->getSize().x * scale * .50, sprite.getTexture()->getSize().y * scale * .50);
    sprite.setTextureRect(createRect());
    sprite.setPosition(x_Pos, y_Pos);
    // sets color of the sprite
    // to keep default color just enter values over 255
    if(color.r <= 255 && color.g <= 255 && color.b <= 255) {
      sprite.setColor(color);
    }
  }

  setBoundaries<sf::Sprite>(sprite);
}

void AnimationSprite::update() {
  if (!always_moving && !curr_moving) {
    if (!pauses)
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
  return sf::IntRect(sx, sy, frame_width * scale, frame_height * scale);
}

// moves the sprite along the vertical axis
void AnimationSprite::move_x(int s_xPos) {
  while(x_Pos < s_xPos) {
    sprite.move(x_Velocity, 0);
    x_Pos += x_Velocity;
  }
}
void AnimationSprite::move_x(bool isMoving) {
  while(isMoving) {
    sprite.move(x_Velocity, 0);
    x_Pos += x_Velocity;
  }
}

// moves the sprite along the vertical axis
void AnimationSprite::move_y(int s_yPos) {
  while(y_Pos < s_yPos) {
    sprite.move(0, y_Velocity);
    y_Pos += y_Velocity;
  }
}
void AnimationSprite::move_y(bool isMoving) {
  while(isMoving) {
    sprite.move(0, y_Velocity);
    y_Pos += y_Velocity;
  }
}

// checks for events
void AnimationSprite::checkEvent() {

}

// draws the sprite
void AnimationSprite::render() {
  windowPointer->draw(sprite);
}

// sets position of the sprite
void AnimationSprite::setPosition(int s_xPos, int s_yPos) {
  sprite.setPosition(s_xPos, s_yPos);
  x_Pos = s_xPos;
  y_Pos = s_yPos;
}

bool AnimationSprite::end() {
  return floor(index) == total_frames - 1;
}

void AnimationSprite::flip(bool isFlipped) {
  if(isFlipped = true) {
    this->isFlipped = true;
    sprite.setScale(-scale, scale);
  }
  else {
    this->isFlipped = false;
    sprite.setScale(scale, scale);
  }
}
