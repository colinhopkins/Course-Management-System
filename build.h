#ifndef BUILD_H
#define BUILD_H

#include <vector>
#include <regex>
using namespace std;

class Build
{
public:
    static const regex buildCourse;

    static void execute(const string* array, int size);

    static void CRN_Exists(const string* array, int size);
};

#endif
