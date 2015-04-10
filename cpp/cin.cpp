#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
	char i;
	int j,k,l;
	cin>>j;
	cout<<j<<endl;
	while(!cin.eof())
	//while(cin>>i)
	{
		//if(cin.good()==0)
		//	break;
		
		cin>>j;
		cin>>k;
		if(j==0)
		{
			cin>>l;
			cout<<j<<" "<<k<<" "<<l<<endl;
		}
		else
			cout<<j<<" "<<k<<endl;
	}
	//cout<<i<<endl;
}
	
