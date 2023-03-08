#include <iostream>
#include <vector>
#include <sstream>
#include <regex>
#include "drop.h"

const regex Drop::DropCourse("^drop B\\d{8} \\d{6}$");

void Drop::execute(const string* array)
{
    cout << "Success: removed student " << array[1] << " from course " << array[2] << endl;
}

void Drop::ill_CRN()
{
    cout << "Input Error: illegal CRN" << endl;
}

void Drop::ill_Bnum()
{
    cout << "Input Error: illegal B Number" << endl;
}

void Drop::no_CRN()
{
    cout << "Error: Course Does Not Exists" << endl;
}

void Drop::no_Bnum()
{
    cout << "Error: Student Does Not Exists" << endl;
}

void Drop::NotEnrolled(const string* array)
{
    cout << "Fail: cannot drop, student " << array[1] << " not enrolled in course " << array[2] << endl;
}
