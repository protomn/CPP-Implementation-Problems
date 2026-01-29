/*
Problem Statement
Implement an enum class Day with values:
    - Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
Also implement:
    - std::string to_string(Day d);

Constraints:
    - Must use a switch statement.
    - Must handle all enum values (no default case).
    - No arrays, no maps for lookup.
    - Output names must be properly capitalized.
*/

#include <iostream>
#include <string>

enum class Day
{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

std::string to_string_(Day d)
{
    switch(d)
    {
        case Day::Monday: { return "Monday"; }
        case Day::Tuesday: { return "Tuesday"; }
        case Day::Wednesday: { return "Wednesday"; }
        case Day::Thursday: { return "Thursday"; }
        case Day::Friday: { return "Friday"; }
        case Day::Saturday: { return "Saturday"; }
        case Day::Sunday: { return "Sunday"; }
    }

    return "Unknown";
}

int main()
{
    Day today = Day::Friday;
    Day tomorrow = Day::Saturday;

    std::cout << "Today is: " << to_string_(today) << '\n';
    std::cout << "Tomorrow is: " << to_string_(tomorrow) << '\n';

    return 0;
}