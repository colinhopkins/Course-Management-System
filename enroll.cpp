#include <iostream>
#include "enroll.h"
using namespace std;

const regex Enroll::enrollStudent("^enroll [B]\\d{8} [a-zA-Z][a-zA-Z\\d]* [^\\s]+\\s+[^\\s]+$");

void Enroll::execute(const string* array)
{
    cout << "Success: enrolled student " << array[1] << " (" << array[2] << ") " << array[4] << ", " << array[3] << endl;
}

void Enroll::CRN_Exists()
{
    cout << "Fail: cannot enroll student, B Number exists" << endl;
}
