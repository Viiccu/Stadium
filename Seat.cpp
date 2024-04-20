#include "Seat.h"
#include <iomanip>
#include <string>

using namespace std;

Seat::Seat() { }

Seat::Seat(const Seat& seat)
{
	this->section = seat.GetSection();
	this->row = seat.GetRow();
	this->number = seat.GetNumber();
}

Seat::Seat(char section, char row, int number)
{
	this->SetSection(section);
	this->SetRow(row);
	this->SetNumber(number);
}

void Seat::SetSection(char section)
{
	if (section >= 'A' && section <= 'E')
		this->section = section;
	else
		this->section = ' ';
}

void Seat::SetRow(char row)
{
	if (row >= 'A' && row <= 'L')
		this->row = row;
	else
		this->row = ' ';
}

void Seat::SetNumber(int number)
{
	if (number >= 1 && number <= 18)
		this->number = number;
	else
		this->number = 0;
}

string Seat::GetSeat() const
{
	string numAsString = (this->number / 10 > 0) ? 
		to_string(this->GetNumber())
		: "0" + to_string(this->GetNumber());

	string secAsString = ""; 
	secAsString = this->GetSection();
	
	string rowAsString = "";
	rowAsString = this->GetRow();

	return secAsString + rowAsString + numAsString;
}

std::ostream& operator<<(std::ostream& os, Seat& seat)
{
	if (seat.available)
		os << seat.GetSection() << seat.GetRow()
		<< std::setw(2) << std::setfill('0') << seat.GetNumber();
	else
		os << "XXXX";
	
	return os;
}
















