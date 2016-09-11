#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

class Sequence
{

private:

    int current;
    int start;
    int end;
    int stepper;

public:

    Sequence(int start, int end, int stepper);
    int step();
    int get();
    void reset();
};

#endif
