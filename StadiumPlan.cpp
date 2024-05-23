#include "StadiumPlan.h"
#include <vector>
#include <algorithm>


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

string StadiumPlan::FindSeat(map<string, Seat> &section, string& seat, char maxLetter, int maxNum)
{
	char row = seat[1];
	int column = atoi(&seat[2]);

	for (int i = 1; i < 18; i++)
	{
		for (int j = -i; j <= i; j++)
		{
			if ((row + j) > maxLetter || (row + j) < 'A') continue;

			for (int k = -i; k <= i; k++)
			{
				if (column + k > maxNum || column + k < 1) continue;

				string key = "";
				string aux = "";
				aux = (row + j);
				key += seat[0] + aux + ((((column + k) / 10) > 0) ? "" : "0") + to_string(column + k);

				if (section.find(key) != section.end() && section.find(key)->second.IsAvailable())
					return section.find(key)->second.GetSeat();
			}
		}
	}

	return "";
}

string StadiumPlan::FindNearestSeat(string seat)
{
	switch (seat[0])
	{
	case 'A':
		return FindSeat(sectionA, seat, 'A', 10);
	case 'B': 
		return FindSeat(sectionB, seat, 'E', 18);
	case 'C':
		return FindSeat(sectionC, seat, 'E', 18);
	case 'D':
		return FindSeat(sectionD, seat, 'L', 4);
	case 'E': 
		return FindSeat(sectionE, seat, 'L', 4);

	default: cout << "\n\nERROR 404 - Not Found: Such section does not exist! \n\n"; break;
	}

	return "";
}

string StadiumPlan::MakeString(char sectionId, char row, int number) 
{
	string key = "";
	string aux = "";
	key = sectionId;
	aux = row;
	key += aux + ((number > 9) ? "" : "0") + to_string(number);

	return key;
}

string StadiumPlan::FindSeatBetter(map<string, Seat>& section, string& seat, char maxLetter, int maxNum)
{
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if ((section.find(MakeString('B', seat[1] - j, section.at(seat).GetNumber() - i)) != section.end())
				&& (section.at(MakeString('B', seat[1] - j, section.at(seat).GetNumber() - i)).IsAvailable()))
				return section.at(MakeString('B', seat[1] - j, section.at(seat).GetNumber() - i)).GetSeat();

			if ((section.find(MakeString('B', seat[1] + j, section.at(seat).GetNumber() - i)) != section.end())
				&& section.at(MakeString('B', seat[1] + j, section.at(seat).GetNumber() - i)).IsAvailable())
				return section.at(MakeString('B', seat[1] + j, section.at(seat).GetNumber() - i)).GetSeat();
			
			if ((section.find(MakeString('B', seat[1] - j, section.at(seat).GetNumber() + i)) != section.end())
				&& section.at(MakeString('B', seat[1] - j, section.at(seat).GetNumber() + i)).IsAvailable())
				return section.at(MakeString('B', seat[1] - j, section.at(seat).GetNumber() + i)).GetSeat();
			
			if ((section.find(MakeString('B', seat[1] + j, section.at(seat).GetNumber() + i)) != section.end())
				&& section.at(MakeString('B', seat[1] + j, section.at(seat).GetNumber() + i)).IsAvailable())
				return section.at(MakeString('B', seat[1] + j, section.at(seat).GetNumber() + i)).GetSeat();

			if ((section.find(MakeString('B', seat[1] - i, section.at(seat).GetNumber() - j)) != section.end())
				&& section.at(MakeString('B', seat[1] - i, section.at(seat).GetNumber() - j)).IsAvailable())
				return section.at(MakeString('B', seat[1] - i, section.at(seat).GetNumber() - j)).GetSeat();
			
			if ((section.find(MakeString('B', seat[1] - i, section.at(seat).GetNumber() + j)) != section.end())
				&& section.at(MakeString('B', seat[1] - i, section.at(seat).GetNumber() + j)).IsAvailable())
				return section.at(MakeString('B', seat[1] - i, section.at(seat).GetNumber() + j)).GetSeat();
			
			if ((section.find(MakeString('B', seat[1] + i, section.at(seat).GetNumber() - j)) != section.end())
				&& section.at(MakeString('B', seat[1] + i, section.at(seat).GetNumber() - j)).IsAvailable())
				return section.at(MakeString('B', seat[1] + i, section.at(seat).GetNumber() - j)).GetSeat();
																						  
			if ((section.find(MakeString('B', seat[1] + i, section.at(seat).GetNumber() + j)) != section.end())
				&& section.at(MakeString('B', seat[1] + i, section.at(seat).GetNumber() + j)).IsAvailable())
				return section.at(MakeString('B', seat[1] + i, section.at(seat).GetNumber() + j)).GetSeat();
		}
	}

	return "";
}

