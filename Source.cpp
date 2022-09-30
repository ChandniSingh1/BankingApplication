#include <iostream>
#include <string> 
#include "DataInput.h"
#include <iomanip>
using namespace std;

//varaibles 
DataInput bankingInfo;
double invest;
double deposit;
int rate;
int years;
char input;
char input2;
double intNewRateNoDeposit;
double yearlyInt;
bool go = true; 

string createChars(size_t num, char c) { //creates a string with a number of chars 
	std::string starSpaces;
	return starSpaces.append(num, c);
}

void firstTable() { // creates inlital table design 
	cout << createChars(34, '*') << endl;
	cout << createChars(11, '*') << " Data Input " << createChars(11, '*') << endl;
}
void tableInput() { // gets and sets data input from user 
	cout << "Initital Investment Amount: $" ;
	cin >> invest;
	bankingInfo.setInititalInvest(invest); //sets investment amount 
	cout << "Monthly Deposit: $";
	cin >> deposit;
	bankingInfo.setMonthlyDeposit(deposit); // sets motnhly deposit 
	cout << "Annual Interest: %";
	cin >> rate; 
	bankingInfo.setInterestRate(rate); // sets interest rate 
	cout << "Number of years: ";
	cin >> years;
	bankingInfo.setNumOfYears(years); // sets number of years to calculate 

}

void filltablewithout(double deposit, int rate, int years) { // calculates yearly blances and interest amounts over the set period of years. Returns amounts after 2 decimal points
	yearlyInt = (rate / 100.00);
	intNewRateNoDeposit = (bankingInfo.getInititalInvest() * yearlyInt);
	double newAmount1 = (bankingInfo.getInititalInvest() + intNewRateNoDeposit);
	for (int i = 1; i <= years; i++) {	
		cout << createChars(5, ' ') << i << createChars(15, ' ');
		cout << "$" << fixed << std::setprecision(2) << newAmount1 << createChars(10, ' ');
		double diffOf = (newAmount1 - bankingInfo.getInititalInvest());
		cout << createChars(10, ' ') << "$" << fixed << std::setprecision(2) << diffOf << endl;
		newAmount1 += intNewRateNoDeposit;
	}
}
 

void filltablewithdep(double deposit, int rate, int years, double monthlydep) { // calculates yearly blances and interest amounts over the set period of years with added montly depositz. Returns amounts after 2 decimal points
	yearlyInt = ((rate / 100.00)/12.00);
	intNewRateNoDeposit = (bankingInfo.getInititalInvest() * yearlyInt);
	double newAmount1 = (bankingInfo.getInititalInvest() + (intNewRateNoDeposit));
	for (int i = 1; i <= years; i++) {
		newAmount1 += ((monthlydep * 12) + intNewRateNoDeposit);
		cout << createChars(5, ' ') << i << createChars(15, ' ');
		cout << "$" << fixed << std::setprecision(2)  << newAmount1 << createChars(10, ' ');
		double diffOf = ((newAmount1 - bankingInfo.getInititalInvest()) - (monthlydep * 12));
		cout << createChars(10, ' ') << "$" << fixed << std::setprecision(2) << diffOf << endl;
	}
}

void tableWithout() { // designs table and uses function to display amounts
	cout << endl;
	cout << createChars(3, ' ') << "Balance and Interest Without Additional Monthly Deposits" << createChars(6, ' ') << endl;
	cout << createChars(66, '=') << endl;
	cout << createChars(3, ' ') << "Year" << createChars(6, ' ') << "Year End Balance" << createChars(6, ' ') << "Year End Earned Interest" << endl;
	cout << createChars(66, '-') << endl;
	filltablewithout(bankingInfo.getInititalInvest(), bankingInfo.getInterestRate(), bankingInfo.getnumberOfYears());
}

void tableWith() { // designs table and uses function to display amounts  
	cout << endl;
	cout << createChars(3, ' ') << "Balance and Interest With Additional Monthly Deposits" << createChars(6, ' ') << endl;
	cout << createChars(66, '=') << endl;
	cout << createChars(3, ' ') << "Year" << createChars(6, ' ') << "Year End Balance" << createChars(6, ' ') << "Year End Earned Interest" << endl;
	cout << createChars(66, '-') << endl;
	filltablewithdep(bankingInfo.getInititalInvest(), bankingInfo.getInterestRate(), bankingInfo.getnumberOfYears(), bankingInfo.getmonthlyDeposit());
}          


int main() {
	while (go) {
		firstTable(); // calls function to creates design 
		tableInput(); // calls function that allows for user input 
		cout << "Press 'Y' to continue . . . ";
		cin >> input;
		if (input == 'y' || input == 'Y') { // displays both tables with and without monthly deposits 
			tableWithout();
			tableWith();
			cout << "Would you like to estimate other amounts? Press 'Y' to continue or 'N' to quit. "; // asks user if they would like to try other amounts without having the restart program.
			cin >> input2;
			if (input2 == 'y' || input2 == 'Y') {
				cout << endl;
				cout << endl;
				go = true;
			}
			else if (input2 == 'n' ||input2 == 'N') {
				go = false;
				cout << endl;
				cout << " Thank you for using AirGead Banking App. Have a good day!"; // ends program 
			}
		}
		else if (input != 'y' || input != 'Y') { // loops back to the beginning if invalid input is entered. 
			cout << endl;
			cout << endl;
			cout << "Invaild input";
			go = false;
			go = true;

		}
	}
}