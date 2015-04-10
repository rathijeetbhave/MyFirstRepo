#include<iostream>
#include<algorithm>
using namespace std;

void sum_of_subset(int,int,int,int*,int,int *);
void myprint(int*);
int main()
{
	int a[]={2,3,4,5};
	int x[4];
	int m=7,sum=0,r=14;
	sum_of_subset(0,14,0,a,7,x);
}

void sum_of_subset(int s,int r,int k,int* a,int m,int* x)
{
	/*if(k>3)
		return;*/
	x[k]=1;
	if(s+a[k]==m)
		myprint(x);
	else if(s+a[k]+a[k+1]<=m)
	{
		sum_of_subset(s+a[k],r-a[k],k+1,a,m,x);
	}
	if((s-a[k]+r>=m) && (s+a[k+1]<=m))
	{
		x[k]=0;
		sum_of_subset(s,r-a[k],k+1,a,m,x);
	}
}

void myprint(int* x)
{
	for(int i=0;i<4;i++)
		cout<<x[i]<<" ";
	cout<<endl;
}
