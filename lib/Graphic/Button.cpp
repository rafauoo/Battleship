#include "include/Button.h"

Button::Button(float x, float y, float scale, const std::string &filename, ButtonType type):
Sprite(x, y, scale, filename), type(type) {}