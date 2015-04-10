#include<iostream>
using namespace std;
void comp(char*,char*);
static int count;
int main()
{
	char str1[]="ask";
	char str2[]="bhaskarask";
	
	comp(str1,str2);
	cout<<count<<endl;
}

void comp(char*p,char*q)
{
		int flag=0;
		//for(int i=0;i<=7;i++)
		for(int i=0;q[i]!='\0';i++)
		{
				//cout<<"hi";
				for(int j=0;p[j]!='\0';j++)
				{
						if(p[j]!=q[i+j])
						{
								break;	
						}
						else
							flag++;
						if(flag==3)
						{
								count++;
								flag=0;
						}
				}
		}
		
}
