#include<iostream>
#include<string>
using namespace std;
int main()
{
		char ch;
		string str,str1;
		int j=1,i=0,count=0;
		getline(cin,str);
		cout<<str<<endl;
		str.insert(str.begin(),toupper(str[0]));
		cout<<str<<endl;
		for(i=0;i<str.length();i++)
		{
				if(str[i]==' ')
						count++;
		}

		cout<<count;

		while(str[i]!='\0')
		{
				if(str[i]== ' ')
				{
						//cout<<"hi";
						str.insert(str.begin()+j,toupper(str[i+1]));
						j++;
				}
				else
						str.erase(str.begin()+j);
				i++;
		}
		cout<<str1<<" "<<j<<endl;

}
