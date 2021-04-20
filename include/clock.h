
#ifndef ESP_CLOCK_H
#define ESP_CLOCK_H

#include "clock_base.h"

class Clock : public ClockBase {
protected:
    void correct_time();
    static void add_time(Clock& to_add_to,int amount);


public:
    Clock();

    Clock(int h, int m, int s);


    std::string to_string(bool format_12h) const;
    std::string to_string(char fill = '0', char separator = ':', bool format_12h = false) const;


    Clock operator=(Clock const & rhs);
    Clock operator+(int rhs) const;
    Clock operator-(int rhs) const;
    Clock& operator++();
    Clock operator++(int);
    Clock& operator--();
    Clock operator--(int);
};



#endif //HEJ_CLOCK_BASE_H