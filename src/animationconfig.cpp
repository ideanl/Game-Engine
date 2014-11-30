#include "../include/spriteconfig.h"

AnimationConfig::AnimationConfig(float s_animationSpeed, int s_total_frames, int s_columns, int s_rows, bool s_always_moving, float s_default_index) {
  animationSpeed = s_animationSpeed;
  columns = s_columns;
  rows = s_rows;
  total_frames = s_total_frames;
  always_moving = s_always_moving;
  default_index = s_default_index;
}


float AnimationConfig::getAnimationSpeed() {
  return animationSpeed;
}

int AnimationConfig::getColumns() {
  return columns;
}

int AnimationConfig::getRows() {
  return rows;
}

int AnimationConfig::getTotalFrames() {
  return total_frames;
}

bool AnimationConfig::getAlwaysMoving() {
  return always_moving;
}

float AnimationConfig::getDefaultIndex() {
  return default_index;
}
