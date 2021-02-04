
#include <iostream>
#include "include/clock.h"
#include "include/counter_clock.h"

using namespace std;

int main(){
    Clock a(-1,1,59);
    cout << a.to_string() << endl;
    Clock clock_added{};
    //enkel addition
    clock_added = a + 9;
    a++;
    cout << a.to_string() << " " << clock_added.to_string() << endl;

    CounterClock b{CounterClock(1, 2, 3)};
    cout << b.to_string() << endl;
}
