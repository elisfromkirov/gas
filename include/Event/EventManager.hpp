#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__

#include <list>

#include "IEvent.hpp"
#include "IEventListener.hpp"

class EventManager {
public:
    void DispatchAll();

    void DispatchEvents(uint32_t category);

    void PostEvent(IEvent* event);

    void AddListener(IEventListener* listener, uint32_t categories = kAllEventCategories);

private:
    std::list<IEvent*>  queue_;

    struct Listener {
        IEventListener* listener;
        uint32_t        categories;
    };
    std::list<Listener> listeners_;
};

#endif // __EVENT_MANAGER_HPP__
