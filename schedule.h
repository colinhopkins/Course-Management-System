#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <regex>
using namespace std;

class Schedule
{
public:
    static const regex StudentSchedule;
    static void ill_BNUM();
    static void no_BNUM();
    static void no_Courses();
};

#endif

