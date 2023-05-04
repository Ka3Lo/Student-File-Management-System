#pragma once
#include <iostream>
#include <string>

using namespace std;
class StudentManagementSystem
{
	static bool findStudent(string studentID);
public:
	static void addStudent();
	static void deleteStudent();
	static void viewStudent();
	static void printStudentRecord();
	static bool studentLoginProcess(string student_email, string student_password);
};


