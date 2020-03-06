/*  Program Description 
Read five names into a vector<string> name, then prompt the user for the ages of the people
named and store the ages in a vector<double> age. Then print out the five (name[i],age[i]) 
pairs. Sort the names (sort(name.begin(),name.end())) and print out the (name[i],age[i]) 
pairs. The tricky part here is to get the age vector in the correct order to match the 
sorted name vector. Hint: Before sorting name, take a copy and use that to make a 
copy of age in the right order after sorting name.
*/

/*
Standard opening
*/

#include "C:\Users\mark.alexieff\source\repos\std_lib_facilities.h"

/*
global variables
*/

vector<string> name;
vector<double> age;
int num_names{ 0 };
const int number_of_names_to_get{ 5 };

/*
functions declarations
*/
int get_names(vector<string>& vn);
int get_ages(vector<double>& va);
void print_names_ages(vector<string>& vn, vector<double>& va);

/*
main
*/

int main() {

	int name_ret{ 0 };
	int age_ret{ 0 };

	name_ret = get_names(name);
	age_ret = get_ages(age);

	cout << "Now we'll output the name age pairs..." << '\n';

	print_names_ages(name, age);

	keep_window_open();
}

/*
funcion definitions
*/

int get_names(vector<string>& vn) {
	string temps{ " " };
	cout << "Enter 5 names: ";
	for (int i = 0; i < 5; i++) {
		cin >> temps;
		vn.push_back(temps);
	}
	return(0);
}

int get_ages(vector<double>& va) {
	double temp_age{ 0 };
	cout << '\n' << "Now enter the ages for each..." << '\n';
	for (string s : name) {
		cout << "Age of " << s << " is?  ";
		cin >> temp_age;
		age.push_back(temp_age);
		cout << "\n";
	}
	return(0);
}

void print_names_ages(vector<string>& vn, vector<double>& va) {
	auto age_itr = va.begin();
	for (string s : vn) {
		cout << s << " is " << *age_itr << '\n';
		age_itr++;
	}
}
