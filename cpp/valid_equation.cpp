#include<iostream>
#include<algorithm>
using namespace std;

void valid_equation(int*,int,int,int,char*,int);
void myprint(char*);

int main()
{
		int a[]={1,2,3,4,5},result=5;
		char sign[4];
		valid_equation(a,1,5,1,sign,5);

}

void valid_equation(int* a,int k,int n,int r,char* sign,int result)
{
		int temp=r;
	//	cout<<r<<" "<<k<<endl;
		if(k==n)
		{
				if(r==result)
						myprint(sign);
				else
						return;
		}
		else
		{
				r=r+a[k];
			//	cout<<"hi ";
				sign[k-1]='+';
				valid_equation(a,k+1,n,r,sign,result);

				r=r-2*a[k];
				sign[k-1]='-';
				valid_equation(a,k+1,n,r,sign,result);

		}
}

void myprint(char* sign)
{
		for(int i=0;i<4;i++)
				cout<<sign[i];
		cout<<endl;
}
