#include<iostream>
#include<algorithm>
using namespace std;

int partition(int*,int,int);
void swap(int*,int,int);
void quicksort(int*,int,int );

int main()
{
		int i,a[8]={7,2,64,6,6,4,3,45},p;

		quicksort(a,0,7);
	//p=partition(a,0,3);
		for(i=0;i<8;i++)
				cout<<a[i]<<" ";
		cout<<endl;

		return 0;
}

int partition(int* a,int start,int end)
{
		int pivot=a[end],index=start,i;
		for(i=start;i<end;i++)
		{
				if(a[i]<pivot)
				{
						swap(a,index,i);
						index++;
				}
		}
		swap(a,index,end);
		return index;
		
}

void swap(int* a,int index,int i)
{
		int temp;
		temp=a[index];
		a[index]=a[i];
		a[i]=temp;
}

void quicksort(int* a,int start,int end)
{
		if(start<end)
		{
				int p;
				p=partition(a,start,end);
				quicksort(a,start,p-1);
				quicksort(a,p+1,end);
		}
}
