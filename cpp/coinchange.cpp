#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
		int i, change_for=2,j,cost;
		vector<int> denominations,c;
	  for(i=0;i<3;i++)
				denominations.push_back(2*i+1);
		
		for(i=0;i<change_for+1;i++)
				c.push_back(0);

		for(j=1;j<change_for+1;j++)
		{
			  cost=2000;
				for(i=0;i<denominations.size();i++)
				{
						if((j-denominations[i])<0)
								break;
						else
								cost=min(cost,c[j-denominations[i]]);
				}
				c[j]=cost+1;
		}
		cout<<c[j-1]<<endl;
}
