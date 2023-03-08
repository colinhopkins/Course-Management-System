#include "roster.h"
#include <iostream>
using namespace std;


const regex Roster::RosterList("^roster \\d{6}$");

void Roster::ill_CRN()
{
    cout << "Input Error: illegal CRN" << endl;
}

void Roster::no_CRN()
{
    cout << "Error: CRN Does Not Exists" << endl;
}

