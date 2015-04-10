#include<iostream>
using namespace std;

void permute(int*,int,int);
void myprint(int*,int);

int main()
{
		int n=2;
		int a[]={1,2,3};
		permute(a,0,n);
}

void permute(int* a,int k,int n)
{
		int temp;
		if(k==n)
				myprint(a,n);
		else
		{
				for(int i=k;i<3;i++)
				{
						temp=a[k];
						a[k]=a[i];
						a[i]=temp;

						permute(a,k+1,n);

						temp=a[k];
						a[k]=a[i];
						a[i]=temp;
				}
		}
}

void myprint(int*a, int n)
{
		for(int i=0;i<=n;i++)
				cout<<a[i]<<" ";
		cout<<endl;
}
