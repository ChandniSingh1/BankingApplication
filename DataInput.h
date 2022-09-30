#ifndef Data_Input_H //opens
#define Data_Input_H
using namespace std;

class DataInput {
private: // private variables 
	double inititalInvest;
	double monthlyDeposit;
	int interestRate;
	int numberOfYears;

public: // public variables (Getters and Setters) 
	DataInput();
	void setInititalInvest(double invest);
	void setMonthlyDeposit(double deposit);
	void setInterestRate(int precentage);
	void setNumOfYears(int years);
	double getInititalInvest();
	double getmonthlyDeposit();
	int getInterestRate();
	int getnumberOfYears();

};

#endif //ends 