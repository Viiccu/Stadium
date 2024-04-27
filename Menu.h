#ifndef MENU_H
#define MENU_H

#include "StadiumPlan.h"
#include <map>

class Menu
{
private:
	StadiumPlan stadium;
	map<char, int> SectionPrices{
		{'A', 200},
		{'B', 60},
		{'C', 60},
		{'D', 20},
		{'E', 20}
	};

	// methods
	void DisplayStadium();
	void BookSeat();
	void CancelBooking();

public:
	void DisplayMenu();
};
#endif 

