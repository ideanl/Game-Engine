#ifndef MENULEVEL_H 
#define MENULEVEL_H
#include <string>

class MenuLevel {
  public:
    std::string name;

};

class Level: public MenuLevel  {
};

class Menu: public MenuLevel  {
};
#endif
