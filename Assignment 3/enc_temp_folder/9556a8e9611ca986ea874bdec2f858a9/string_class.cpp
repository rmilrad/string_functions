/***********************************PROGRAM HEADER*****************************************************************************************************
Name: Ryan Milrad
TOTAL POINTS:  25
DUE DATE:  09/22/2020
COURSE:  COP 3530
Assignment Name:  Assignment#3
Professor:  Dr. Bullard

Description:  Declaration CPP file for date assignment
******************************************************************************************************************************************************/


#include <iomanip>
#include <iostream>
#include <string>
#include <string.h>
#include "string_class.h"
using namespace std;

//default coonstructor
string_class::string_class() {
	current_string = "";
}

//explicit value constructor sets current string to an empty string
string_class::string_class(string current) {
	current_string = current;
}

//returns t/f if the current string is a palindrome
bool string_class::palindrome() {
	if (current_string.size() == 1) {
		return true;
	}
	else if (current_string.size() % 2 == 0) {
		for (int i = 0; i < current_string.size() / 2; i++) {
			int a = current_string[i];
			int b = current_string[current_string.size() - 1 - i];
			int equal;
			if (a > b) {
				equal = a - b;
			}
			else if (a < b) {
				equal = b - a;
			}
			else {
				equal = 0;
			}

			if (equal != 0) {
				if (equal != 32) {
					return false;
				}
			}
		}
		return true;
	}
	else {
		for (int i = 0; i < (current_string.size() / 2); i++) {
			int a = current_string[i];
			int b = current_string[current_string.size() - 1 - i];
			int equal;
			if (a > b) {
				equal = a - b;
			}
			else if (a < b) {
				equal = b - a;
			}
			else {
				equal = 0;
			}

			if (equal != 0) {
				if (equal != 32) {
					return false;
				}
			}
		}
		return true;
	}
}

//replace function to replace a certain string within the current_string with a new given string
void string_class::replace_all(const string old_substring, const string new_substring) {

	int eligible; //used to decide whether the given strings can be reconstructed
	int locEnd, diff, cont=0;
	int loc = -1;

	//sets eligible to 0 if strings given are not eligible. Sets eligible to 1 if strings can be reconstructed
	if (current_string.size() == 0 || (old_substring.size() > current_string.size())) {
		eligible = 0;
	}
	else {
		eligible = 1;
	}

	//if the strings can be reconstructed
	if (eligible == 1) {
		for (int i = 0; i < (current_string.size()); i++) { //starting at beginning of current_string and loop till last index
			for (int j = 0; j < old_substring.size(); j++) { //starting at beginning of old_substring
				if (i == current_string.size()) { //if current_string index is beyond length, break loop
					break;
				}
				else if ((current_string[i] == old_substring[j]) && (j < (old_substring.size() - 1))) { //if current_string index and old_substring index match up but not at end of old_substring, increase both indexes
					i++;
					loc = -1;
				}
				else if ((current_string[i] == old_substring[j]) && (j < old_substring.size())) { //if indexes match and at end of old_substring, set location for replacement 
					loc = i - j;
				}
				else if (current_string[i] != old_substring[j]) { //if not a match, break
					loc = -1;
					i++;
					j = -1;
				}
				else { //any other circumstances, break
					loc = -1;
					i++;
					j = -1;
				}
			}
			if (loc != -1) { //if a match has been found and location has been set
				locEnd = loc + new_substring.size() - 1; //set a stop location for reference
				diff = new_substring.size() - old_substring.size(); //set a value for replacement string size difference for reference
				if (diff > -1) { //if the new_substring isnt smaller than the old_substring
					for (int q = 0; q < diff; q++) { //increase size of current_string by the diff in size, diff
						current_string += '!';
					}
					for (int k = current_string.size() - 1; k > locEnd; k--) { //starting at the last index of current_string, shift each element to new position
						current_string[k] = current_string[k - diff];
					}
					for (int k = 0; k < new_substring.size(); k++) { //when loop reaches locEnd, starting at loc, begin to replace old_substring with new_substring until totally replaced
						current_string[loc + k] = new_substring[k];
					}
				}
				else { //if the new_substring is smaller than the old_substring
					if (new_substring.size() == 0) {
						current_string.erase(loc, old_substring.size());
					}
					else {
						for (int q = 0; q < locEnd; q++) { //starting at loc, replace old_substring
							current_string[loc + q] = new_substring[q];
						}
						for (int q = 1; q < current_string.size() - 1; q++) { //starting after locEnd, begin to shift remaining elements
							current_string[locEnd + q] = current_string[locEnd + q + 1];
						}
						current_string.erase(current_string.size() - 1, diff);
					}
				}
				if (new_substring.size() != 0) {
					i += (new_substring.size() - 1); //set i to a value to pick up at the index after the last element of the new_substring
				}
				else {
					i = loc - 2;
				}				
				loc = -1; //reset location to ensure if no new locations are found, the function ends
			}
			else { //help break loop
				cont += i;
			}
		}
		if (cont > (current_string.size() - 1)) { //if the current_string has reached its last element, change the strings eligibility to avoid running loop
			eligible = 0;
		}
	}
	else { //if the given strings are not eligible, function ends.
		cout << "Finished." << endl;
		return;
	}
}

//overload << operator with chaining
ostream& operator<<(ostream& out, const string_class& current) {
	out << current.current_string << endl;
	return out;
}