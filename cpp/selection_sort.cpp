#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
		int n,i=0,min,elem,index,temp,j,k;
		//cout<<"enter no. of elements";
		cin>>n;
		int *a;
		a=(int*)malloc(n);
		while(!cin.eof())
		{
				cin>>elem;
				a[i]=elem;
				i++;
		}
		for(j=0;j<n-1;j++)
		{
			min=a[j];
			for(i=j+1;i<n;i++)
			{
					if(a[i]<min)
					{	
						min=a[i];
						index=i;
					}
			}
			cout<<min<<index<<endl;

			temp=a[j];
			a[j]=min;
		  a[index]=temp;
		}
		
		for(k=0;k<n;k++)
		{
				cout<<a[k]<<" ";
		}
		cout<<endl;
}

