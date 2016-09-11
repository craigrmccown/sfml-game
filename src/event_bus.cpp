#include "../include/event_bus.hpp"

std::map<sf::Event::EventType, std::vector<std::function<void(sf::Event)>>> EventBus::bus = std::map<sf::Event::EventType, std::vector<std::function<void(sf::Event)>>>();

void EventBus::publish(sf::Event event)
{
    std::vector<std::function<void(sf::Event)>> funcs = EventBus::bus[event.type];

    for(std::vector<std::function<void(sf::Event)>>::size_type i = 0; i < funcs.size(); i++)
    {
        funcs[i](event);
    }
}
