#ifndef GRAPHIC_MENUWINDOW_H
#define GRAPHIC_MENUWINDOW_H
#include "Window.h"
#include <queue>

class MenuWindow: public Window {
  public:
    virtual void render() override;
};

#endif