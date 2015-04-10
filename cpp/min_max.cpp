#include<iostream>
//#include<algorithm>
#include<cmath>
using namespace std;

void min_max(int,int,int,int,int*);
struct answer{
		int minimum;
		int maximum;
};
int main()
{
		struct answer ans;
		int a[]={1,2,3,4,5,6,7,8},max=0,min=0;
		min_max(0,7,min,max,a);
}

void min_max(int i,int j,int min,int max,int* a)
{
		int mid,left_min,left_max,right_min,right_max;
		if(i==j)
		{
				min=a[j];
				max=a[i];
		}
		else if((j-i)==1)
		{
				if(a[i]>=a[j])
				{
						max=a[i];
						min=a[j];
				}
				else
				{
						max=a[j];
						min=a[i];
				}

		}
		else
		{
				mid=(i+j)/2;
				min_max(i,mid,min,max,a);

			/*	left_min=*min;
				left_max=*max;
				cout<<"left_min= "<<left_min<<" "<<"left_max= "<<left_max<<endl;*/

				min_max(mid+1,j,right_min,right_max,a);

			/*	right_min=*min;
				right_max=*max;

				cout<<"right_min= "<<right_min<<" "<<"right_max= "<<right_max<<endl;*/

				if(min<=right_min)
						min=left_min;
			/*	else
						min=right_min;*/
				if(right_max>=max)
						max=right_max;
			/*	else
						max=right_max;*/
				cout<<min<<" "<<max<<endl;

		}
		}
