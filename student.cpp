#include "student.h"

Student::Student(string bnumber, string userid, string first, string last)
{
    this->bnumber = bnumber;
    this->userid = userid;
    this->first = first;
    this->last = last;
    enrolled_CRNs = new string[100];
    num_CRNs = 0;
}

Student::Student()
{
    bnumber = "";
    userid = "";
    first = "";
    last = "";
    enrolled_CRNs = new string[100];
    num_CRNs = 0;
}

Student::~Student()
{
}

string Student::getBnum() const
{
    return bnumber;
}

string Student::getName() const
{
    return first + " " + last;
}

void Student::addCRN(string crn)
{
    enrolled_CRNs[num_CRNs++] = crn;
}

void Student::removeCRN(string crn)
{
    for (int i = 0; i < num_CRNs; i++)
    {
        if (enrolled_CRNs[i] == crn)
        {
            for (int j = i; j < num_CRNs - 1; j++)
            {
                enrolled_CRNs[j] = enrolled_CRNs[j + 1];
            }
            num_CRNs--;
            enrolled_CRNs[num_CRNs] = "";
        }
    }
}

string *Student::getCRNs() const
{
    return enrolled_CRNs;
}

int Student::getCRNsSize() const
{
    return num_CRNs;
}
