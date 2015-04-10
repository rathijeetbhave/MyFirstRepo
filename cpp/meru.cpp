#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
		string str;
		int i,k,t;
		char ch;
		getline(cin,str);
		cout<<str<<endl;
		cin>>t;

		for(i=0;i<t;i++)
		{
				int count=0,l=0;
				cin>>k>>ch;
				while(str[l]!='\0')
				{
						if(str[l]==ch)
						{
								count++;
								if(count==k)
										str.erase(str.begin()+l);
						}
						l++;
				}

		}
		cout<<str<<endl;

}
