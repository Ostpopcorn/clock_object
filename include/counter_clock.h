//
// Created by adrian on 2021-02-01.
//

#ifndef HEJ_COUNTER_CLOCK_H
#define HEJ_COUNTER_CLOCK_H
#include "clock.h"

class CounterClock : public ClockBase {
public:
    CounterClock();

    CounterClock(int h, int m, int s);

    std::string to_string(char fill='0') const;
protected:
    void correct_time() override;


};

#endif //HEJ_COUNTER_CLOCK_H
