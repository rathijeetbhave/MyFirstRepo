#ifndef Bank_H
#define Bank_H

#include<iostream>
#include<string>
using namespace std;

class Bank{
public:
		//Default constructor
		Bank();

		//Overload constructor
		Bank(string, int, double);

		//Destructor
		~Bank();

		//Accessor functions
		string getname() const;

		double getbalance() const;

		int getAccountNumber() const;

		void setname(string);

		void setbalance(double);

		void setAccountNumber(int);

		//Mutator functions
		void deposit(double);

		void withdraw(double);

		static void printBankInfo();


private:
		string name;
		double balance;
		int accountNumber;

		static int totalAccounts;
		static double bankBalance;

};

#endif
