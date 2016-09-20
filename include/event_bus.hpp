#ifndef EVENT_BUS_HPP
#define EVENT_BUS_HPP

#include <map>
#include <vector>
#include <functional>
#include <cstdint>
#include <SFML/Window.hpp>
#include "sequence.hpp"

typedef std::map<uintptr_t, std::function<void(sf::Event)>> callback_map_t;
typedef std::map<sf::Event::EventType, callback_map_t> event_map_t;
typedef std::map<uintptr_t, std::vector<sf::Event::EventType>> ptr_map_t;

class EventBus
{

private:

    ptr_map_t ptr_map;
    event_map_t bus;

public:

    void publish(const sf::Event event);
    void unsubscribe(const void * const ptr);

    template <typename T>
    void subscribe(const sf::Event::EventType event_type, T* instance, void(T:: *func)(sf::Event)) 
    {
        uintptr_t handle = reinterpret_cast<uintptr_t>(instance);
        this->ptr_map[handle].push_back(event_type);
        this->bus[event_type][handle] = std::bind(func, instance, std::placeholders::_1);
    }
};

#endif
