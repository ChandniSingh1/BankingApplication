#include <iostream>
using namespace std;
#include "DataInput.h" // allows public data from 'h' file to be accessed into this file

DataInput::DataInput() {  // constrictor 
	inititalInvest = 0.0;
	monthlyDeposit = 0.0;
	interestRate = 0;
	numberOfYears = 0;
}

void DataInput::setInititalInvest(double invest) { //mutator
	inititalInvest = invest;
}

void DataInput::setMonthlyDeposit(double deposit) {  //mutator
	monthlyDeposit = deposit;
}

void DataInput::setInterestRate(int precentage) {  //mutator
	interestRate = precentage;
}

void DataInput::setNumOfYears(int years) {  //mutator
	numberOfYears = years;
}

double DataInput::getInititalInvest() { //accessor 
	return inititalInvest; 
}

double DataInput::getmonthlyDeposit() {  //accessor 
	return monthlyDeposit;
}

int DataInput::getInterestRate() {  //accessor 
	return interestRate;
}

int DataInput::getnumberOfYears() { //accessor 
	return numberOfYears;
}