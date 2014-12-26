#ifndef STARTMENU_H
#define STARTMENU_H

#include "../menulevel.h"

class StartMenu: public Menu {
  public:
    void menuLevelUpdate();
  private:
    void setStartScene();
    void addKeys();
    void addEvents();
};

#endif
