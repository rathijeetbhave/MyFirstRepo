#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
		int i,elem,n;
		vector<int> vec,s;
		cin>>n;
		s.push_back(0);
		cout<<s[0]<<endl;
		while(!cin.eof())
		{
				cin>>elem;
				vec.push_back(elem);
		}

		for(int j=0;j<n;j++)
				cout<<vec[j]<<" ";
		cout<<endl;
		cout<<vec.size()<<endl;		
		for(i=1;i<=n;i++)
		{
				s.push_back(max(s[i-1]+vec[i-1],vec[i-1]));
		}

		for(int k=0;k<s.size();k++)
				cout<<s[k]<<" ";
		cout<<endl;
		s.clear();
}

