#include <iostream>
#include "build.h"
using namespace std;

const regex Build::buildCourse("^build\\s+\\d{6}\\s+[A-Z]{2,4}\\s+[1-6]\\d{2}\\s+.+$");

void Build::execute(const string* array, int size)
{
    cout << "Success: built course " << array[2] << array[3] << " (CRN: " << array[1] << ") : ";
    for (int i = 4; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Build::CRN_Exists(const string* array, int size)
{
    cout << "Fail: cannot build course " << array[2] << array[3] << " (CRN: " << array[1] << ") : CRN exists" << endl;
}