string StadiumPlan::FindNearestSeatBetter(string seat)
{
	switch (seat[0])
	{
	case 'A':
		return FindSeatBetter(sectionA, seat, 'A', 10);
	case 'B':
		return FindSeatBetter(sectionB, seat, 'E', 18);
	case 'C':
		return FindSeatBetter(sectionC, seat, 'E', 18);
	case 'D':
		return FindSeatBetter(sectionD, seat, 'L', 4);
	case 'E':
		return FindSeatBetter(sectionE, seat, 'L', 4);

	default: std::cout << "\n\nERROR 404 - Not Found: Such section does not exist! \n\n"; break;
	}

	return "";
}

void StadiumPlan::DisplayStadium()
{
	for (int i = 1; i < 26; i++)
		cout << " ";

	for (int i = 1; i < 11; i++)
	{
		string key = "";
		key += "AA";
		key += (i == 10) ? "" : "0";
		key += to_string(i);
		cout << sectionA.find(key)->second << " ";
	}

	cout << "\n\n     ";
	DisplayRow(sectionB, 'A', 'B');
	cout << '\n';

	for (char c = 'A'; c <= 'L'; c++)
	{
		DisplayRow(sectionD, c, 'D');
		if (c <= 'D') DisplayRow(sectionB, c + 1, 'B');
		if (c > 'D' && c < 'I')
		{
			for (int i = 0; i < 55; i++) cout << " ";
		}
		if (c >= 'I') DisplayRow(sectionC, c - 8, 'C');
		DisplayRow(sectionE, c, 'E');
		cout << "\n";
	}

	cout << "     ";
	DisplayRow(sectionC, 'E', 'C');
	cout << "\n\n";
}

void StadiumPlan::DisplayRow(map<string, Seat> &section, char row, char sectionInitial)
{
	for (int i = 1; i <= 18; i++)
	{
		string key = "";
		key += sectionInitial;
		key += row;
		key += (i >= 10) ? "" : "0";
		key += to_string(i);

		auto seat = section.find(key);
		if (seat != section.end())
		{
			cout << seat->second << " ";
		}
		else if (sectionInitial == 'D')
		{
			cout << "     ";
			return;
		}
	}
			cout << "     ";
}

bool StadiumPlan::BookSeat(string& seat)
{
	transform(seat.begin(), seat.end(), seat.begin(), ::toupper);

	switch (seat[0])
	{
	case 'A':
		return FindAndBookSeat(sectionA, seat); break;
	case 'B':
		return FindAndBookSeat(sectionB, seat); break;
	case 'C':
		return FindAndBookSeat(sectionC, seat); break;
	case 'D':
		return FindAndBookSeat(sectionD, seat); break;
	case 'E':
		return FindAndBookSeat(sectionE, seat); break;
	
	default:
		cout << "ERROR 404: invalid seat number!\n";
		break;
	}

	return false;
}

bool StadiumPlan::FindAndBookSeat(map<string, Seat> &section, string& seatKey)
{
	auto seat = section.find(seatKey);
	if (seat != section.end())
	{
		if (seat->second.IsAvailable())
		{
			seat->second.Book();
			cout << "Seat booked!\n";
			return true;
		}
		else
		{
			if (this->FindNearestSeatBetter(seat->second.GetSeat()) != "")
			{
				cout << "Seat '" << seat->second.GetSeat() 
					<< "' is not available (closest is '" 
					<< this->FindNearestSeatBetter(seat->second.GetSeat()) 
					<< "')\n";
			}
			else if(!CheckIfStadiumFull())
			{
				cout << "There are no more available seats in this section!\n";
			}
			else 
			{
				cout << "There are no more available seats for this game!\n";
				return true;
			}
		}
	}
	else
	{
		cout << "ERROR 404: invalid seat number!\n";
	}

	return false;
}

bool StadiumPlan::CancelSeat(map<string, Seat>& section, string& seatKey)
{
	auto seat = section.find(seatKey);
	if (seat != section.end())
	{
		seat->second.CancelBooking();
		return true;
	}
	else
	{
		cout << "ERROR: This seat does not exist!\n\n";
	}

	return false;
}

bool StadiumPlan::CancelBooking(string& seat)
{
	transform(seat.begin(), seat.end(), seat.begin(), ::toupper);

	switch (seat[0])
	{
	case 'A': 
		return CancelSeat(sectionA, seat); 
	case 'B': 
		return CancelSeat(sectionB, seat); 
	case 'C': 
		return CancelSeat(sectionC, seat); 
	case 'D': 
		return CancelSeat(sectionD, seat); 
	case 'E': 
		return CancelSeat(sectionE, seat); 

	default: 
		break;
	}

	return false;
}

bool StadiumPlan::CheckIfStadiumFull() 
{
	for (auto it : this->sectionA)
		if (it.second.IsAvailable()) return false;
	for (auto it : this->sectionB)
		if (it.second.IsAvailable()) return false;
	for (auto it : this->sectionC)
		if (it.second.IsAvailable()) return false;
	for (auto it : this->sectionD)
		if (it.second.IsAvailable()) return false;
	for (auto it : this->sectionE)
		if (it.second.IsAvailable()) return false;
	
	return true;
}

