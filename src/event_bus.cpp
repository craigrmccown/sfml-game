#include "../include/event_bus.hpp"

EventBus::EventBus()
{
    this->bus = bus_type();
}

void EventBus::publish(sf::Event event)
{
    std::map<int, std::function<void(sf::Event)>> func_map = this->bus[event.type];

    for(std::map<int, std::function<void(sf::Event)>>::iterator i = func_map.begin(); i != func_map.end(); i++)
    {
        i->second(event);
    }
}

void EventBus::unsubscribe(int token)
{
    sf::Event::EventType event_type = this->token_map[token];
    this->bus[event_type].erase(token);
}
