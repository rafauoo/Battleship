#include <memory>
#include <utility>

#include "include/Event.h"

Event::Event(EventType e, int x, int y) {
    type = e;
    switch (e) {
        case (MouseLeftClick): {
            info.mousePosInfo = {x, y};
            break;
        }
        case (MouseRightClick): {
            info.mousePosInfo = {x, y};
            break;
        }
        case (MouseLeftReleased): {
            info.mousePosInfo = {x, y};
            break;
        }
        case (MouseRightReleased): {
            info.mousePosInfo = {x, y};
            break;
        }
        default: {
            break;
        }
    }
}

Event::Event(EventType e, int i) {
    type = e;
    switch(e) {
        case (KeyPressed): {
            info.keyInfo.key = i;
            break;
        }
        case (KeyReleased): {
            info.keyInfo.key = i;
            break;
        }
        default: {
            break;
        }
    }
}

Event::Event(EventType e) {
    type = e;
    switch(e) {
        case (NullEvent): {
            break;
        }
        default: {
            break;
        }
    }
}