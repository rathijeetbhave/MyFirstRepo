#include<iostream>
using namespace std;
int main()
{
	int a[100],n,i,k,t;	
	
	cout<< "enter no. of elements";
	cin>> n;	
	cout<<"\nEnter Elements : \n";

	for(i=0;i<=n-1;i++)
	{
		cin>> a[i];
	}
	for(i=0;i<n;i++)
	{
		t=a[i];
		k=i;
		while(k>0 && a[k]<a[k-1])
		{
			a[k]=a[k-1];

			a[k-1]=t;
			k=k-1;
		}
	}
	for(k=0;k<=n-1;k++)
	{
		cout<< a[k]<<endl;
	}	
	return(0);
}


