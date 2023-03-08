#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "add.h"

const regex Add::AddCourse("^add B\\d{8} \\d{6}$");

void Add::execute(const string* array)
{
    cout << "Success: added student " << array[1] << " into course " << array[2] << endl;
}

void Add::ill_CRN()
{
    cout << "Input Error: illegal CRN" << endl;
}

void Add::ill_Bnum()
{
    cout << "Input Error: illegal B Number" << endl;
}

void Add::no_CRN()
{
    cout << "Error: Course Does Not Exists" << endl;
}

void Add::no_Bnum()
{
    cout << "Error: Student Does Not Exists" << endl;
}

void Add::alreadyEnrolled(const string* array)
{
    cout << "Fail: cannot add, student " << array[1] << " already enrolled in course " << array[2] << endl;
}
