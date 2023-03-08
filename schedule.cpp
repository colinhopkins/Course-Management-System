#include "schedule.h"
#include <iostream>
using namespace std;


const regex Schedule::StudentSchedule("^schedule B\\d{8}$");

void Schedule::ill_BNUM()
{
    cout << "Input Error: illegal B Number" << endl;
}

void Schedule::no_BNUM()
{
    cout << "Error: B Number Does Not Exists" << endl;
}

void Schedule::no_Courses()
{
    cout << "No Courses Enrolled" << endl;
}
