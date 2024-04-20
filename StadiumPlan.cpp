#include "StadiumPlan.h"


StadiumPlan::StadiumPlan()
{
	// populate section A
	for (int i = 1; i < 11; i++)
	{
		Seat seat('A', 'A', i);

		sectionA.insert({ seat.GetSeat(), seat});
	}

	// populate section B and C
	{
		char cB = 'A';
		char cC = 'E';
		for (int i = 1, j = 18; i <= 5; i++, j--)
		{
			for (int seatNr = i; seatNr <= j; seatNr++)
			{
				Seat seatB('B', cB, seatNr);
				Seat seatC('C', cC, seatNr);

				sectionB.insert({ seatB.GetSeat(), seatB });
				sectionC.insert({ seatC.GetSeat(), seatC });
			}

			cB++;
			cC--;
		}
	}

	// populate section D and E
	{
		int numD = 1;
		int numE = 4;
		for (char c = 'A', k = 'L'; c <= 'L'; c++, k--)
		{
			for (char i = c; i <= k; i++)
			{
				Seat seatD('D', i, numD);
				Seat seatE('E', i, numE);

				sectionD.insert({ seatD.GetSeat(), seatD });
				sectionE.insert({ seatE.GetSeat(), seatE });
			}
			numD = numD == 4 ? numD : numD + 1;
			numE = numE == 1 ? numE : numE - 1;
		}
	}
}