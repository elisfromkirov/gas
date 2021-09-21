#ifndef __I_EVENT_HPP__
#define __I_EVENT_HPP__

#include <cstdint>

enum EventCategory : uint32_t {
    kNoneCategoty         = 0x00000000,
    kInputEventCategory   = 0x00010000,
    kPhysicsEventCategory = 0x00020000,
    kAllEventCategories   = 0xffff0000
};

class IEvent {
public:
    virtual ~IEvent() {}

    /// Event manager filter event by category.
    virtual uint32_t GetCategory() const = 0;
    
    /// Unique bitmask for every event.
    /// Bits from  0 to 15 is event type, bits from 16 to 31 is event category.
    virtual uint32_t GetMask() const = 0;
};

#endif // __I_EVENT_HPP__
