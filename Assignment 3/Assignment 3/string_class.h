#pragma once

/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Ryan Milrad
TOTAL POINTS:  25
DUE DATE:  09/22/2020
COURSE:  COP 3530
Assignment Name:  Assignment#3
Professor:  Dr. Bullard

Description:  header file for string class
******************************************************************************************************************************************************/


#include <iomanip>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#ifndef STRING_CLASS_H
#define STRING_CLASS_H

//string class declaration
class string_class {
public:
	string_class(); //default constructor
	string_class(string current); //explicit value constructor
	bool palindrome(); //palindrome function that returns bool value correlating to it being or not being palindromic
	void replace_all(const string old_substring, const string new_substring); //function that searches for a  A-string within a string and replaces A-string with B-string. 
	friend ostream& operator<<(ostream& out, const string_class& current); //overload >> operator as a friend function
private:
	string current_string; //private variable string
};

#endif STRING_CLASS_H