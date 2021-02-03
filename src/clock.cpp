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
}


Clock::Clock(const ClockBase& base) {
    ClockBase::operator=(base);
}

Clock Clock::operator=(const Clock &rhs) {
    second = rhs.get_second();
    minute = rhs.get_minute();
    hour = rhs.get_hour();
    return *this;
}

Clock Clock::operator+(int rhs) const {
    Clock output{this->get_hour(), this->get_minute(), this->get_second()+ rhs};
    output.correct_time();
    return output;
}

Clock Clock::operator-(int rhs) const {
    Clock return_clock = *this + (-rhs);
    return return_clock;
}

Clock Clock::operator++(int) {
    Clock return_clock{};
    return_clock = *this;
    this->increment_time();
    return return_clock;
}

Clock &Clock::operator++() {
    Clock return_clock{};
    this->increment_time();
    return *this;
}

Clock Clock::operator--(int) {
    Clock return_clock{};
    return_clock = *this;
    this->decrement_time();
    return return_clock;
}

Clock& Clock::operator--() {
    Clock return_clock{};
    this->decrement_time();
    return *this;
}

bool Clock::operator<(const Clock &rhs) const {
    return ClockBase::operator<(rhs);
}

bool Clock::operator>(const Clock &rhs) const {
    return ClockBase::operator>(rhs);
}

bool Clock::operator==(const Clock &rhs) const {
    return ClockBase::operator==(rhs);
}

bool Clock::operator<=(const Clock &rhs) const {
    return ClockBase::operator<=(rhs);
}

bool Clock::operator>=(const Clock &rhs) const {
    return ClockBase::operator>=(rhs);
}

bool Clock::operator!=(const Clock &rhs) const {
    return ClockBase::operator!=(rhs);
}


