#include<iostream>
using namespace std;
void findmin(int *b, int n)
{
	cout<< "func n="<<n <<endl;
	int i,temp,low=0,*p;
	p=b;
	if(n==1)
		cout<<*p;
	else
	{
		for(i=1;i<n;i++)
		{
			if(*b>*(b+i))
			{
				//low=low+1;
				b=b+i;
			}
		}
		//cout<< b[n-1] <<endl;
		temp=*p;
		*p=*b;
		*b=temp;
		//b[n-1] = b[low];
		//b[low]=temp;
		cout<< *p;
		b=p+1;
		findmin(b,n-1);
	}
	
}

void findmin(int *b, int n);

int main()
{
	int n,a[n],i;
	cout<< "enter no of elements";
	cin>> n;
	cout<<"enter elements";
	for(i=0;i<n;i++)
	{
		cin>> a[i];
	}
	cout<< "main n="<<n<<endl;
	findmin(a,n);
	return 0;
}
	
	
	

