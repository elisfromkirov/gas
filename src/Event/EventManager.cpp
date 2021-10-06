#include "EventManager.hpp"

EventManager::EventManager() {}

EventManager::~EventManager() {}

void EventManager::DispatchAllEvents() {
    while (!queue_.empty()) {
        IEvent* event = queue_.front();

        for (auto listener : listeners_) {
            if (listener.categories & event->GetCategory()) {
                listener.listener->OnEvent(event);
            }
        }

        queue_.pop_front();
        delete event;
    }
}

void EventManager::DispatchEvents(uint32_t category) {
    auto iterator = queue_.begin();
    while (iterator != queue_.end()) {
        IEvent* event = *iterator;

        if (category & event->GetCategory()) {
            for (auto listener : listeners_) {
                if (listener.categories & event->GetCategory()) {
                    listener.listener->OnEvent(event);
                }
            }

            auto tmp = iterator;
            ++iterator;
            queue_.erase(tmp);
        } else {
            ++iterator;
        }
    }
}

void EventManager::RegisterListener(IEventListener* listener, uint32_t categories) {
    listeners_.push_back(Listener{listener, categories});
}
