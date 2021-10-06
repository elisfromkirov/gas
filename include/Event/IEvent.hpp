#ifndef __I_EVENT_HPP__
#define __I_EVENT_HPP__

#include <cassert>
#include <cstdint>

enum EventCategory : uint32_t {
    kNoneCategory           = 0,
    kCollisionEventCategory = 1
};

class IEvent {
public:
    virtual ~IEvent() {}

    virtual uint32_t GetCategory() const = 0;
};

#endif // __I_EVENT_HPP__
