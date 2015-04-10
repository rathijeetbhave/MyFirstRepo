#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int n,avg,i,*p,sum=0,*c,*d;
	cout<<"enter no. of students";
	cin>>n;
	p=(int*)calloc(n,2);
	c=p;
	d=c;
	cout<<p<<endl<<c;
	if(p==NULL)
	{
		cout<<"memory allocation unsuccessful";
		exit(0);
	}
	for(i=0;i<n;i++)
	{
		cin>>*p;
		p++;
	}
	p=p-1;
	for(i=0;i<n;i++)
	{
		cout<<*p;
		p=p-1;
	}
	for(i=0;i<n;i++)
		sum=sum+*(p+i);
	avg=sum/n;
	cout<<endl<<avg;
}
	
	
