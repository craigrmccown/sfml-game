#include "../include/event_bus.hpp"

void EventBus::publish(const sf::Event event)
{
    callback_map_t cb_map = this->bus[event.type];

    for(auto i = cb_map.begin(); i != cb_map.end(); i ++)
    {
        i->second(event);
    }
}

void EventBus::unsubscribe(const void * const ptr)
{
    uintptr_t handle = reinterpret_cast<uintptr_t>(ptr);

    if (!this->ptr_map.count(handle))
    {
        return;
    }

    std::vector<sf::Event::EventType> event_types = this->ptr_map[handle];

    for (auto i = event_types.begin(); i < event_types.end(); i++)
    {
        this->bus[*i].erase(handle);
    }

    this->ptr_map.erase(handle);
}
