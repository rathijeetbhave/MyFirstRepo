#include<iostream>
#include<algorithm>
using namespace std;
int find_min_dist(int*,int,int,int);
int main()
{
		int n,query,count=1,i,j,m;
		cin>>n;
		int a[n];
		int e[n][n];
		cin>>m;
		for(i=0;i<n;i++)
		{
				for(j=0;j<n;j++)
					e[i][j]=0;
		}
		for(i=0;i<m;i++)
		{
				cin>>query;
				if(query==1)
				{
						cin>>i>>j;
						e[i][j]=1;
						e[j][i]=1;
				}
				else
				{
						cin>>i>>j;
						count = find_min_dist((int*)e,i,j,0);
						cout<<count<<endl;
						
				}
		}
}

int find_min_dist(int *arr,int i,int j,int count)
{int p;//i=0;j=0;
p=*(arr+3*i+j);
cout<<p;
return 2;
		/*if(c[i][j]==1)
				return count;
		else
		{
				for(k=0;k<n;i++)
				{
						if(k==j)
								continue;
						if(c[i][k]==1)
						{
								count++;
								find_min_dist(k,j);
						}
								
				}
		return -1;
		}*/
}

