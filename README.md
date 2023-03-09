# Course Management System in C++

This program is a course management system that allows users to build and manage courses, enroll and drop students, and view rosters and schedules.

## Usage

In a loop, the program accepts the following commands, with the following interface:

### build <crn> <department> <number> <name>
The user enters build to make a new course in the program.

The <crn> must be a legal CRN, which is defined as a 6 digit number.
The <department> must be a 2-4 character code, all caps.
The <number> must be a 3 digit number between 100 and 700.
The <name> can be any string, no restrictions, and may include whitespace.
Example:


build 123456 CS 240 Data Structures and Algorithms
Success: built course CS240 (CRN: 123456): Data Structures and Algorithms
  
### cancel <crn>
The user enters cancel to remove a course from the program.

The <crn> must be a legal CRN, which is defined as a 6 digit number.
Example:

cancel 123456
Success: cancelled course 123456
  
### enroll <bnumber> <userid> <first> <last>
The user enters enroll to create a new student in the program.

The <bnumber> must be a valid B Number, namely a capital B followed by exactly 8 digits.
The <userid> must begin with a letter and contain only letters and digits.
The <first> name may be any string, separated only by whitespace from the <userid> and <last> name.
The <last> name may be any string and may include whitespace.
Example:

enroll B12345678 jdoe Jane Doe
Success: enrolled student B123456789 (jdoe) Doe, Jane
  
### add <bnumber> <crn>
The user enters add to put a student into a course.

The <bnumber> must be a valid B Number.
The <crn> must be a legal CRN.
Example:

add B12345678 987654
Success: added student B12345678 into course 987654
  
### drop <bnumber> <crn>
The user enters drop to remove a student from a course.

The <bnumber> must be a valid B Number.
The <crn> must be a legal CRN.
Example:

drop B12345678 987654
Success: removed student B12345678 from course 987654
  
### roster <crn>
The user enters roster to view the roster for a course.

The <crn> must be a legal CRN.
Example:

roster 555333
CRN: 555333
Students: 4
B11122233 Joe Biden
B77712123 Kamala Harris
B99887766 Elon Musk
B23454321 Greta Thunberg
  
### schedule <bnumber>
The user enters schedule to display the schedule for a student.

The <bnumber> must be a valid B Number.
Example:

schedule B11122233
Student: B11122233: Joe Biden
123456 CS 240 Data Structures and Algorithms
654321 PLSC 101 Intro to American Politics
111222 BW 555 Advanced Basket Weaving
  
### quit
The user enters quit
