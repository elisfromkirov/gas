add_library(GasEvent)

set(INCROOT ${Gas_SOURCE_DIR}/include/Event)

target_include_directories(GasEvent
    PUBLIC
        ${INCROOT}
    )

target_sources(GasEvent
    PUBLIC
        ${INCROOT}/EventManager.hpp
        ${INCROOT}/IEvent.hpp
        ${INCROOT}/IEventListener.hpp
    PRIVATE
        EventManager.cpp
    )

