#ifndef STUDENT_H
#define STUDENT_H

#include <string>

using namespace std;

class Student
{
private:
    string bnumber;
    string userid;
    string first;
    string last;
    string* enrolled_CRNs;
    int num_CRNs;

public:
    Student(string bnumber, string userid, string first, string last);

    Student();

    ~Student();

    string getBnum() const;

    string getName() const;

    void addCRN(string crn);

    void removeCRN(string crn);

    string* getCRNs() const;

    int getCRNsSize() const;
};

#endif
