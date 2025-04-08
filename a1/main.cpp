// EXEMPLE COMMANDS TO COMPILE AND REUN THE TEST FILE
// @Glen-Sasek-PCC-Instructor ➜ /workspaces/CS-161B (main) $ cd a1
// @Glen-Sasek-PCC-Instructor ➜ /workspaces/CS-161B/a1 (main) $ g++ main.cpp && ./a.out < test-1.txt && rm ./a.out


/******************************************************************************
# Author:           
# Assignment:       A01 (CS161B)
# Date:             April 6, 2025
# Description:      Food Cart program that takes user information for prices
					          and products and displays the total and applicable 
					          discounts
# Input:            double itemCost, tip; int userOption; string itemPurchased		
# Output:           Program will output prompts to obtain user input
					          will output user costs and discounts if applicable
					          Welcome and goodbye messages
# Sources:          Assignment 1 specifications
#******************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

void welcome();
void displayMenu();
void readOption(int& option);
void readInt(string prompt, int& num);
void readChar(string prompt, char& option);
void readDouble(string prompt, double& num);
void placeOrder(double& cost);
double tipDiscount(double& tip, double& discount, double cost);
void discountDisplay(double discount, double cost);
void displayTotal(double cost);

int main() {
	int userOption;
	double cost;
	double discount;
	double tip;
	
	welcome();
	do {
		displayMenu();
		readOption(userOption);
		if (userOption == 1) {
			cost = 0; // setting cost to 0 for looping
			placeOrder(cost);
			displayTotal(cost); // to display total
			cost = tipDiscount(tip, discount, cost); 
			cout << "Your final total is: $" << fixed
				<< setprecision(2) << cost << endl << endl;
		}

	} while (userOption != 2);
	
	cout << "Goodbye!" << endl;
}

void welcome() {
	cout << "Hello there and welcome to my food cart!\n";
	cout << "What would you like to order?\n";
	cout << endl;
}

void displayMenu() {
	cout << "Pick one of the options below:\n";
	cout << "1. Place an Order" << endl;
	cout << "2. Quit" << endl;
}

void readOption(int& option) {
	string prompt = "Option: ";
	readInt(prompt, option);

	// while the option is not 1 or 2
	while (option != 1 && option != 2) {
		readInt(prompt, option);
	}
}

void readInt(string prompt, int& num) {
	int tempVar = 0;
	cout << prompt;
	cin >> tempVar;
	while (!cin || tempVar != 1 && tempVar != 2)
	{
		cout << "Invalid input! Please enter 1 or 2:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> tempVar;
	}
	cin.ignore(10, '\n');
	num = tempVar;
}

void readChar(string prompt, char& option) {
	cout << prompt;
	cin >> option;
	// loop until correct input
	while (!cin || (option != 'y' && option != 'Y' &&
		option != 'n' && option != 'N')) {
		cout << "Invalid input! ";
		cout << "Please enter 'y' for yes or 'n' for no : \n";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> option;
	}
	cin.ignore(10, '\n');
}

void readDouble(string prompt, double& num) {
	double temp = 0.0;
	cout << prompt;
	cin >> temp;
	while (!cin || temp < 0.0 || temp > 100000.0) {
		cout << "Invalid input! Enter a postive number:";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> temp;
	}
	cin.ignore(10, '\n');
	num = temp;
}

void placeOrder(double& cost) {
	char userOrder = 'x';
	double localCost = 0;
	string prompt1 = "Enter the cost of your item: $";
	string prompt2 = "Do you want another item (y/n)? ";

	while (userOrder != 'n' && userOrder != 'N') {
		cout << "Enter the name of the item: ";
		string menuItem;
		getline(cin, menuItem);
		readDouble(prompt1, localCost);
		cost += localCost;
		readChar(prompt2, userOrder);
	}
}

double tipDiscount(double& tip, double& discount, double cost) {
	double total = cost;
	string prompt = "Enter a tip amount: $";
	readDouble(prompt, tip);
	total += tip;
	displayTotal(total); // Show total including tip
	if (total >= 50) {
		discount = 0.1; //10% discount 
		discountDisplay(discount, total);
		return total *= (1 - discount);
	}
	else if (total < 50 && total >= 35) {
		discount = 0.05; //5% discount
		discountDisplay(discount, total);
		return total *= (1 - discount);
	}
	else {
		return total;
	}
}

void discountDisplay(double discount, double cost) {
	cout << "You get a " << (discount * 100.0) << "% discount!\n";
	cout << "You discount today is $" << fixed << setprecision(2) <<
		(cost * discount) << endl;
	cout << endl;
}

void displayTotal(double cost) {
	cout << endl;
	cout << "Your total is: $" << fixed << setprecision(2) << cost;
	cout << endl;
}
