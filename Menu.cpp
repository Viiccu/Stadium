#include "Menu.h"
#include <conio.h>

void Menu::DisplayMenu() 
{
    char c = 'A';
    do {
        system("cls");
        cout << "------------------------------------\n";
        cout << "Norlanding Icewinders Booking System\n";
        cout << "------------------------------------\n";
        cout << "P: Print stadium layout\nB: Book seat\nC: Cancel booking\nX: Exit\n";
        cout << "------------------------------------\n";
        cout << "-- Choice -> ";
        cin >> c;

        switch (c)
        {
        case 'p':
        case 'P': this->DisplayStadium();
            break;
        case 'b':
        case 'B': this->BookSeat();
            break;
        case 'c':
        case 'C': this->CancelBooking();
            break;
        case 'x':
        case 'X':
            cout << "App ended.";
            return;

        default:
            break;
        }
    } while (true);
}

void Menu::DisplayStadium()
{
    system("cls");
    cout << "-- Choice -> P\n\n";
	this->stadium.DisplayStadium();
    _getch();
}

bool is_number(const string& s)
{
    return !s.empty() && std::find_if(s.begin(),
        s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

void Menu::BookSeat()
{
	system("cls");
    stadium.DisplayStadium();
    cout << "\n-- Choice -> B\n";
	int numOfSeats;
    int cost = 0;
	string numOfSeatsAsString;

    do {
	    cout << "Enter number of seats to book: ";
	    cin >> numOfSeatsAsString;
    } while (!is_number(numOfSeatsAsString));

    numOfSeats = stoi(numOfSeatsAsString);

	for (int i = 0; i < numOfSeats; i++)
	{
		string seat;
		do {
			cout << "Enter seat number: ";
			cin >> seat;
		} while (!stadium.BookSeat(seat));
        cost += SectionPrices.find(seat[0])->second;
	}

    cout << "\nFor the " << numOfSeats << " booked, the cost is: " << cost << "$\n";
    _getch();
}

void Menu::CancelBooking()
{
    system("cls");
    
    string seat;
    do {
        
        cout << "Input seat number to cancel: ";
        cin >> seat;

    } while (!this->stadium.CancelBooking(seat));
    cout << "Seat canceled";
    _getch();
}