#include<iostream>
using namespace std;
int fib(int n)
{
	int k;
	if(n==0)
		return 0;
	else if(n==1)
		return 1;	
	else
	{
		k=fib(n-1)+fib(n-2);
		return k;
	}
}

int main()
{
	int f,n;
	cout<< "enter value";
	cin>> n;
	f=fib(n);
	cout<< f;
	//return(0);
}

