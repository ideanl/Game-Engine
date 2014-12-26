#ifndef LEVEL1_H
#define LEVEL1_H

#include "../menulevel.h"

class Level1: public Level {
  public:
    void menuLevelUpdate();
  private:
    void setStartScene();
    void addKeys();
    void addEvents();
};

#endif
