
#ifndef ESP_CLOCK_H
#define ESP_CLOCK_H

#include "clock_base.h"

class Clock : public ClockBase {
protected:
    void correct_time() override;
public:
    Clock();

    Clock(int h, int m, int s);

    Clock(const ClockBase& base);

    std::string to_string(char fill = '0', bool format_12h = false) const;


    Clock operator=(Clock const & rhs);
    Clock operator+(int rhs) const;
    Clock operator-(int rhs) const;
    // Komplettering: Se standard declaration av prefix och postfix
    // operatorerna på cpppreference.
    Clock& operator++();
    Clock operator++(int);
    Clock& operator--();
    Clock operator--(int);

    bool operator<(Clock const &rhs) const;
    bool operator>(Clock const &rhs) const;
    bool operator==(Clock const &rhs) const;
    bool operator<=(Clock const &rhs) const;
    bool operator>=(Clock const &rhs) const;
    bool operator!=(Clock const &rhs) const;

};


#endif //HEJ_CLOCK_BASE_H