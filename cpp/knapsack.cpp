#include<iostream>
#include<algorithm>
using namespace std;

//#define rows 4;
//#define columns 11;
//int rows=4,columns=11;
void myprint(int[10][11],int[10][11]);
int main()
{
		int i,j,row=4,col=6,sum=0,l;
		int value[]={2,3,4,2,3,4,2,3,4};
		int weight[]={2,3,4,2,3,4,2,3,4};
		int cost[10][11],taken[10][11],count[11];
		for(l=0;l<11;l++)
			count[l]=0;
		for(i=0;i<11;i++)
		{
				cost[0][i]=0;
				taken[0][i]=0;
		}
		for(i=0;i<10;i++)
		{
				cost[i][0]=0;
				taken[i][0]=0;
		}
				
		for(i=1;i<10;i++)
		{
			for(j=1;j<11;j++)
			{
				if((j-weight[i-1])>=0)
				{
					cost[i][j]=max(cost[i-1][j],cost[i-1][j-weight[i-1]]+value[i-1]);
					if(cost[i][j]==cost[i-1][j])
						taken[i][j]=0;
					else
					{
						sum=0;
						taken[i][j]=1;
						for(l=1;l<=i;l++)
							sum=sum+taken[l][j]*weight[l-1];
						if(sum<=j)
							count[j]++;
					}
				}
				else
				{
					cost[i][j]=cost[i-1][j];
					taken[i][j]=0;
				}
			}
		}
		
		myprint(cost,taken);
		cout<<endl;
		for(l=0;l<11;l++)
			cout<<count[l]<<" ";
		cout<<endl;
		cout<<endl;
		/* For printing elements*/
		int n=10,w=10;
		while(n!=0)
		{
			if(taken[n][w]==1)
			{
				cout<<"sone no. "<<n<<" value is "<<value[n]<<endl;
				n=n-1;
				w=w-weight[n];
			}
			else
				n=n-1;
		}
		cout<<endl;
}

void myprint(int cost[10][11],int taken[10][11] )
{
		int i,j;
		for(i=0;i<10;i++)
		{
				for(j=0;j<11;j++)
						cout<<*(*(cost+i)+j)<<" ";
				cout<<endl;
		}
		cout<<endl;
		cout<<endl;
		
		for(i=0;i<10;i++)
		{
				for(j=0;j<11;j++)
						cout<<*(*(taken+i)+j)<<" ";
				cout<<endl;
		}
}
