#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

char calcgrade(int marks)
{
	if(marks > 80) return  'A';
	else if(marks > 70) return 'B';
	else if(marks > 60) return 'C';
	else if(marks > 50) return 'D';
	else return 'F';
}

void outputTable(double percentage, int max_width, string *names, int *marks, char *grade)
{
	cout << "+" << setw(max_width + 2) << setfill('-')  << '-' << '+'
		<< setfill('-') << setw(8) << '-' << '+'
		<< setfill('-') << setw(3) << '-' << '+' << endl;

	cout << "| " << setw(max_width) << setfill(' ') << left << "Subject" << " | "
			<< setw(6) << "Marks" << " |"
			<< "" << "Grd" << "|" << endl;

	cout << "+" << setw(max_width + 2) << setfill('-')  << '-' << '+'
		<< setfill('-') << setw(8) << '-' << '+'
		<< setfill('-') << setw(3) << '-' << '+' << endl;

	for(int i = 0; i < 5; i++)
	{
		cout << "| " << setfill(' ') << setw(max_width) << left << names[i] << " | "
			<< setw(6) << setfill(' ') << left << marks[i] << " |"
			<< " " << grade[i] << " |" << endl;
	}

	cout << "+" << setw(max_width + 2) << setfill('-')  << '-' << '+'
		<< setfill('-') << setw(8) << '-' << '+'
		<< setfill('-') << setw(3) << '-' << '+' << endl;

	cout << "| " << setw(max_width) << setfill(' ') << left << "Percentage Scored" << " : "
			<< setw(6) << setprecision(2) << left << percentage << " |"
			<< " " << calcgrade(percentage) << " |" << endl;

	cout << "+" << setw(max_width + 2) << setfill('-')  << '-' << '+'
		<< setfill('-') << setw(8) << '-' << '+'
		<< setfill('-') << setw(3) << '-' << '+' << endl;
}

int main(void)
{
	int max_width = 0;
	double percentage = 0;

	string names[5];
	int marks[5];
	char grade[5];

	cout << "Enter Names of Subjects followed by their marks." << endl;
	for(int i = 0; i < 5; i++)
	{
		cout << "[" << i + 1 << "] ";
		cin >> names[i] >> marks[i];

		percentage += marks[i];

		grade[i] = calcgrade(marks[i]);

		if(names[i].size() > max_width)
			max_width = names[i].size();
	}
	percentage /= 5.0;

	// Accounting for Percentage Scored
	if(max_width < 17)
		max_width = 17;

	outputTable(percentage, max_width, names, marks, grade);
}
