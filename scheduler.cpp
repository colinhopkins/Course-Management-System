#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <regex>
using namespace std;
#include "build.h"
#include "course.h"
#include "cancel.h"
#include "student.h"
#include "enroll.h"
#include "add.h"
#include "drop.h"
#include "roster.h"
#include "schedule.h"

int main()
{

    string input_str = "";

    int size = 0;

    string *array = new string[size];

    int size1 = 0;

    Course *total_courses = new Course[size1];

    int size2 = 0;

    Student *total_students = new Student[size2];

    cout << "Enter Command: \n";
    while (getline(cin, input_str))
    {
        stringstream ss(input_str);
        string word;
        int index = 0;
        while (ss >> word)
        {
            if (index >= size)
            {
                size += 10;
                string *new_array = new string[size];
                for (int i = 0; i < index; i++)
                {
                    new_array[i] = array[i];
                }
                delete[] array;
                array = new_array;
            }

            array[index++] = word;
        }

        if (array[0] == "quit")
        {
            break;
        }
        else if (array[0] == "build")
        {
            if (index < 5)
            {
                cout << "Input Error: too few arguments" << endl;
            }
            else if (!regex_match(array[1], regex("^\\d{6}$")))
            {
                cout << "Input Error: illegal CRN" << endl;
            }
            else if (!regex_match(array[2], regex("^[A-Z]{2,4}$")))
            {
                cout << "Input Error: illegal department" << endl;
            }
            else if (!regex_match(array[3], regex("^[1-6]\\d{2}$")))
            {
                cout << "Input Error: illegal course number" << endl;
            }
            else if (regex_match(input_str, Build::buildCourse))
            {
                bool courseExists = false;
                for (int i = 0; i < size1; i++)
                {
                    if (total_courses[i].getCRN() == array[1])
                    {
                        Build::CRN_Exists(array, size);
                        courseExists = true;
                        break;
                    }
                }
                if (!courseExists)
                {
                    Build::execute(array, size);

                    stringstream string_stream;
                    for (int i = 4; i < index; i++)
                    {
                        string_stream << array[i];
                        if (i < index - 1)
                        {
                            string_stream << " ";
                        }
                    }
                    string course_name = string_stream.str();

                    Course *new_courses = new Course[size1 + 1];
                    for (int i = 0; i < size1; i++)
                    {
                        new_courses[i] = total_courses[i];
                    }
                    new_courses[size1] = Course(array[1], array[2], array[3], course_name);
                    delete[] total_courses;
                    total_courses = new_courses;
                    delete[] new_courses;
                    size1++;
                }
            }
        }

        else if (array[0] == "cancel")
        {
            if (index > 2)
            {
                Cancel::extra_arg();
            }

            if (!regex_match(array[1], regex("\\d{6}")))
            {
                Cancel::ill_CRN();
            }
            else
            {
                bool courseFound = false;
                for (int i = 0; i < size1; ++i)
                {
                    if (total_courses[i].getCRN() == array[1])
                    {
                        for (int j = i; j < size1 - 1; ++j)
                        {
                            total_courses[j] = total_courses[j + 1];
                        }
                        size1--;
                        courseFound = true;
                        break;
                    }
                }
                if (courseFound)
                {
                    Cancel::execute(array);
                }
                else
                {
                    Cancel::CRN_dne();
                }
            }
        }
        else if (array[0] == "enroll")
        {
            if (index < 5)
            {
                cout << "Input Error: too few arguments" << endl;
            }

            if (regex_match(input_str, Enroll::enrollStudent))
            {
                bool studentExists = false;
                for (int i = 0; i < size2; i++)
                {
                    if (total_students[i].getBnum() == array[1])
                    {
                        Enroll::CRN_Exists();
                        studentExists = true;
                        break;
                    }
                }
                if (!studentExists)
                {
                    Enroll::execute(array);

                    Student new_student(array[1], array[2], array[3], array[4]);
                    Student *new_students = new Student[size2 + 1];
                    for (int i = 0; i < size2; i++)
                    {
                        new_students[i] = total_students[i];
                    }
                    total_students = new_students;
                    total_students[size2++] = new_student;
                }
            }
        }

        else if (array[0] == "add")
        {
            if (!regex_match(array[1], regex("B\\d{8}")))
            {
                Add::ill_Bnum();
            }
            else if (!regex_match(array[2], regex("\\d{6}")))
            {
                Add::ill_CRN();
            }

            if (regex_match(input_str, Add::AddCourse))
            {
                bool studentEnrolled = false;
                bool bnumExists = false;
                bool crnExists = false;
                string course = input_str;
                for (int i = 0; i < size1; i++)
                {
                    if (total_courses[i].getCRN() == array[2])
                    {
                        crnExists = true;
                        break;
                    }
                }
                if (!crnExists)
                {
                    Add::no_CRN();
                }
                for (int i = 0; i < size2; i++)
                {
                    if (total_students[i].getBnum() == array[1])
                    {
                        bnumExists = true;
                        break;
                    }
                }
                if (!bnumExists)
                {
                    Add::no_Bnum();
                }
                if (crnExists && bnumExists)
                {
                    bool alreadyEnrolled = false;
                    for (int i = 0; i < size1; i++)
                    {
                        if (total_courses[i].getCRN() == array[2])
                        {
                            for (int j = 0; j < total_courses[i].getNumStudents(); j++)
                            {
                                if (total_courses[i].getStudents()[j]->getBnum() == array[1])
                                {
                                    alreadyEnrolled = true;
                                    break;
                                }
                            }
                            if (alreadyEnrolled)
                            {
                                Add::alreadyEnrolled(array);
                            }
                            else
                            {
                                for (int k = 0; k < size2; k++)
                                {
                                    if (total_students[k].getBnum() == array[1])
                                    {
                                        total_courses[i].addStudent(&total_students[k]);
                                        total_students[k].addCRN(total_courses[i].getCRN());
                                        Add::execute(array);
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }

        else if (array[0] == "drop")
        {

            if (!regex_match(array[1], regex("B\\d{8}")))
            {
                Add::ill_Bnum();
            }
            else if (!regex_match(array[2], regex("\\d{6}")))
            {
                Add::ill_CRN();
            }

            if (regex_match(input_str, Drop::DropCourse))
            {
                bool studentEnrolled = false;
                bool bnumExists = false;
                bool crnExists = false;
                string course = input_str;
                for (int i = 0; i < size1; i++)
                {
                    if (total_courses[i].getCRN() == array[2])
                    {
                        crnExists = true;
                        break;
                    }
                }
                if (!crnExists)
                {
                    Drop::no_CRN();
                }
                for (int i = 0; i < size2; i++)
                {
                    if (total_students[i].getBnum() == array[1])
                    {
                        bnumExists = true;
                        break;
                    }
                }
                if (!bnumExists)
                {
                    Drop::no_Bnum();
                }
                if (crnExists && bnumExists)
                {
                    bool NotEnrolled = true;
                    for (int i = 0; i < size1; i++)
                    {
                        if (total_courses[i].getCRN() == array[2])
                        {
                            for (int j = 0; j < total_courses[i].getNumStudents(); j++)
                            {
                                if (total_courses[i].getStudents()[j]->getBnum() == array[1])
                                {
                                    NotEnrolled = false;
                                    break;
                                }
                            }
                            if (NotEnrolled)
                            {
                                Drop::NotEnrolled(array);
                            }
                            else
                            {
                                for (int k = 0; k < size2; k++)
                                {
                                    if (total_students[k].getBnum() == array[1])
                                    {
                                        total_courses[i].removeStudent(&total_students[k]);
                                        total_students[k].removeCRN(total_courses[i].getCRN());
                                        Drop::execute(array);
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
        }
        else if (array[0] == "roster")
        {

            if (!regex_match(input_str, Roster::RosterList))
            {
                Roster::ill_CRN();
            }
            else
            {
                bool crnExists = false;
                for (int i = 0; i < size1; i++)
                {
                    if (total_courses[i].getCRN() == array[1])
                    {
                        crnExists = true;
                        cout << "CRN: " << total_courses[i].getCRN() << endl;
                        cout << "Students: " << total_courses[i].getNumStudents() << endl;
                        for (int j = 0; j < total_courses[i].getNumStudents(); j++)
                        {
                            Student s = *(total_courses[i].getStudents()[j]);
                            cout << s.getBnum() << " " << s.getName() << endl;
                        }
                        break;
                    }
                }
                if (!crnExists)
                {
                    Roster::no_CRN();
                }
            }
        }

        else if (array[0] == "schedule")
        {
            if (!regex_match(input_str, Schedule::StudentSchedule))
            {
                Schedule::ill_BNUM();
            }
            else
            {
                bool studentExists = false;
                for (int i = 0; i < size2; i++)
                {
                    if (total_students[i].getBnum() == array[1])
                    {
                        studentExists = true;
                        if (total_students[i].getCRNs() == nullptr || total_students[i].getCRNsSize() == 0)
                        {
                            Schedule::no_Courses();
                        }
                        else
                        {
                            cout << "Student: " << total_students[i].getBnum() << ": " << total_students[i].getName() << endl;
                            for (int j = 0; j < total_students[i].getCRNsSize(); j++)
                            {
                                for (int k = 0; k < size1; k++)
                                {
                                    if (total_courses[k].getCRN() == total_students[i].getCRNs()[j])
                                    {
                                        total_courses[k].printCourse(total_courses[k]);
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    }
                }
                if (!studentExists)
                {
                    Schedule::no_BNUM();
                }
            }
        }

        else
        {
            cout << "Command not recognized, please try again." << endl;
        }
    }

    delete[] array;
    delete[] total_courses;
    delete[] total_students;
}
