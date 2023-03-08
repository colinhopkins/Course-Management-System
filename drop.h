#ifndef DROP_H
#define DROP_H

#include <vector>
#include <regex>
using namespace std;

class Drop
{
public:
    static const regex DropCourse;
    static void execute(const string* array);
    static void ill_CRN();
    static void ill_Bnum();
    static void no_CRN();
    static void no_Bnum();
    static void NotEnrolled(const string* array);
};

#endif
