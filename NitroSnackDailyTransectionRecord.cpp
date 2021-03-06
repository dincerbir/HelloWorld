// NitroSnackDailyTransectionRecord.cpp : Records Daily Transection Activities and saves them in an Exel File
#include "Database.h"
#include "NitroSnackMenuItem.h"
#include "Gelato.h"
#include "DragonBreath.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <process.h>

#define CLEARSCREEN system ( "cls" )

using namespace std;

//Forward Declerations
void flushStdIn();
void callHelper(char); 
void helper(char);

void newSale(string, int, double);
double calculateItemPrice(int, double);

int main()
{
	char choice = '\0';

	cout << "\n *** NITROSNACK DAILY TRANSECTION RECORD ***" << endl << endl;

	do
	{
		cout << "\tPlease Select one Option" << endl;
		cout << "\t[1]-New Sale" << endl;
		cout << "\t[2]-Display Sales History" << endl;
		cout << "\t[0]-Exit" << endl;
		cin >> choice;
		flushStdIn();
		callHelper(choice);

	} while (choice != '0');

    return 0;
}

void clrscr()
{
	system("@cls||clear");
}

void flushStdIn()
{
	int c;
	do c = getchar(); while (c != '\n' && c != EOF);
}

void callHelper(char choice)
{
	switch (choice)
	{
		case '1':
		case '2': helper(choice);
			break;
		case '0': break;
		default: cout << "*** Invalid Operation! Please Select an Option Below ***" << endl;
	}
}

void helper(char choice)
{
	int	quantity = 0;
	double itemPrice = 0.0;
	string itemName = "";

	if (choice == '1')
	{
		system("cls");
		cout << endl << "\t*****New Sale*****" << endl;
		cout << "\t|-->1-Item Name:";
		getline(cin, itemName);

		cout << "\t|-->2-Quantity:";
		cin >> quantity;

		cout << "\t|-->3-Price:";
		cin >> itemPrice;
		cout << endl << "|-->Total Amount:" << calculateItemPrice(quantity, itemPrice) << endl;
		newSale(itemName, quantity, itemPrice);
	}
}

void newSale(string item, int quantity, double price)
{
	cout << "New Item Added in Transection History!" << endl;
}

double calculateItemPrice(int quantity, double itemPrice)
{
	return (quantity * itemPrice);
}