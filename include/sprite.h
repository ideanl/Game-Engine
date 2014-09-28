#ifndef SPRITE_H
#define SPRITE_H

#include <SFML/Graphics.hpp>

class Sprite {

  public:
    Sprite();
    inline void setWindowPointer(sf::RenderWindow& window) {windowpointer = &window;}
    inline void setX_Velocity(int s_xVelocity) {x_Velocity = s_xVelocity;}
    inline void setY_Velocity(int s_yVelocity) {y_Velocity = s_yVelocity;}
    inline void setX_Pos(int s_xPos) {x_Pos = s_xPos;}
    inline void setY_Pos(int s_yPos) {y_Pos = s_xPos;}
    virtual void create() = 0;
    virtual void checkEvent() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    ~Sprite();
  protected:
    int x_Velocity, y_Velocity, x_Pos, y_pos;
    sf::RenderWindow* windowPointer;
  private:
};

#endif
