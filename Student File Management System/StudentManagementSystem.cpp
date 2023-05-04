#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_LENGTH 15 //MAX NAME CHARACTER LENGTH
#define MAX_FACULTY_LENGTH 20 // MAX FACULTY CHARACTER LENGTH
#define MAX_STUDENT_NUMBER_LENGTH 5 //MAX LENGTH FOR STUDENT NUMBER
#define MAX_ADDRESS_LENGTH 20 // MAX EMAIL ADDRESS CHARACTER LENGTH
#define MAX_PASSWORD_LENGTH 15 // MAX PASSWORD LENGTH
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "StudentManagementSystem.h"


using namespace std;

bool StudentManagementSystem::findStudent(string studentID)
{
	fstream find_studentFile;
	find_studentFile.open("StudentFile.txt", ios::in);

	if (find_studentFile.is_open())
	{
		string line, rollNo, firstname, lastname, email, faculty, password;
		while (getline(find_studentFile, line))
		{
			stringstream sso(line);

			getline(sso, rollNo, '\t');
			getline(sso, firstname, '\t');
			getline(sso, lastname, '\t');
			getline(sso, email, '\t');
			getline(sso, faculty, '\t');
			getline(sso, password, '\t');

			if (studentID.compare(rollNo) == 0)
			{
				find_studentFile.close();
				return true;
			}
			else
			{
				continue;
			}
		}
	}
	else
	{
		cout << "Error opening the STUDENT FILE......." << endl;
		return false;
	}
}

void StudentManagementSystem::addStudent()
{
	fstream add_studentFile;

	char* studentNumber = new char[MAX_STUDENT_NUMBER_LENGTH]; //Student number should be 5 characters
	char* Password = new char[MAX_PASSWORD_LENGTH];
	char* FirstName = new char[MAX_NAME_LENGTH];
	char* LastName = new char[MAX_NAME_LENGTH];
	char* Email = new char[MAX_ADDRESS_LENGTH];
	char* Faculty = new char[MAX_ADDRESS_LENGTH];


	add_studentFile.open("StudentFile.txt", ios::app);

	if (add_studentFile.is_open())
	{
		cout << "\n\t\tEnter student Information:";
		cout << "\n\t\tSTUDENT NUMBER: ";
		cin >> studentNumber;

		cout << "\n\t\tSTUDENT FIRST NAME: ";
		cin >> FirstName;

		cout << "\n\t\tSTUDENT LAST NAME: ";
		cin >> LastName;

		cout << "\n\t\tSTUDENT EMAIL: ";
		cin >> Email;

		cout << "\n\t\tSTUDENT FACULTY: ";
		cin >> Faculty;

		cout << "\n\t\tPASSWORD (Alphanumeric): ";
		cin >> Password;

		add_studentFile << studentNumber << "\t" << FirstName << "\t" << LastName << "\t" << Email << "\t" << Faculty << "\t" << Password << "\n";
		add_studentFile.close();
	}

	delete[] studentNumber;
	studentNumber = NULL;

	delete[] FirstName;
	FirstName = NULL;

	delete[] LastName;
	LastName = NULL;

	delete[] Email;
	Email = NULL;

	delete[] Faculty;
	Faculty = NULL;

	delete[] Password;
	Password = NULL;
	cout << "\n\t\tStudent Successfully Added in Record !!!" << endl;
}

