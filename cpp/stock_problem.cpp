#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int stock_problem(int *,int,int);
int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,a[n],elem,max=0,profit;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>elem;
        a[i]=elem;
    }
		profit=stock_problem(a,0,n);
		cout<<profit<<endl;
}

int stock_problem(int *a,int k,int n)
{
		int money,profit;
		int max,i;
		if(k==n-1)
				return profit;
    for( i=k;i<n;i++)
    {
        if(a[i]>max)
            max=a[i];
    }
		cout<<max<<endl;
		i=k;
		while(a[i]<max)
		{
				money=money-a[i];
				i++;
		}
		profit=a[i+1]*i-money;
		stock_problem(a,i+2,n);
}

   /* for(int i=0;i<n-1;i++)
    {
        if(a[i]<=a[i+1])
        {
            buy[i]
            }
        }
    }*/
    


