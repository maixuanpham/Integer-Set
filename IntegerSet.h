/*  	Program:		MSVS 2012/2015
    	Author:			Mai Pham
    	Class:			CSCI 140
    	Date:			05/09/2017
    	Description:		Project 3: Integer Set
    	I certify that the code below is my own work.
	Exception(s): N/A
*/

//Header File
#ifndef INTEGERSET_H
#define INTEGERSET_H
#include <iostream>
using namespace std;

const int SIZE = 256;

class IntegerSet
{
private:
	bool set[SIZE];
public:
	IntegerSet();
	IntegerSet(int m);
	IntegerSet(const int array[], int n);
	IntegerSet operator+(const IntegerSet &s) const;
	IntegerSet operator*(const IntegerSet &s) const;
	int elements(int arr[]) const;
	bool isElem(int m) const;
	IntegerSet &insert(int m);
	IntegerSet &remove(int a);
	friend istream &operator>>(istream &in, IntegerSet &s);
	friend ostream &operator<<(ostream &out, const IntegerSet &s);
	bool operator<=(const IntegerSet &s) const;
	bool operator>=(const IntegerSet &s) const;
};
#endif
