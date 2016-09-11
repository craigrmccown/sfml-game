#ifndef EVENT_BUS_HPP
#define EVENT_BUS_HPP

#include <map>
#include <vector>
#include <functional>
#include <SFML/Window.hpp>
#include "sequence.hpp"

typedef std::map<sf::Event::EventType, std::map<int, std::function<void(sf::Event)>>> bus_type;

class EventBus
{

private:

    Sequence token_seq = Sequence(0, 5000, 1);
    std::map<int, sf::Event::EventType> token_map;

public:
    
    bus_type bus;

    EventBus();
    void publish(sf::Event event);
    void unsubscribe(int token);

    template <typename T>
    int subscribe(sf::Event::EventType event_type, T *instance, void(T:: *func)(sf::Event)) 
    {
        /* get the current value of the sequence */
        int val = this->token_seq.get();

        this->token_map[val] = event_type;
        this->bus[event_type][val] = std::bind(func, instance, std::placeholders::_1);

        /* step the current value of the sequence */
        this->token_seq.step();

        return val;
    }
};

#endif
