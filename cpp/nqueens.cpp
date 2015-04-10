#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
		int n=4,soln[n];
		nqueens(n,soln);
}

void nqueens(int n int *soln)
{
		for(i=0;i<n;i++)
		{
				for(j=0;j<i;j++)
				{
						if(can_place(i,j))
						{
								soln[i]=j;
								if(i==n-1)
								{
										for (int k=0;k<n;k++)
												cout<<soln[k];
								}
								else
										nqueens
						}
				}
		}
}
