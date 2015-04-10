#include "bank.h"

int Bank::totalAccounts = 0;
double Bank::bankBalance = 1000;

Bank::Bank(){
		accountNumber=0;
		balance=0.0;
		totalAccounts++;
}

Bank::Bank(string newName,int newAccountNumber,double NewBalance){
		accountNumber=newAccountNumber;
		balance=NewBalance;
		name=newName;
		totalAccounts++;
		bankBalance+=NewBalance;
}

Bank::~Bank(){
		totalAccounts--;
		bankBalance -= balance;
}

string Bank::getname() const {
		return name;
}

double Bank::getbalance() const {
		return balance;
}

int Bank::getAccountNumber() const {
		return accountNumber;
}

void Bank::setname(string newName){
		name=newName;
}

void Bank::setbalance(double NewBalance){
		bankBalance -= balance;
		balance = NewBalance;
		bankBalance += balance;
}

void Bank::setAccountNumber(int newAccountNumber){
		accountNumber=newAccountNumber;
}

void Bank::withdraw(double withdraw){
		balance-=withdraw;
		bankBalance-=withdraw;
}

void Bank::deposit(double deposit){
		balance+=deposit;
		bankBalance+=deposit;
}

void Bank::printBankInfo(){
		cout<<"total number of accounts : "<<totalAccounts<<endl;
		cout<<"total bankBalancebalance is : "<<bankBalance<<endl;
}
