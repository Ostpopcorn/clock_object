#include <cstring>
#include "../include/counter_clock.h"

CounterClock::CounterClock() {}

CounterClock::CounterClock(int h, int m, int s) : ClockBase(h, m, s) {
}

std::string CounterClock::to_string(char fill) const {
    char* buff = new char[12];
    ClockBase::to_string_base(buff,fill,false);
    std::string a(buff,9);
    delete[] buff;
    return  a;
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

}

CounterClock CounterClock::operator=(const CounterClock &rhs) {
    second = rhs.get_second();
    minute = rhs.get_minute();
    hour = rhs.get_hour();
    return *this;
}

CounterClock CounterClock::operator+(int rhs) const {
    CounterClock output{this->get_hour(), this->get_minute(), this->get_second()+ rhs};
    output.correct_time();
    return output;
}

CounterClock CounterClock::operator-(int rhs) const {
    CounterClock return_clock = *this + (-rhs);
    return return_clock;
}

CounterClock CounterClock::operator++(int) {
    CounterClock return_clock{*this};
    this->increment_time();
    return return_clock;
}

CounterClock &CounterClock::operator++() {
    this->increment_time();
    return *this;
}

CounterClock CounterClock::operator--(int) {
    CounterClock return_clock{*this};
    this->decrement_time();
    return return_clock;
}

CounterClock& CounterClock::operator--() {
    this->decrement_time();
    return *this;
}

