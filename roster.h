#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <regex>
using namespace std;

class Roster
{
public:
    static const regex RosterList;
    static void ill_CRN();
    static void no_CRN();
};

#endif
