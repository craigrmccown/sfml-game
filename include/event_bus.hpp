#ifndef EVENT_BUS_HPP
#define EVENT_BUS_HPP

#include <map>
#include <vector>
#include <functional>
#include "stdint.h"
#include <SFML/Window.hpp>
#include "sequence.hpp"

typedef std::map<sf::Event::EventType, std::map<uintptr_t, std::function<void(sf::Event)>>> bus_type;
typedef std::map<uintptr_t, std::vector<sf::Event::EventType>> ptr_map_type;

class EventBus
{

private:

    ptr_map_type ptr_map;

public:
    
    bus_type bus;

    EventBus();
    void publish(sf::Event event);
    void unsubscribe(void *ptr);

    template <typename T>
    void subscribe(sf::Event::EventType event_type, T *instance, void(T:: *func)(sf::Event)) 
    {
        this->ptr_map[reinterpret_cast<uintptr_t>(instance)].push_back(event_type);
        this->bus[event_type][reinterpret_cast<uintptr_t>(instance)] = std::bind(func, instance, std::placeholders::_1);
    }
};

#endif
