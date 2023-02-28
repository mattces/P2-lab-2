#include <iostream>
using namespace std;
#include "fraction.h"

void Fraction::read() {
  cin >> *this;
}

void Fraction::write() const {
  cout << *this;
}

Fraction::Fraction(int a, int b) {
  numerator = a;
  denominator = b;

  shorten();
}
void Fraction::setNumerator(int numerator) {
  this->numerator = numerator;
  shorten(); 
}
void Fraction::setDenominator(int denominator) {
  this->denominator = denominator;
  shorten(); 
}

int gcd(int a, int b) {
  while(b != 0) {
    int rest = a % b;
    a = b;
    b = rest;
  }
  return a;
}

Fraction add(Fraction a, Fraction b) {
  Fraction newFraction;
  newFraction.numerator = 
    a.numerator * b.denominator 
    + b.numerator*a.denominator;
  newFraction.denominator = 
    a.denominator*b.denominator;

  newFraction.shorten();
  return newFraction;
}

void Fraction::shorten() {
  int common = gcd(numerator, denominator);

  numerator/=common;
  denominator/=common;

  if (denominator < 0) {
    numerator*=-1;
    denominator*=-1;
  }
}

ostream& operator<<(ostream& out, Fraction u) {
  if (u.numerator == 0 || u.denominator == 1) 
    out << u.numerator << endl;
  else
    out << u.numerator << "/" << u.denominator << endl;

  return out;
};
istream& operator>>(istream& in, Fraction& u) {
  in >> u.numerator >> u.denominator;
  u.shorten();

  return in;
};