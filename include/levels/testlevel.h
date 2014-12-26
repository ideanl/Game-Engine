#ifndef TestLevel_H
#define TestLevel_H

#include "../menulevel.h"

class TestLevel: public Level {
  public:
    void menuLevelUpdate();
  private:
    void setStartScene();
    void addKeys();
    void addEvents();
};

#endif
