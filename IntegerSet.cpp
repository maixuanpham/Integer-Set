/*  	Program:		MSVS 2012/2015
    	Author:			Mai Pham
    	Class:			CSCI 140
    	Date:			05/09/2017
    	Description:		Project 3: Integer Set
    	I certify that the code below is my own work.
	Exception(s): N/A
*/

// Implementation File (Member Functions)
#include "IntegerSet.h"
#include <iostream>
using namespace std;

IntegerSet::IntegerSet()
{
	for (int i = 0; i < SIZE; i++)
		set[i] = false;
}
IntegerSet::IntegerSet(int m)
{
	for (int i = 0; i < SIZE; i++)
		set[i] = false;
	if (m >= 0 && m < SIZE)
		set[m] = true;
}
IntegerSet::IntegerSet(const int arr[], int n)
{
	for (int i = 0; i < SIZE; i++)
		set[i] = false;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= 0 && arr[i] < SIZE)
			set[arr[i]] = true;
	}
}
IntegerSet IntegerSet::operator+(const IntegerSet &s) const
{
	IntegerSet a;
	for (int i = 0; i < SIZE; i++)
	{
		if (set[i] || s.set[i])
			a.set[i] = true;
	}
	return a;
}
IntegerSet IntegerSet::operator*(const IntegerSet &s) const
{
	IntegerSet a;
	for (int i = 0; i < SIZE; i++)
	{
		if (set[i] && s.set[i])
			a.set[i] = true;
	}
	return a;
}
int IntegerSet::elements(int arr[]) const
{
	int count = 0;
	for (int i = 0; i < SIZE; i++)
	{	if (set[i] == true)
		{
			arr[count] = i;
			count++;
		}
	}
	return count;
}
bool IntegerSet::isElem(int m) const
{
	if (set[m])
		return true;
	else
		return false;
}
IntegerSet &IntegerSet::insert(int a)
{
	if (a >= 0 && a < SIZE)
		set[a] = true;
	return *this;
}
IntegerSet &IntegerSet::remove(int a)
{
	if (a >= 0 && a < SIZE)
		set[a] = false;
	return *this;
}
istream &operator>>(istream &in, IntegerSet &s)
{
	int element;

	for (int i = 0; i < SIZE; i++)
		s.set[i] = false;
	
	in >> element;
	while (element != -1)
	{	
		if (element >= 0 && element < SIZE)
			s.set[element] = true;
		in >> element;
	}
	return in;
}
ostream &operator<<(ostream &out, const IntegerSet &s)
{
	out << "{";
	for (int i = 0; i < SIZE; i++)
	{
		if (s.set[i])
			out << i << " ";
	}
	out << "}";
	return out;
}
bool IntegerSet::operator<=(const IntegerSet &s) const
{
	bool subset = false;
	for (int i = 0; i < SIZE; i++)
	{
		if (set[i])
			if (s.set[i])
				subset = true;
			else
				subset = false;
	}
	return subset;
}
bool IntegerSet::operator>=(const IntegerSet &s) const
{
	bool subset = false;
	for (int i = 0; i < SIZE; i++)
	{
		if (s.set[i])
			if (set[i])
				subset = true;
			else
				subset = false;
	}
	return subset;
}

