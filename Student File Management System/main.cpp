#include <iostream>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "StudentManagementSystem.h"
#include "Admin.h"

using namespace std;

int main()
{
	StudentManagementSystem sms;
	Admin admn;
	string admin_Name, admin_Password, student_Name, student_Password;
	int admin_LoginCounter = 3;
	int student_LoginCounter = 3;
	int ch;

	do
	{
		cout << "\n\n\t\t**********    Login Dashboard    **********";
		cout << "\n\n\t\t 1.Admin\n\t\t 2.Student\n\t\t 3.Exit \n\n\t\t Enter your Choice: ";
		cin >> ch;
		int adminch = 0;
		bool result;
		bool studfoundIndex;


		switch (ch)
		{

		case 1:
			do {
				cout << "\n\n\t\t**********    Admin Login    **********";
				cout << "\n\t\tUsername:";
				cin >> admin_Name;
				cout << "\n\t\tpassword:";
				cin >> admin_Password;
				result = admn.Admin_Login(admin_Name, admin_Password);
				if (!result)
				{
					admin_LoginCounter -= 1;
					cout << "\n\t\tInvalid username or password try again !!! " << endl;
					cout << "\n\t\tYou have " << admin_LoginCounter << " attempts left" << endl;

				}

				if (result)
				{
					cout << "\n\t\t Admin login  Successful !!!";
					do
					{

						cout << "\n\n\t\t**********    Admin DashBoard    **********";
						cout << "\n\n\t\t1.Add Student \n\t\t2.Delete Student\n\t\t3.View Student Details\n\t\t4.Print List\n\t\t5.Exit\n\n\t\tEnter Your Choice: ";
						cin >> adminch;


						switch (adminch)
						{
						case 1:
							sms.addStudent();
							break;
						case 2:
							sms.deleteStudent();
							break;
						case 3:
							sms.viewStudent();
							break;
						case 4:
							sms.printStudentRecord();
							break;
						}
					} while (adminch != 5);
				}
			} while (admin_LoginCounter <= 3 && admin_LoginCounter != 0);
			break;
		case 2:
			do {
				cout << "\n\n\t\t**********    Student Login    **********";
				cout << "\n\t\tEmail: ";
				cin >> student_Name;
				cout << "\n\t\tPassword: ";
				cin >> student_Password;
				studfoundIndex = sms.studentLoginProcess(student_Name, student_Password);
				if (!studfoundIndex)
				{
					student_LoginCounter -= 1;
					cout << "\n\t\tInvalid username ,password or student not on record!!";
					cout << "\n\t\tYou have " << student_LoginCounter << " attempts left" << endl;
				}

				else
					cout << "\n\t\t" << student_Name << " you successfully logged in" << endl;

			} while (student_LoginCounter <= 3 && student_LoginCounter != 0);
			break;
		}
	} while (ch != 3);
}


