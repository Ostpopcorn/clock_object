#include <cstring>
#include "../include/clock.h"

std::string Clock::to_string(bool format_12h) const {
    return to_string('0',true);
}

std::string Clock::to_string(char fill, bool format_12h) const
{
    char* buff = new char[12];
    ClockBase::to_string_base(buff,fill,format_12h);
    std::string a(&buff[1],format_12h?11:8);
    delete[] buff;
    return  a;

}

Clock::Clock() {}

Clock::Clock(int h, int m, int s) : ClockBase(h, m, s) {
    correct_time();
}

void Clock::correct_time() {

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
    this->negative = false;
}



Clock Clock::operator=(const Clock &rhs) {
    negative = rhs.negative;
    second = rhs.get_second();
    minute = rhs.get_minute();
    hour = rhs.get_hour();
    return *this;
}

Clock Clock::operator+(int rhs) const {
    Clock output{*this};
    add_time(output,rhs);
    return output;
}

Clock Clock::operator-(int rhs) const {
    Clock return_clock = *this + (-rhs);
    return return_clock;
}

Clock Clock::operator++(int) {
    Clock return_clock{*this};
    add_time(*this,1);
    return return_clock;
}

Clock &Clock::operator++() {
    add_time(*this,1);
    return *this;
}

Clock Clock::operator--(int) {
    Clock return_clock{*this};
    add_time(*this,-1);
    return return_clock;
}

Clock& Clock::operator--() {;
    add_time(*this,-1);
    return *this;
}

void Clock::add_time(Clock &to_add_to, int amount) {
    if (to_add_to.negative){
        to_add_to.second -= amount;
    }else{
        to_add_to.second += amount;
    }
    to_add_to.correct_time();

}
