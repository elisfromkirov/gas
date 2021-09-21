#include "EventManager.hpp"

void EventManager::DispatchAll() {    
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
    
void EventManager::PostEvent(IEvent* event) {
    queue_.push_back(event);
}

void EventManager::AddListener(IEventListener* listener, uint32_t categories) {
    listeners_.push_back(Listener{listener, categories});
}
