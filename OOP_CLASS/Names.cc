#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Subject
{
	string name;
	int marks;		// assuming out of 100
	char grade;
	
public:
	Subject(string name = "", int marks = 0);
	string &get_name();
	int &get_marks();
	char &get_grade();

	void calcGrade();
};

Subject::Subject(string name, int marks)
{
	Subject::name = name;
	Subject::marks = marks;

	if(marks > 100 || marks < 0)
	{
		cerr << "Wrong marks." << endl;
		exit(1);
	}
}

void Subject::calcGrade()
{
	if(marks > 80) grade = 'A';
	else if(marks > 70) grade = 'B';
	else if(marks > 60) grade = 'C';
	else if(marks > 50) grade = 'D';
	else grade = 'F';
}

inline int &Subject::get_marks()
{
	return this->marks;
}

inline char &Subject::get_grade()
{
	return this->grade;
}

inline string &Subject::get_name()
{
	return this->name;
}

class Student
{
	Subject subjects[5];
	double percentage;
	char avg_grade;

	int max_width;

public:
	Student();
	void inputSubjects();
	void outputTable();
	void calcPercentage();
};

Student::Student()
{
	percentage = 0;
	max_width = 0;
}

void Student::inputSubjects()
{
	cout << "Enter Names of Subjects followed by their marks." << endl;
	for(int i = 0; i < 5; i++)
	{
		cout << "[" << i + 1 << "] ";
		cin >> subjects[i].get_name() >> subjects[i].get_marks();

		subjects[i].calcGrade();

		if(subjects[i].get_name().size() > max_width)
			max_width = subjects[i].get_name().size();
	}

	// Accounting for Percentage Scored
	if(max_width < 17)
		max_width = 17;
}

void Student::outputTable()
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
		cout << "| " << setfill(' ') << setw(max_width) << left << subjects[i].get_name() << " | "
			<< setw(6) << setfill(' ') << left << subjects[i].get_marks() << " |"
			<< " " << subjects[i].get_grade() << " |" << endl;
	}

	cout << "+" << setw(max_width + 2) << setfill('-')  << '-' << '+'
		<< setfill('-') << setw(8) << '-' << '+'
		<< setfill('-') << setw(3) << '-' << '+' << endl;

	cout << "| " << setw(max_width) << setfill(' ') << left << "Percentage Scored" << " : "
			<< setw(6) << setprecision(2) << left << percentage << " |"
			<< " " << avg_grade << " |" << endl;

	cout << "+" << setw(max_width + 2) << setfill('-')  << '-' << '+'
		<< setfill('-') << setw(8) << '-' << '+'
		<< setfill('-') << setw(3) << '-' << '+' << endl;
}

void Student::calcPercentage()
{
	for(int i = 0; i < 5; i++)
		percentage += subjects[i].get_marks();
	percentage /= 5.0;

	if(percentage > 80) avg_grade = 'A';
	else if(percentage > 70) avg_grade = 'B';
	else if(percentage > 60) avg_grade = 'C';
	else if(percentage > 50) avg_grade = 'D';
	else avg_grade = 'F';
}

int main(void)
{
	Student s;
	s.inputSubjects();
	s.calcPercentage();
	s.outputTable();
}
