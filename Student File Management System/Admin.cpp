#include "Admin.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <string>

bool Admin::Admin_Login(string uname, string password)
{
	fstream adminFile;
	string adminUsername, adminPassword;

	//admin USERNAME Super, PASSWORD abc123
	adminFile.open("Super_Admin.txt", ios::in);

	if (adminFile.is_open())
	{
		string line;
		while (getline(adminFile, line))
		{
			stringstream sso(line);

			getline(sso, adminUsername, ',');
			getline(sso, adminPassword, ',');

			if (adminUsername.compare(uname) == 0 && adminPassword.compare(password) == 0)
			{
				adminFile.close();
				return true;
			}

			else
				return false;
		}
	}
	else
	{
		cout << "Error opening the STUDENT FILE......." << endl;
		return false;
	}
}
