#ifndef GRAPHIC_BUTTON_H
#define GRAPHIC_BUTTON_H

#include "Sprite.h"


enum ButtonType {
    Play = 0,
    Settings,
    Quit
};

class Button: public Sprite {
    public:
        ButtonType type;
        Button(float x, float y, float scale, const std::string &filename, ButtonType type);
};


#endif