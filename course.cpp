#include "course.h"
#include "student.h"
#include <iostream>

Course::Course(string CRN, string dep, string course_num, string course_name)
{
    this->CRN = CRN;
    this->dep = dep;
    this->course_num = course_num;
    this->course_name = course_name;
    this->students = nullptr;
    arraySize = 10;
    num_students = 0;
    students = new Student *[100];
}

Course::Course()
{
    this->CRN = "";
    this->dep = "";
    this->course_num = "";
    this->course_name = "";
    this->students = nullptr;
    this->arraySize = 10;
    this->num_students = 0;
    this->students = new Student *[arraySize];
}

string Course::getCRN() const
{
    return CRN;
}

string Course::getDEP() const
{
    return dep;
}

string Course::getNUM() const
{
    return course_num;
}

string Course::getNAME() const
{
    return course_name;
}

void Course::addStudent(Student* student)
{
    if (num_students >= arraySize)
    {
        arraySize *= 2;
        Student **newStudents = new Student *[arraySize];
        for (int i = 0; i < num_students; i++)
        {
            newStudents[i] = students[i];
        }
        delete[] students;
        students = newStudents;
    }
    students[num_students] = student;
    num_students++;
}

void Course::removeStudent(Student* student)
{
    int index = -1;
    for (int i = 0; i < num_students; i++)
    {
        if (students[i] == student)
        {
            index = i;
            break;
        }
    }

    if (index != -1)
    {
        for (int i = index; i < num_students - 1; i++)
        {
            students[i] = students[i+1];
        }
        students[num_students-1] = nullptr;
        num_students--;
    }
}


Student **Course::getStudents() const
{
    return students;
}

int Course::getNumStudents() const
{
    return num_students;
}

void Course::printCourse(const Course &course)
{
    cout << course.getCRN() << " " << course.getDEP() << " " << course.getNUM() << " " << course.getNAME() << endl;
}

Course::~Course()
{
    
}

Course& Course::operator=(const Course& other) {
    if (this != &other) {
        CRN = other.CRN;
        dep = other.dep;
        course_num = other.course_num;
        course_name = other.course_name;
        num_students = other.num_students;
        arraySize = other.arraySize;
        delete[] students;
        students = new Student*[arraySize];
        for (int i = 0; i < num_students; i++) {
            students[i] = new Student(*other.students[i]);
        }
    }
    return *this;
}
