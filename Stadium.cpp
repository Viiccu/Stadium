#include <iostream>
#include "StadiumPlan.h"

using namespace std;

int main()
{
    StadiumPlan stadium;
    stadium.DisplayStadium();

    stadium.BookSeat("BB07");
    stadium.BookSeat("BB07");
}
