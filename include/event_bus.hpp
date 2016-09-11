#ifndef EVENT_BUS_HPP
#define EVENT_BUS_HPP

#include <map>
#include <vector>
#include <functional>
#include <SFML/Window.hpp>

class EventBus
{

public:
    
    static std::map<sf::Event::EventType, std::vector<std::function<void(sf::Event)>>> bus;

    static void subscribe(sf::Event::EventType event, std::function<void(sf::Event)> func);
    static void publish(sf::Event event);
};

#endif
