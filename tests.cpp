#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "include/clock.h"
#include "include/counter_clock.h"
using namespace std;

TEST_CASE("Initializing", "[clock]")
{
    Clock clock{00, 41, 50};
    CHECK(clock.to_string('0', true) == "00:41:50");
    CHECK(clock.to_string(' ', true) == "   41:50");
    CHECK(clock.to_string(false) == "12:41:50 am");
    clock = Clock{19, 41, 50};
    CHECK(clock.to_string(false) == "07:41:50 pm");
    clock = Clock{19, 41, 50};
    CHECK(clock.to_string(' ', false) == " 7:41:50 pm");
    CHECK(clock.to_string('0', false) == "07:41:50 pm");

    clock = Clock{0, 0, 50};
    CHECK(clock.to_string(' ', true) == "      50");
    CHECK(clock.to_string('a', true) == "aa:aa:50");
    clock = Clock{0, 0, 00};
    CHECK(clock.to_string(' ', true) == "       0");
    CHECK(clock.to_string('a', true) == "aa:aa:a0");

    clock = Clock{12, 41, 50};
    CHECK(clock.to_string() == "12:41:50");
    CHECK(clock.to_string(false) == "12:41:50 pm");

    clock = Clock{19, 41, 50};
    CHECK(clock.to_string() == "19:41:50");
    CHECK(clock.to_string(false) == "07:41:50 pm");

    clock = Clock{00, 30, 30};
    CHECK(clock.to_string() == "00:30:30");
    CHECK(clock.to_string(false) == "12:30:30 am");
    /*en fräsig kommentar*/
    // Mycket fräsig!
}

TEST_CASE("Addition och subtraktion", "[clock]")
{
    // Komplettering: Denna variabel används aldrig. 4-1
    Clock test_av_felaktig{24, -2, 10};
    Clock clock{12, 41, 50};
    Clock clock_added{};
    //enkel addition
    clock_added = clock + 9;
    CHECK(clock_added.to_string() == "12:41:59");
    CHECK((++clock_added).to_string() == "12:42:00");
    CHECK((clock_added++).to_string() == "12:42:00");
    CHECK((clock_added).to_string() == "12:42:01");

    clock_added = clock + 15;
    CHECK(clock_added.to_string() == "12:42:05");
    clock_added = clock + 3600;
    CHECK(clock_added.to_string() == "13:41:50");
    clock_added = clock + (3600 * 48);
    CHECK(clock_added.to_string() == "12:41:50");

    //enkel subtraktion
    clock_added = clock - (51 + 59);
    CHECK(clock_added.to_string() == "12:40:00");
    CHECK((--clock_added).to_string() == "12:39:59");
    CHECK((clock_added--).to_string() == "12:39:59");
    CHECK((clock_added).to_string() == "12:39:58");

    clock_added = clock - 3651;
    CHECK(clock_added.to_string() == "11:40:59");
    clock_added = clock - (3600 * 48);
    CHECK(clock_added.to_string() == "12:41:50");
}

TEST_CASE("Testar jämförelseoperatorer", "[clock]")
{
    Clock clock_intermediate{12, 41, 50};
    Clock clock_large{19, 41, 50};
    Clock clock_small{00, 30, 30};

    // Mindre än <
    CHECK_FALSE(clock_intermediate < clock_small);
    CHECK(clock_small < clock_intermediate);
    CHECK_FALSE(clock_large < clock_intermediate);
    CHECK_FALSE(clock_intermediate < clock_intermediate);

    // Mindre än >
    CHECK(clock_intermediate > clock_small);
    CHECK_FALSE(clock_small > clock_intermediate);
    CHECK(clock_large > clock_intermediate);
    CHECK_FALSE(clock_intermediate > clock_intermediate);

    //Lika med ==
    CHECK(clock_intermediate == clock_intermediate);
    CHECK_FALSE(clock_intermediate == clock_large);
    CHECK_FALSE(clock_intermediate == clock_small);

    // <=
    CHECK_FALSE(clock_intermediate <= clock_small);
    CHECK(clock_small <= clock_intermediate);
    CHECK_FALSE(clock_large <= clock_intermediate);
    CHECK(clock_intermediate <= clock_intermediate);

    // >=
    CHECK(clock_intermediate >= clock_intermediate);
    CHECK(clock_intermediate >= clock_small);
    CHECK_FALSE(clock_small >= clock_intermediate);
    CHECK(clock_large >= clock_intermediate);

    // !=
    CHECK_FALSE(clock_intermediate != clock_intermediate);
    CHECK(clock_intermediate != clock_large);
}

TEST_CASE("Counter Clock", "[counter_clock]"){
    CounterClock cc{};
}