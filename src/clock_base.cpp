
#include "../include/clock_base.h"
#include <cstring>

using namespace std;

ClockBase::ClockBase() {}

ClockBase::ClockBase(int h, int m, int s) : hour{h}, minute{m}, second{s}
{

}

// Komplettering: Vi vill, som skapare av en modul, aldrig skriva ut
// error meddelande direkt till terminalen.
void ClockBase::set_time(int h, int m, int s)
{
    //: hour{h}, minute{m}, second{s}
    if (h < 0 || h > 23)
    {
        //cout << "Felaktig inmatning! Out of bounds, timma" << endl;
    }
    if (m < 0 || m > 59)
    {
        //cout << "Felaktig inmatning! Out of bounds, minut" << endl;
    }
    if (s < 0 || s > 59)
    {
        //cout << "Felaktig inmatning! Out of bounds, sekund" << endl;
    }
    hour = h;
    minute = m;
    second = s;
}

void ClockBase::increment_time()
{
    second += 1;
    correct_time();
}
void ClockBase::decrement_time()
{
    second -= 1;
    correct_time();
}


int ClockBase::get_hour() const
{
    return hour;
}
int ClockBase::get_minute() const
{
    return minute;
}
int ClockBase::get_second() const
{
    return second;
}
int ClockBase::get_all_time_as_second() const
{
    return this->second + (60 * this->minute) + (60 * 60 * this->hour);
}

bool ClockBase::operator<(ClockBase const &rhs) const
{
    // Jämför först timmar
    if (this->get_hour() < rhs.get_hour())
    {
        return true;
    }
    else if (this->get_hour() > rhs.get_hour())
    {
        return false;
    }

    // Om det är samma timme så undersöks minuter
    if (this->get_minute() < rhs.get_minute())
    {
        return true;
    }
    else if (this->get_minute() > rhs.get_minute())
    {
        return false;
    }

    // Om det är samma minut så undersöks sekund
    if (this->get_second() < rhs.get_second())
    {
        return true;
    }
    return false;
}

bool ClockBase::operator>(ClockBase const &rhs) const
{
    // Jämför först timmar
    if (this->get_hour() > rhs.get_hour())
    {
        return true;
    }
    else if (this->get_hour() < rhs.get_hour())
    {
        return false;
    }

    // Om det är samma timme så undersöks minuter
    if (this->get_minute() > rhs.get_minute())
    {
        return true;
    }
    else if (this->get_minute() < rhs.get_minute())
    {
        return false;
    }

    // Om det är samma minut så undersöks sekund
    if (this->get_second() > rhs.get_second())
    {
        return true;
    }
    return false;
}

bool ClockBase::operator==(ClockBase const &rhs) const
{
    return !((*this < rhs) || (*this > rhs));
}

bool ClockBase::operator<=(ClockBase const &rhs) const
{
    return !(*this > rhs);
}

bool ClockBase::operator>=(ClockBase const &rhs) const
{
    return !(*this < rhs);
}

bool ClockBase::operator!=(ClockBase const &rhs) const
{
    return !(*this == rhs);
}