void StudentManagementSystem::deleteStudent()
{
	string rollNumber;
	fstream studentFile;
	fstream tempFile;

	cout << "\n\t\tEnter student roll number to delete student from record: ";
	cin >> rollNumber;

	bool result = findStudent(rollNumber);

	if (result)
	{
		string line, studentNumber, FirstName, LastName, Email, Faculty, Password;

		studentFile.open("StudentFile.txt", ios::in);
		tempFile.open("Temp.txt", ios::out);

		if (studentFile.is_open())
		{
			while (getline(studentFile, line))
			{
				stringstream sso(line);

				getline(sso, studentNumber, '\t');
				getline(sso, FirstName, '\t');
				getline(sso, LastName, '\t');
				getline(sso, Email, '\t');
				getline(sso, Faculty, '\t');
				getline(sso, Password, '\t');

				if (rollNumber.compare(studentNumber) == 0)
					continue;
				else
				{
					tempFile << studentNumber << "\t" << FirstName << "\t" << LastName << "\t" << Email << "\t" << Faculty << "\t" << Password << "\n";
				}
			}
			studentFile.close();
			tempFile.close();
		}

		studentFile.open("StudentFile.txt", ios::out);
		tempFile.open("Temp.txt", ios::in);

		if (tempFile.is_open())
		{
			string line, studentNumber, FirstName, LastName, Email, Faculty, Password;

			while (getline(tempFile, line))
			{
				stringstream sso(line);

				getline(sso, studentNumber, '\t');
				getline(sso, FirstName, '\t');
				getline(sso, LastName, '\t');
				getline(sso, Email, '\t');
				getline(sso, Faculty, '\t');
				getline(sso, Password, '\t');

				studentFile << studentNumber << "\t" << FirstName << "\t" << LastName << "\t" << Email << "\t" << Faculty << "\t" << Password << "\n";
			}

			studentFile.close();
			tempFile.close();
		}

		remove("Temp.txt");
		cout << " \n\t\tStudent with Roll number " << rollNumber << " deleted" << endl;
	}

	else
	{
		cout << " \n\t\tStudent with Roll number " << rollNumber << " NOT FOUND" << endl;
	}
}

void StudentManagementSystem::viewStudent()
{
	string rollNumber;
	fstream studentFile;

	cout << "\n\t\tEnter student roll number to view student record: ";
	cin >> rollNumber;
	bool result = findStudent(rollNumber);
	if (result)
	{
		studentFile.open("StudentFile.txt", ios::in);
		if (studentFile.is_open())
		{
			string line, firstname, lastname, rollNo, username, password, studClass, emailId, mobileNumber;
			while (getline(studentFile, line))
			{
				stringstream sso(line);

				getline(sso, rollNo, '\t');
				getline(sso, firstname, '\t');
				getline(sso, lastname, '\t');
				getline(sso, username, '\t');
				getline(sso, studClass, '\t');
				getline(sso, emailId, '\t');
				getline(sso, mobileNumber, '\t');

				if (rollNumber.compare(rollNo) == 0)
				{
					cout << "\n\t\t This is the student with roll number: " << rollNumber << endl;
					cout << "\n\t\t " << firstname << " " << lastname << endl;
				}
				else
					continue;
			}

			studentFile.close();
		}
	}
	else
		cout << "Student with Roll number " << rollNumber << " NOT FOUND" << endl;
}

void StudentManagementSystem::printStudentRecord()
{
	fstream studentFile;
	studentFile.open("StudentFile.txt", ios::in);

	if (studentFile.is_open())
	{
		string line;

		cout << "\n\n\t\t**********    LIST OF STUDENTS    **********" << endl;

		while (getline(studentFile, line))
		{
			cout << " \n\t\t " << line << " \n";
		}

		studentFile.close();
	}
}

bool StudentManagementSystem::studentLoginProcess(string student_email, string student_password)
{
	fstream studentFile;
	studentFile.open("StudentFile.txt", ios::in);

	if (studentFile.is_open())
	{
		string line, rollNo, firstname, lastname, email, faculty, password;
		while (getline(studentFile, line))
		{
			stringstream sso(line);

			getline(sso, rollNo, '\t');
			getline(sso, firstname, '\t');
			getline(sso, lastname, '\t');
			getline(sso, email, '\t');
			getline(sso, faculty, '\t');
			getline(sso, password, '\t');

			if (student_email.compare(email) == 0 && student_password.compare(password) == 0)
			{
				cout << "\n\n\t\t**********    STUDENT PORTAL    **********" << endl;
				cout << "\n\t\t " << "Roll Number: " << rollNo << endl;
				cout << "\n\t\t " << "First Name: " << firstname << endl;
				cout << "\n\t\t " << "Last Name: " << lastname << endl;
				cout << "\n\t\t " << "Username: " << email << endl;
				cout << "\n\t\t " << "Faculty: " << faculty << endl;
				cout << "\n\t\t " << "Email: " << password << endl;

				studentFile.close();
				return true;
			}
			else
			{
				continue;
			}
		}
	}
	else
		return false;
}
