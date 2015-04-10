#include<iostream>
using namespace std;
int *check(int,int);
int main()
{
	int *c;
	c=check(10,20);
	cout<<*c<<endl;
}

int *check(int i,int j)
{
	int *p,*q;
	p=&i;
	q=&j;
	if(i>=450000000)
	{
		return p;
		cout<<"hi";
	}
	else
		return q;
}
