#ifndef SPRITECONFIG_H
#define SPRITECONFIG_H

class SpriteConfig {
  
};

class AnimationConfig: public SpriteConfig{
  public:
    AnimationConfig(float s_animationSpeed, int s_total_frames, int s_columns, int s_rows, bool s_always_moving = false, float s_default_index = 0);
    float getAnimationSpeed();
    int getColumns();
    int getRows();
    int getFrameWidth();
    int getFrameHeight();
    int getTotalFrames();
    bool getAlwaysMoving();
    float getDefaultIndex();
  private:
    float animationSpeed;
    int columns;
    int rows;
    int frame_width;
    int frame_height;
    int total_frames;
    bool always_moving;
    float default_index;
};

#endif
