#ifndef ESP_CLOCK_BASE_H
#define ESP_CLOCK_BASE_H
#include <string>
class ClockBase
{

protected:
    int hour{};
    int minute{};
    int second{};
    virtual void correct_time() = 0;
    void set_time(int, int, int);

    void get_seconds_string(char* to_print_to, char fill = '0');
    void get_minute_string(char* to_print_to, char fill = '0');
    void get_hour_string(char *to_print_to, char fill = '0', bool format_12h = false);

    void increment_time();

    void decrement_time();

public:
    ClockBase();
    ClockBase(int h, int m, int s);
    virtual ~ClockBase();


    int get_hour() const;
    int get_minute() const;
    int get_second() const;
    int get_all_time_as_second() const;


    bool operator<(ClockBase const &rhs) const;
    bool operator>(ClockBase const &rhs) const;
    bool operator==(ClockBase const &rhs) const;
    bool operator<=(ClockBase const &rhs) const;
    bool operator>=(ClockBase const &rhs) const;
    bool operator!=(ClockBase const &rhs) const;
};

#endif

