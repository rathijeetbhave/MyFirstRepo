#include "bank.h"

int main(){
		Bank::printBankInfo();
		cout<<endl;
		Bank rathi("rathi",1,200);
		Bank::printBankInfo();
		cout<<endl;
		Bank bhaskar;
		bhaskar.setname("bhaskar");
		bhaskar.setbalance(0);
		bhaskar.setAccountNumber(3);
		Bank::printBankInfo();
		cout<<endl;
		bhaskar.deposit(3000);
		rathi.deposit(400);
		Bank::printBankInfo();
		cout<<endl;
	//	bhaskar.setbalance(500);
		Bank::printBankInfo();
		cout<<endl;
		bhaskar.~Bank();
		Bank::printBankInfo();
		cout<<endl;
		
		Bank pramod("pramod",3,7000);
	//	bhaskar.deposit(3000);
	//	Bank bhaskar("bhaskar",2,3000);
		Bank::printBankInfo();
		cout<<endl;
		cout<<"pramod ko dena hai "<<pramod.getbalance()<<endl;
		cout<<"bhaskar ko dena hai "<<bhaskar.getbalance()<<endl;
		
}

