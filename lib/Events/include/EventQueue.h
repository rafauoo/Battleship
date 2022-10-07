#ifndef EVENTS_EVENTQUEUE_H
#define EVENTS_EVENTQUEUE_H

#include <queue>
#include <memory>

template <class E>
class EventQueue {
public:
    EventQueue(EventQueue&) = delete;

    bool operator=(const EventQueue&) = delete;

    void registerEvent(std::unique_ptr<E> event){
        events_.push(std::move(event));
    };

    std::unique_ptr<E> pop(){
        auto first = std::move(events_.front());
        events_.pop();
        return std::move(first);
    };

    bool isEmpty(){
        return events_.empty();
    };

    unsigned int size(){
        return events_.size();
    }

    void clear(){
        std::queue<std::unique_ptr<E>>().swap(events_);
    }

    static EventQueue* instance(){
        static std::unique_ptr<EventQueue<E>> self(new EventQueue<E>);
        return self.get();
    };

protected:
    std::queue<std::unique_ptr<E>> events_;

    static std::unique_ptr<EventQueue> self_;

private:
    EventQueue()=default;

};


#endif
