#pragma once
#include <iostream>
using namespace std;

struct Fraction
{
	Fraction() {};
	Fraction(int, int);

	int numerator;
	void setNumerator(int); 
	int denominator;
	void setDenominator(int);

	void read();
	void write() const;
	void shorten();
};

int gcd(int a, int b);
Fraction add(Fraction a, Fraction b);

ostream& operator<<(ostream& out, Fraction u);
istream& operator>>(istream& in, Fraction& u);
