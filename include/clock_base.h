#ifndef ESP_CLOCK_BASE_H
#define ESP_CLOCK_BASE_H
#include <string>
class ClockBase
{
private:
    void get_seconds_string(char* to_print_to, char fill = '0') const;
    void get_minute_string(char* to_print_to, char fill = '0') const;
    void get_hour_string(char *to_print_to, char fill = '0', bool format_12h = false) const;

protected:
    int hour{};
    int minute{};
    int second{};
    virtual void correct_time() = 0;
    void set_time(int, int, int);

    void increment_time();
    void decrement_time();

    void to_string_base(char* output, char fill = '0', bool format_12h = false) const;

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

