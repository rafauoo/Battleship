#include <memory>
#include <utility>

#include "include/Event.h"

Event::Event(EventType e, float x, float y) {
    type = e;
    switch (e) {
        case (MouseLeftClick): {
            info.mousePosInfo = {x, y};
            break;
        }
    }
}