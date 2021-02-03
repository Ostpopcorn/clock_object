#include <cstring>
#include "../include/clock.h"

std::string Clock::to_string(char fill, bool format_12h) const
{
    int print_len{format_12h ? 8 : 11};
    // int hms_start_pos{format_24h ? 0 : 0};
    int hms_start_pos{0};

    char output[11];
    char print_string[13];

    memset(output, fill, print_len);
    memset(print_string, fill, 13);

    bool has_larger{false};
    if (format_12h)
    {
        if (get_hour() > 0)
        {
            sprintf(print_string, "%.2i", get_hour());
            has_larger = true;
            fill = '0';
        }
    }
    else
    {
        if (get_hour() > 12)
        {
            sprintf(print_string, "%.2i", get_hour() - 12);
        }
        else if (get_hour() == 0)
        {
            sprintf(print_string, "%.2i", 12);
        }
        else
        {
            sprintf(print_string, "%.2i", get_hour());
        }
        has_larger = true;
    }
    if(print_string[0] == '0'){
        print_string[0] = fill;
    }
    memcpy(&output[hms_start_pos], print_string, 2);
    if (has_larger || fill != ' ')
    {
        output[hms_start_pos + 2] = ':';
    }

    // Minutes
    memset(print_string, fill, 2);
    if (get_minute() != 0)
    {

        memset(print_string, fill, 2);
        sprintf(print_string, "%.2i", get_minute());
        if(print_string[0] == '0' && !has_larger){
            print_string[0] = fill;
        }
        has_larger = true;
        fill = '0';
    }
    else
    {
        if (has_larger )
        {
            memset(print_string, '0', 2);
        }
    }

    memcpy(&output[hms_start_pos + 3], print_string, 2);
    if (has_larger || fill != ' ')
    {
        output[hms_start_pos + 5] = ':';
    }

    // Second
    memset(print_string, fill, 2);

    if (get_second() != 0)
    {
        sprintf(print_string, "%.2i", get_second());
        if(print_string[0] == '0' && !has_larger){
            print_string[0] = ' ';
        }
        has_larger = true;
        fill = '0';
    }
    else
    {
        if (has_larger)
        {
            memset(print_string, '0', 2);
        }
        else
        {
            memset(&print_string[1], '0', 1);
        }
    }

    memcpy(&output[hms_start_pos + 6], print_string, 2);

    /*AM/PM eller inget*/
    if (!format_12h)
    {
        if (get_hour() < 12)
        {
            memcpy(&output[8], " am", 3);
        }
        else
        {
            memcpy(&output[8], " pm", 3);
        }
    }

    return std::string(output, print_len);
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
    return false;
}

bool Clock::operator==(const Clock &rhs) const {
    return false;
}

bool Clock::operator<=(const Clock &rhs) const {
    return false;
}

bool Clock::operator>=(const Clock &rhs) const {
    return false;
}

bool Clock::operator!=(const Clock &rhs) const {
    return false;
}

