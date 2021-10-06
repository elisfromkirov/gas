#ifndef __EVENT_MANAGER_HPP__
#define __EVENT_MANAGER_HPP__

#include <list>

#include "IEvent.hpp"
#include "IEventListener.hpp"

class EventManager {
public:
    EventManager();
    ~EventManager();

    void DispatchAllEvents();

    void DispatchEvents(uint32_t category);

    template <typename EventT, typename... Args>
    void SendEvent(Args&&... args);

    void RegisterListener(IEventListener* listener, uint32_t categories);

private:
    std::list<IEvent*> queue_;

    struct Listener {
        IEventListener* listener;
        uint32_t        categories;
    };
    std::list<Listener> listeners_;
};

template <class EventT, class... Args>
void EventManager::SendEvent(Args&&... args) {
    auto event = new EventT(std::forward<Args>(args)...);

    queue_.push_back(event);
}

#endif // __EVENT_MANAGER_HPP__
