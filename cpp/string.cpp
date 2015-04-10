#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
		int num[5],l;
		for(int i=0;i<5;i++)
				num[i]=0;

		vector<string> str;
		str.push_back("amazon");
		str.push_back("rathi");
		str.push_back("run");
		str.push_back("pun");
		str.push_back("sun");
		for(int i=0;i<5;i++)
		{
				for(int j=str[i].size()-1;j>=0;j--)
				{
						if(str[i][j]=='a'||str[i][j]=='b'||str[i][j]=='c')
								num[i]=num[i]+2*pow(10,str[i].size()-j-1);

						if(str[i][j]=='d'||str[i][j]=='e'||str[i][j]=='f')
								num[i]=num[i]+3*pow(10,str[i].size()-j-1);

						if(str[i][j]=='g'||str[i][j]=='h'||str[i][j]=='i')
								num[i]=num[i]+4*pow(10,str[i].size()-j-1);

						if(str[i][j]=='j'||str[i][j]=='k'||str[i][j]=='l')
								num[i]=num[i]+5*pow(10,str[i].size()-j-1);

						if(str[i][j]=='m'||str[i][j]=='n'||str[i][j]=='o')
								num[i]=num[i]+6*pow(10,str[i].size()-j-1);

						if(str[i][j]=='p'||str[i][j]=='q'||str[i][j]=='r'||str[i][j]=='s')
								num[i]=num[i]+7*pow(10,str[i].size()-j-1);

						if(str[i][j]=='t'||str[i][j]=='u'||str[i][j]=='v')
								num[i]=num[i]+8*pow(10,str[i].size()-j-1);

						if(str[i][j]=='x'||str[i][j]=='y'||str[i][j]=='z')
								num[i]=num[i]+9*pow(10,str[i].size()-j-1);
				}
		}

		sort(num,num+5,greater<int>());
		for(int i=0;i<5;i++)
				cout<<num[i]<<"  "<<str[i]<<endl;
		string temp;
		for(int i=0;i<4;i++)
		{
				if(num[i]==num[i+1])
				{
						l=strcmp(str[i].c_str(),str[i+1].c_str());
						if(l>0)
						{
							temp=str[i];
							str[i]=str[i+1];
							str[i+1]=temp;
							//	swap(str.beg()+i,str.begin()+i+1]);
								//swap(num+i,num+i+1);
						}
				}
		}
								
		for(int i=0;i<5;i++)
				cout<<num[i]<<"  "<<str[i]<<endl;



}
