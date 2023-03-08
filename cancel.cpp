#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "course.h"
#include "cancel.h"
using namespace std;

const regex Cancel::cancelCourse("^cancel\\s+\\d{6}$");

void Cancel::execute(const string* array)
{
    cout << "Success: cancelled course " << array[1] << endl;
}
void Cancel::CRN_dne()
{
    cout << "Fail: cannot cancel course, CRN does not exist" << endl;
}
void Cancel::extra_arg()
{
    cout << "Warning: ignoring extra argument(s)" << endl;
}
void Cancel::ill_CRN()
{
    cout << "Input Error: illegal CRN" << endl;
}
