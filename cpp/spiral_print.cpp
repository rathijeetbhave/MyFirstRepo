#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
		int L=0,R=2,T=0,B=2,dir=0,i;
		int a[3][3]={1,2,3,4,5,6,7,8,9};
		while(T<=B && L<=R)
		{
				if(dir==0)
				{
						for(i=L;i<=R;i++)
								cout<<a[T][i]<<" ";
						T++;
						dir=1;
				}

				if(dir==1)
				{
						for(i=T;i<=B;i++)
								cout<<a[i][R]<<" ";
						R--;
						dir=2;
				}

				if(dir==2)
				{
						for(i=R;i>=L;i--)
								cout<<a[B][i]<<" ";
						B--;
						dir=3;
				}

				if(dir==3)
				{
						for(i=B;i>=T;i--)
								cout<<a[i][L]<<" ";
						L++;
						dir=0;
				}
		}
}
