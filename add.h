#ifndef ADD_H
#define ADD_H

#include <vector>
#include <regex>
using namespace std;

class Add
{
public:
    static const regex AddCourse;
    static void execute(const string* array);
    static void ill_CRN();
    static void ill_Bnum();
    static void no_CRN();
    static void no_Bnum();
    static void alreadyEnrolled(const string* array);
};

#endif
