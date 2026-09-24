// ==================================================================
//       (C++) LOGIN AND REGISTRATION SYSTEM - CodeAlpha Project
// ==================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <conio.h>
#include <windows.h>

using namespace std;


const int CLR_DEFAULT = 7;
const int CLR_BORDER = 9;       // Blue
const int CLR_TITLE = 13;       // Pink / Purple
const int CLR_LABEL = 14;       // Yellow
const int CLR_INPUT = 15;       // Bright white
const int CLR_SUCCESS = 10;     // Green
const int CLR_ERROR = 12;       // Red
const int CLR_MENU = 11;        // Light blue

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen()
{
	system("cls");
}

void printLine(char symbol = '=', int width = 58)
{
	setColor(CLR_BORDER);

	for (int i = 0; i < width; i++)
	{
		cout << symbol;
	}

	cout << endl;
	setColor(CLR_DEFAULT);
}

void printTitle(string title)
{
	printLine('=');

	setColor(CLR_TITLE);
	cout << "              " << title << endl;

	printLine('=');
	setColor(CLR_DEFAULT);
}

void pauseScreen()
{
	setColor(CLR_MENU);
	cout << "\nPress any key to continue...";
	setColor(CLR_DEFAULT);

	_getch();
}

// ------------------------------------------------------------
// Password input with * characters
// ------------------------------------------------------------
string readPassword()
{
	string password = "";
	char character;

	while (true)
	{
		character = _getch();

		if (character == 13) // Enter key
		{
			cout << endl;
			break;
		}
		else if (character == 8) // Backspace key
		{
			if (password.length() > 0)
			{
				password.erase(password.length() - 1, 1);
				cout << "\b \b";
			}
		}
		else if (character != 0 && character != 224)
		{
			password += character;
			cout << "*";
		}
	}

	return password;
}

// ------------------------------------------------------------
// Username validation
// ------------------------------------------------------------
bool isValidUsername(string username)
{
	if (username.length() < 3)
	{
		return false;
	}

	for (int i = 0; i < username.length(); i++)
	{
		if (!isalnum(username[i]) && username[i] != '_')
		{
			return false;
		}
	}

	return true;
}

// ------------------------------------------------------------
// Finds whether username already exists in users.txt
// File format: username|password
// ------------------------------------------------------------
bool usernameExists(string username)
{
	ifstream file("users.txt");
	string line;

	while (getline(file, line))
	{
		int separatorPosition = line.find('|');

		if (separatorPosition != -1)
		{
			string savedUsername = line.substr(0, separatorPosition);

			if (savedUsername == username)
			{
				file.close();
				return true;
			}
		}
	}

	file.close();
	return false;
}

// ------------------------------------------------------------
// Register a new account
// ------------------------------------------------------------
void registerUser()
{
	string username;
	string password;
	string confirmPassword;

	clearScreen();
	printTitle("NEW USER REGISTRATION");

	setColor(CLR_LABEL);
	cout << "Enter username: ";
	setColor(CLR_INPUT);
	getline(cin, username);

	if (!isValidUsername(username))
	{
		setColor(CLR_ERROR);
		cout << "\nError: Username must have at least 3 characters.\n";
		cout << "Only letters, numbers, and underscore are allowed.\n";
		setColor(CLR_DEFAULT);
		return;
	}

	if (usernameExists(username))
	{
		setColor(CLR_ERROR);
		cout << "\nError: This username is already registered.\n";
		setColor(CLR_DEFAULT);
		return;
	}

	setColor(CLR_LABEL);
	cout << "Enter password: ";
	setColor(CLR_INPUT);
	password = readPassword();

	if (password.length() < 6)
	{
		setColor(CLR_ERROR);
		cout << "Error: Password must contain at least 6 characters.\n";
		setColor(CLR_DEFAULT);
		return;
	}

	if (password.find('|') != -1)
	{
		setColor(CLR_ERROR);
		cout << "Error: Password cannot contain the | character.\n";
		setColor(CLR_DEFAULT);
		return;
	}

	setColor(CLR_LABEL);
	cout << "Confirm password: ";
	setColor(CLR_INPUT);
	confirmPassword = readPassword();

	if (password != confirmPassword)
	{
		setColor(CLR_ERROR);
		cout << "Error: Passwords do not match.\n";
		setColor(CLR_DEFAULT);
		return;
	}

	try
	{
		ofstream file("users.txt", ios::app);

		if (!file)
		{
			throw runtime_error("Unable to open the user database file.");
		}

		file << username << "|" << password << endl;
		file.close();

		setColor(CLR_SUCCESS);
		cout << "\nRegistration successful! You can now log in.\n";
		setColor(CLR_DEFAULT);
	}
	catch (exception& error)
	{
		setColor(CLR_ERROR);
		cout << "\nRegistration error: " << error.what() << endl;
		setColor(CLR_DEFAULT);
	}
}

// ------------------------------------------------------------
// Login existing account
// ------------------------------------------------------------
void loginUser()
{
	string username;
	string password;
	string line;

	clearScreen();
	printTitle("USER LOGIN");

	setColor(CLR_LABEL);
	cout << "Enter username: ";
	setColor(CLR_INPUT);
	getline(cin, username);

	setColor(CLR_LABEL);
	cout << "Enter password: ";
	setColor(CLR_INPUT);
	password = readPassword();

	try
	{
		ifstream file("users.txt");

		if (!file)
		{
			throw runtime_error("No user database found. Register first.");
		}

		bool loginSuccessful = false;

		while (getline(file, line))
		{
			int separatorPosition = line.find('|');

			if (separatorPosition != -1)
			{
				string savedUsername = line.substr(0, separatorPosition);
				string savedPassword = line.substr(separatorPosition + 1);

				if (username == savedUsername && password == savedPassword)
				{
					loginSuccessful = true;
					break;
				}
			}
		}

		file.close();

		if (loginSuccessful)
		{
			setColor(CLR_SUCCESS);
			cout << "\nLogin successful. Welcome, " << username << "!\n";
		}
		else
		{
			setColor(CLR_ERROR);
			cout << "\nLogin failed. Incorrect username or password.\n";
		}

		setColor(CLR_DEFAULT);
	}
	catch (exception& error)
	{
		setColor(CLR_ERROR);
		cout << "\nLogin error: " << error.what() << endl;
		setColor(CLR_DEFAULT);
	}
}

// ------------------------------------------------------------
// Main Program
// ------------------------------------------------------------
int main()
{
	string choice;

	while (true)
	{
		clearScreen();
		printTitle("LOGIN & REGISTRATION SYSTEM");

		setColor(CLR_MENU);
		cout << "  [1] Register New User\n";
		cout << "  [2] Login\n";
		cout << "  [3] Exit\n";

		setColor(CLR_LABEL);
		cout << "\nEnter your choice: ";
		setColor(CLR_INPUT);

		getline(cin, choice);

		if (choice == "1")
		{
			registerUser();
			pauseScreen();
		}
		else if (choice == "2")
		{
			loginUser();
			pauseScreen();
		}
		else if (choice == "3")
		{
			clearScreen();
			printTitle("GOODBYE");

			setColor(CLR_SUCCESS);
			cout << "\nThank you for using the system.\n\n";
			setColor(CLR_DEFAULT);
			break;
		}
		else
		{
			setColor(CLR_ERROR);
			cout << "\nInvalid choice. Please enter 1, 2, or 3.\n";
			setColor(CLR_DEFAULT);

			pauseScreen();
		}
	}

	return 0;
}