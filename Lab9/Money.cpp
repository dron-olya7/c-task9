#include "pch.h"
#include "Money.h"

Money::Money() { }

Money::Money(long d, int c)
{
	dollars = d;
	cents = c;
}

Money::~Money() { }

// ��������������� ��������� ">"
int Money::operator>(const Money & that)
{
	return dollars > that.dollars || (dollars == that.dollars && cents > that.cents);
}

std::ostream & operator<<(std::ostream & os, Money & that)
{
	// ������ �������� � �����. 
	os << "$" << that.dollars << "." << that.cents;
	return os;
}
