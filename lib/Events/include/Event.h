#ifndef EVENTS_EVENT_H
#define EVENTS_EVENT_H

class Event {
    public:
    ~Event() = default;
    enum EventType {
        MouseLeftClick = 0,
        MouseRightClick
    };
    EventType type;

    struct MousePosInfo {
        float x;
        float y;
    };

    union info_u {
        MousePosInfo mousePosInfo;
        ~info_u() { }  // DO NOT change this to =default, or else it will stop working (must be '{}')
    } info = {};

    Event(EventType, float, float);
};
#endif