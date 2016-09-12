#include "../include/event_bus.hpp"

EventBus::EventBus()
{
    this->bus = bus_type();
}

void EventBus::publish(sf::Event event)
{
    std::map<uintptr_t, std::function<void(sf::Event)>> func_map = this->bus[event.type];

    for(std::map<uintptr_t, std::function<void(sf::Event)>>::iterator i = func_map.begin(); i != func_map.end(); i++)
    {
        i->second(event);
    }
}

void EventBus::unsubscribe(void *ptr)
{
    uintptr_t ptr_val = reinterpret_cast<uintptr_t>(ptr);

    if (!this->ptr_map.count(ptr_val))
    {
        return;
    }

    std::vector<sf::Event::EventType> event_types = this->ptr_map[ptr_val];

    for(std::vector<sf::Event::EventType>::iterator i = event_types.begin(); i < event_types.end(); i++)
    {
        this->bus[*i].erase(ptr_val);
    }

    this->ptr_map.erase(ptr_val);
}
