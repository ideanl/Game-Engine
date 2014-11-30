#include "../include/spriteconfig.h"

AnimationConfig::AnimationConfig(float s_animationSpeed, int s_total_frames, int s_columns, int s_rows, int s_frame_width, int s_frame_height, bool s_always_moving, float s_default_index) {
  animationSpeed = s_animationSpeed;
  columns = s_columns;
  rows = s_rows;
  frame_width = s_frame_width;
  frame_height = s_frame_height;
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

int AnimationConfig::getFrameWidth() {
  return frame_width;
}

int AnimationConfig::getFrameHeight() {
  return frame_height;
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
