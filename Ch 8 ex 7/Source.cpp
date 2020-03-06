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
vector<string> sorted_name;
vector<double> age;
vector<double> sorted_age;
int num_names{ 0 };
const int number_of_names_to_get{ 5 };

/*
functions declarations
*/
int get_names(vector<string>& vn);
int get_ages(vector<double>& va);
void print_names_ages(vector<string>& vn, vector<double>& va);
void sort_both(vector<string>& vn, vector<string>& svn, vector<double>& va, vector<double>& sa);


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

	cout << "Now we'll output the sorted name age pairs..." << '\n';

	sort_both(name, sorted_name, age, sorted_age);

	print_names_ages(sorted_name, sorted_age);

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

void sort_both(vector<string>& vn, vector<string>& svn, vector<double>& va, vector<double>& sa) {
	
	int va_index{ 0 };
	int sa_index{ 0 };

	svn = vn;
	sa = va;

	sort(svn.begin(), svn.end());
	for (string s : svn) {
		va_index = 0;
		for (auto vn_itr = vn.begin(); vn_itr < vn.end(); vn_itr++) {
		if (s == *vn_itr) sa.at(sa_index) = va.at(va_index);
		va_index++;
		}
		sa_index++;
	}

}
