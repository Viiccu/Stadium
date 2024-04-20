#ifndef STADIUMPLAN_H
#define STADIUMPLAN_H

#include <map>
#include <string>
#include "Seat.h"

using namespace std;

class StadiumPlan
{
private:
	map<string, Seat> sectionA;
	map<string, Seat> sectionB;
	map<string, Seat> sectionC;
	map<string, Seat> sectionD;
	map<string, Seat> sectionE;

public:
	StadiumPlan();

};

#endif // !STADIUMPLAN_H
