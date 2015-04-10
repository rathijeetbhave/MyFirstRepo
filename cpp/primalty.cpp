#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool isprime(double);
int main()
{
		double n;
		bool b;
		cout<<"enter number";
		cin>>n;
		b=isprime(n);
		cout<<b<<endl;
}

bool isprime(double n)
{
		double n1;
		for(int i=0;i<20;i++)
		{
				n1=fmod(rand(),n)+1;
				if(n1==n)
						break;
				if(fmod(pow(n1,n-1),n) != 1.0)
						return 0;

		}
		
		return 1;
}

