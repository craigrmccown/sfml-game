#include "../include/sequence.hpp"

Sequence::Sequence(int start, int end, int stepper)
{
    this->current = start;
    this->start = start;
    this->end = end;
    this->stepper = stepper;
}

int Sequence::get()
{
    return this->current;
}

int Sequence::step()
{
    this->current = this->current + this->stepper;

    if (this->current > this->end)
    {
        this->current = this->start;
    }

    return this->current;
}

void Sequence::reset()
{
    this->current = this->start;
} 
