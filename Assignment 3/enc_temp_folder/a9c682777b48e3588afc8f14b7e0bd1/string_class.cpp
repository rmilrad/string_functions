#include <iomanip>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class string_class {
public:
	string_class();
	string_class(string current);
	bool palindrome();
	void replace_all(const string old_substring, const string new_substring);
	friend ostream& operator<<(ostream& out, const string_class& current);
private:
	string current_string;
};

string_class::string_class() {
	current_string = "";
}

string_class::string_class(string current) {
	current_string = current;
}

bool string_class::palindrome() {
	for (int i = 0; i < current_string.size() / 2; i++) {
		if (current_string[i] == current_string[current_string.size() - 1 - i]) {
			return true;
		}
		else {
			return false;
		}
	}
}

void string_class::replace_all(const string old_substring, const string new_substring) {
	
	int eligible;
	int locEnd, diff;
	int loc=-1;
	if (current_string.size() == 0 || (old_substring.size() > current_string.size())) {
		eligible = 0;
	}
	else {
		eligible = 1;
	}

	if (eligible == 1) {
		for (int i = 0; i < current_string.size(); i++) {
			for (int j = 0; j < old_substring.size() || i == current_string.size(); j++) {
				if ((current_string[i] == old_substring[j]) && (j < (old_substring.size() - 1))) {
					i++;
					loc = -1;
				}
				else if ((current_string[i] == old_substring[j]) && (j < old_substring.size())) {
					loc = i-j;
				}
				else if (current_string[i] != old_substring[j]) {
					loc = -1;
					i++;
					j = -1;
				}
				else {
					loc = -1;
					i++;
					j = -1;
				}
			}
			cout << loc;
			if (loc != -1) {
				cout << "Starting replacement" << endl;
				locEnd = loc + new_substring.size() - 1;
				diff = new_substring.size() - old_substring.size();
				for (int q = 0; q < diff; q++) {
					current_string += '!';
				}
				cout << current_string;
				for (int k = current_string.size()-1; k > locEnd; k--) {
					current_string[k] = current_string[k - diff];
				}
				for (int k = 0; k < new_substring.size(); k++) {
					current_string[loc + k] = new_substring[k];
				}
				i += (new_substring.size() - 1);
				loc = -1;
			}
			else {
				break;
			}
			cout << current_string;
		}
	}
	else {
		cout << "Can not be completed." << endl;
		return;
	}
}


ostream& operator<<(ostream& out, const string_class& current) {
	out << current.current_string << endl;
	return out;
}

int main() {
	/*
	string_class s;
	cout << "****************************************" << endl
	<< "Test#1: tesing default constructor and overloaded operator<< with chaining\n"
	<< s << "1st blank line" << endl << s << "2nd blank line" << endl
	<< "Test#1 Ended" << endl
	<< "****************************************" << endl;

	
	string_class r("hello");
	cout << "****************************************" << endl	<< "Test#2: tesing explicit-value constructor and overloaded operator<< with chaining\n" << r << endl << "1st blank line" << endl << r <<endl<< "2nd blank line " << endl
	<< "Test#2 Ended" << endl
	<< "****************************************" << endl;

	
	cout << "****************************************" << endl
	<< "Test#3: tesing palindrome\n"
	<< "****************************************" << endl;
	string response = "Y";
	string ss;
	while (response == "Y" || response == "y")
	{
	cout << "Enter String: ";
	getline(cin, ss);
	string_class main_string(ss);
	if (main_string.palindrome()==true)
	{
		cout << ss << " is a palindrome\n";
	}
	else
	{
		cout << ss << " is not a palindrome\n";
	}
	cout << "Would you like to try another string? (Y or N): ";
	getline( cin,response);
	}
	cout << "Test#3 Ended" << endl
	<< "****************************************" << endl;
	*/
	string response;
	
	cout << "****************************************" << endl
	<< "Test#4: tesing replace_all\n"
	<< "****************************************" << endl;
	response = "y";
	string current, old_substring, new_substring;
	while (response == "Y" || response == "y")
	{
	cout << "Enter value for current_string: ";
	getline(cin, current);
	string_class current_string(current);
	cout << "Enter old_substring: ";
	getline(cin, old_substring);
	cout << "Enter new_substring: ";
	getline(cin, new_substring);
	cout << "Current Value in Current string = " << current << endl;
	current_string.replace_all(old_substring, new_substring);
	cout << "New value in Current String = " << current_string << endl;
	cout<< endl;
	cout << "Would you like to try another string? (Y or N): ";
	getline(cin, response);
	cout << endl;
	}
	cout << "****************************************" << endl
	<< "End Test#4: tesing replace\n"
	<< "****************************************" << endl;
	

	return 0;
}