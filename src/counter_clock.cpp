//
// Created by adrian on 2021-02-01.
//

#include "../include/counter_clock.h"

CounterClock::CounterClock() {}

CounterClock::CounterClock(int h, int m, int s) : ClockBase(h, m, s) {
    correct_time();
}

std::string CounterClock::to_string(char fill) const {
    return std::string("HEJ");
}

void CounterClock::correct_time() {
    int temp{};
    temp = second / 60;
    minute += temp;
    second = second - (60 * temp);
    if (second < 0)
    {
        minute -= 1;
        second += 60;
    }

    temp = minute / 60;
    hour += temp;
    minute = minute - (60 * temp);
    if (minute < 0)
    {
        hour -= 1;
        minute += 60;
    }

    hour %= 24;
    if (hour < 0)
    {
        hour += 24;
    }
}