ClockBase::~ClockBase() {

}
/*std::string ClockBase::to_string(char fill, bool format_24h) const
{
    int print_len{format_24h ? 8 : 11};
    // int hms_start_pos{format_24h ? 0 : 0};
    int hms_start_pos{0};

    char output[11];
    char print_string[13];

    memset(output, fill, print_len);
    memset(print_string, fill, 13);

    bool has_larger{false};
    if (format_24h)
    {
        if (hour > 0)
        {
            sprintf(print_string, "%.2i", hour);
            has_larger = true;
            fill = '0';
        }
    }
    else
    {
        if (hour > 12)
        {
            sprintf(print_string, "%.2i", hour - 12);
        }
        else if (hour == 0)
        {
            sprintf(print_string, "%.2i", 12);
        }
        else
        {
            sprintf(print_string, "%.2i", hour);
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
    if (minute != 0)
    {

        memset(print_string, fill, 2);
        sprintf(print_string, "%.2i", minute);
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

    if (second != 0)
    {
        sprintf(print_string, "%.2i", second);
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

    *//*AM/PM eller inget*//*
    if (!format_24h)
    {
        if (hour < 12)
        {
            memcpy(&output[8], " am", 3);
        }
        else
        {
            memcpy(&output[8], " pm", 3);
        }
    }

    return string(output, print_len);
}*/
void ClockBase::get_seconds_string(char* to_print_to, char fill) const {
    /*
     * prints to the char array what second it currently is.
     * Max 2 digits
     */
    char ones_digit{static_cast<char>('0'+(get_second())%10)};
    char tens_digit{static_cast<char>('0'+(get_second()/10)%10)};

    if (get_hour() != 0 || get_minute() != 0){
        // Has larger
        to_print_to[0] = tens_digit;
        to_print_to[1] = ones_digit;

    }else{
        if ( tens_digit == '0' ){
            to_print_to[0] = fill;
        }else{
            to_print_to[0] = tens_digit;
        }
        to_print_to[1] = ones_digit;
    }
}

void ClockBase::get_minute_string(char* to_print_to, char fill) const {
    /*
     * prints to the char array what second it currently is.
     * Max 2 digits
     */
    char ones_digit{static_cast<char>('0'+(get_minute())%10)};
    char tens_digit{static_cast<char>('0'+(get_minute()/10)%10)};

    if (get_hour() != 0){
        // Has larger, should fill with 0:s
        to_print_to[0] = tens_digit;
        to_print_to[1] = ones_digit;

    }else{
        if ( tens_digit == '0' ){
            to_print_to[0] = fill;
            to_print_to[1] = (ones_digit == '0')?fill:ones_digit;
        }else{
            to_print_to[0] = tens_digit;
            to_print_to[1] = ones_digit;
        }
    }
}

void ClockBase::get_hour_string(char *to_print_to, char fill, bool format_12h) const {
    /*
     * prints to the char array what second it currently is.
     * Max 3 chars, 2 digits and one minus sign
     * Having hour be negative and format 12 h has undefined behaviour
     */
    bool is_negative{get_hour()<0};
    int hour_to_use{get_hour()};
    if (is_negative){
        hour_to_use = -hour_to_use;
    }
    if (format_12h){
        hour_to_use = get_hour()%12; // 0-11
        if(hour_to_use == 0){
            //should be 12
            hour_to_use = 12;
        }
    }
    char ones_digit{static_cast<char>('0'+(hour_to_use)%10)};
    char tens_digit{static_cast<char>('0'+(hour_to_use/10)%10)};

    if ( tens_digit == '0' ){
        to_print_to[1] = fill;
        to_print_to[2] = (ones_digit == '0')?fill:ones_digit;
    }else{
        to_print_to[1] = tens_digit;
        to_print_to[2] = ones_digit;
    }
    to_print_to[0] = !is_negative?'+':'-';

}

void ClockBase::to_string_base(char* output, char fill, bool format_12h) const {
    int print_len{format_12h ? 12 : 9};
    // int hms_start_pos{format_24h ? 0 : 0};
    int hms_start_pos{0};

    memset(output, fill, print_len);

    get_hour_string(&output[hms_start_pos], fill, format_12h);

    if (get_hour() != 0 || fill != ' ' || format_12h) {
        output[hms_start_pos + 3] = ':';
    }

    get_minute_string(&output[hms_start_pos + 4], fill);
    if (get_minute() != 0 || get_hour() != 0 || fill != ' ' || format_12h) {
        output[hms_start_pos + 6] = ':';
    }
    get_seconds_string(&output[hms_start_pos + 7], fill);


    /*AM/PM eller inget*/
    if (format_12h) {
        if (get_hour() < 12) {
            memcpy(&output[9], " am", 3);
        } else {
            memcpy(&output[9], " pm", 3);
        }
    }
}

