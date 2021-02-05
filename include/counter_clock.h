#ifndef HEJ_COUNTER_CLOCK_H
#define HEJ_COUNTER_CLOCK_H
#include "clock.h"

class CounterClock : public ClockBase {
private:
protected:
    static void add_time(CounterClock& to_add_to,int amount);
    void correct_time();

public:
    CounterClock();

    CounterClock(int h, int m, int s);

    std::string to_string(char fill='0') const;

    CounterClock operator=(CounterClock const & rhs);
    CounterClock operator+(int rhs) const;
    CounterClock operator-(int rhs) const;
    CounterClock& operator++();
    CounterClock operator++(int);
    CounterClock& operator--();
    CounterClock operator--(int);

};

#endif //HEJ_COUNTER_CLOCK_H
