#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>

using namespace std;

class Seat
{
private:
	char section{ ' ' };
	char row{ ' ' };
	int number{ 0 };
	bool available{ true };

public:
	// ctors
	Seat();
	Seat(const Seat& seat);
	Seat(char, char, int);

	// getters
	char GetSection() const { return this->section; }
	char GetRow() const { return this->row; }
	int GetNumber() const { return this->number; }
	std::string GetSeat() const;

	// setters
	void SetSection(char section);
	void SetRow(char row);
	void SetNumber(int number);

	// overloads
	friend std::ostream& operator<<(std::ostream&, Seat&);

	// methods
	bool IsAvailable() { return this->available; }
	void Book() { this->available = false; }
	void CancelBooking() { this->available = true; }
};

#endif // !SEAT_H

