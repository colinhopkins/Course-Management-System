#ifndef ENROLL_H
#define ENROLL_H

#include <vector>
#include <regex>
using namespace std;

class Enroll
{
public:
    static const regex enrollStudent;

    static void execute(const string* array);

    static void CRN_Exists();
};

#endif
