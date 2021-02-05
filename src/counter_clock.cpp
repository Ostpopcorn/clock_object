#include <cstring>
#include "../include/counter_clock.h"

CounterClock::CounterClock() {}

CounterClock::CounterClock(int h, int m, int s) : ClockBase(h, m, s) {
    correct_time();
}

std::string CounterClock::to_string(char fill) const {
    char* buff = new char[12];
    ClockBase::to_string_base(buff,fill,false);
    std::string a(buff,9);
    delete[] buff;
    return  a;
}

void CounterClock::correct_time() {
    if (this->get_all_time_as_second() < 0 && !this->negative){
        // Should be converted from positive to negative
        int diff {this->get_all_time_as_second()};
        this->negative = true;
        this->hour = 0;
        this->minute = 0;
        this->second = -diff;
    }else if (this->get_all_time_as_second() >= 0 && this->negative){
        // Should be converted from negative to positive
        int diff {this->get_all_time_as_second()};
        this->negative = false;
        this->hour = 0;
        this->minute = 0;
        this->second = diff;
    }

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



    /*Clock output{this->get_hour(), this->get_minute(), this->get_second()};

    int tot_len{output.get_all_time_as_second()};
    if( (rhs+tot_len) < 0 && negative ){
        // tot_len is larger than rhs so just add
        output.second -= rhs;
    }else if( (rhs + tot_len) > 0 && !negative){
        // tot_len is larger than rhs so just add
        output.second += rhs;
    }else{
        rhs += tot_len;
        output = Clock{0,0,rhs};
    }
    output.correct_time();
    return output;*/

}

CounterClock CounterClock::operator=(const CounterClock &rhs) {
    negative = rhs.negative;
    second = rhs.get_second();
    minute = rhs.get_minute();
    hour = rhs.get_hour();
    return *this;
}

CounterClock CounterClock::operator+(int rhs) const {
    CounterClock output{*this};
    add_time(output,rhs);
    return output;
}

CounterClock CounterClock::operator-(int rhs) const {
    CounterClock return_clock = *this + (-rhs);
    return return_clock;
}

CounterClock CounterClock::operator++(int) {
    CounterClock return_clock{*this};
    add_time(*this,1);
    return return_clock;
}

CounterClock &CounterClock::operator++() {
    add_time(*this,1);
    return *this;
}

CounterClock CounterClock::operator--(int) {
    CounterClock return_clock{*this};
    add_time(*this,-1);
    return return_clock;
}

CounterClock& CounterClock::operator--() {
    add_time(*this,-1);
    return *this;
}

void CounterClock::add_time(CounterClock& to_add_to,int amount){
    if (to_add_to.negative){
        to_add_to.second -= amount;
    }else{
        to_add_to.second += amount;
    }
    to_add_to.correct_time();
}

