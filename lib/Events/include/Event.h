#ifndef EVENTS_EVENT_H
#define EVENTS_EVENT_H

class Event {
    public:
    ~Event() = default;
    enum EventType {
        MouseLeftClick = 0,
        MouseRightClick,
        MouseLeftReleased,
        MouseRightReleased,

        KeyPressed,
        KeyReleased,

        NullEvent
    };
    EventType type;

    struct MousePosInfo {
        int x;
        int y;
    };

    struct KeyInfo {
        int key;
    };

    union info_u {
        MousePosInfo mousePosInfo;
        KeyInfo keyInfo;
        ~info_u() { }  // DO NOT change this to =default, or else it will stop working (must be '{}')
    } info = {};

    // MouseLeftClick, MouseRightClick, MouseLeftReleased, MouseRightReleased
    Event(EventType, int, int);

    // Key Pressed, Key Released
    Event(EventType, int);

    // Null Event
    Event(EventType);
};

#endif