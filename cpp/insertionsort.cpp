#include<iostream>
using namespace std;
int main()
{
	int a[100],n,i,j,k,temp,p,z;	
	cout<< "enter no. of elements";
	cin>> n;
	cout<<"\nEnter Elements : \n";
	for(i=0;i<=n-1;i++)
	{
		cin>> a[i];
	}
	for(j=1;j<=n-1;j++)
	{
		z=j;
		for(p=j;p>0;p--)
		{
			if(a[z]<a[p-1])
			{
				temp=a[p-1];			
				a[p-1]=a[z];
				a[z]=temp;
				z=z-1;
			}
		}
	}
	for(k=0;k<=n-1;k++)
	{
		cout<< a[k]<<endl;
	}
	return(0);
}
			
				
	
