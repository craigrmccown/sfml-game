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


    static void publish(sf::Event event);

    template <typename T>
    static void subscribe(sf::Event::EventType event,T *instance, void(T:: *func)(sf::Event)) 
    {
        EventBus::bus[event].push_back(std::bind(func, instance, std::placeholders::_1));
    }
};

#endif
