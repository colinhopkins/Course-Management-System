#ifndef CANCEL_H
#define CANCEL_H

#include <vector>
#include <regex>
using namespace std;

class Cancel
{
public:
    static const regex cancelCourse;
    static void execute(const string* array);
    static void CRN_dne();
    static void extra_arg();
    static void ill_CRN();
};

#endif
