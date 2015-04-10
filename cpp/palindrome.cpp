#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int palindrome(string,int ,int);
static int mycount ;

int main()
{
		int i,l;
	  char *p,*q;
	  //p=new string;
	  //p="abchdr";
		char str[]="abczba";
		l=palindrome(str,1,6);
		/*p=str;
		q=p+1;*/
		cout<<l<<endl;
		cout<<mycount<<endl;

			//	cout<<&q-&p<<" "<<q<<endl;
}

int palindrome(string str,int i,int j)
{
		if(i==j)
				return 1;
	else if(((j-i)==1) && str[i-1]==str[j-1])
				return 2;
		else if(((j-i)==1) && str[i-1]!=str[j-1])
				return 1;
		else
		{
				if(str[i-1]==str[j-1])
				{
						mycount++;
						return palindrome(str,i+1,j-1)+2;
				}
				else
				{
						mycount++;
						return max(palindrome(str,i+1,j),palindrome(str,i,j-1));
				}
				
		}
		
		
}
