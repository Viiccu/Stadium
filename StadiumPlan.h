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
	// ctor
	StadiumPlan();

	// methods
	void DisplayStadium();
	bool BookSeat(string&);
	bool CancelBooking(string&);
	bool CheckIfStadiumFull();

private:
	// methods
	void DisplayRow(map<string, Seat>&, char, char);
	string FindNearestSeat(string);
	bool FindAndBookSeat(map<string, Seat>&, string&);
	string FindSeat(map<string, Seat>&, string&, char, int);
	bool CancelSeat(map<string, Seat>&, string&);

	// better methods
	string FindNearestSeatBetter(string);
	string FindSeatBetter(map<string, Seat>&, string&, char, int);
};

#endif // !STADIUMPLAN_H
