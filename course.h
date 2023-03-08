#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "student.h"

class Course
{
private:
    string CRN;
    string dep;
    string course_num;
    string course_name;
    Student** students;
    int num_students;
    int arraySize;

public:
    Course(string CRN, string dep, string course_num, string course_name);
    Course();
    ~Course();
    string getCRN() const;
    string getDEP() const;
    string getNUM() const;
    string getNAME() const;

    void addStudent(Student* student);
    void removeStudent(Student* student);

    void printCourse(const Course &course);

    Student** getStudents() const;
    int getNumStudents() const;

    Course& operator=(const Course& other);
};

#endif