#include<iostream>
#include<cstdlib>
using namespace std;
int push(int, int);
int pop(int);
int peek(int);
int isEmpty(int);
int display(int);
int n=6;
int top0=-1,top1=n,stk[6],i;
int main()
{
	int s,ch,elem;
	for(i=0;i<n;i++)
		stk[i]=-1;
	while(1)
	{
		cout<<"press 0 for push \n 1 for pop \n 2 for peek \n 3 for isempty \n 4 to display \n 5 to exit \n";
		cin>>ch;
		cout<<"enter stack value";
		cin>>s;
		switch(ch)
		{
			case 0:
			{
				cout<<"enter element to be pushed";
				cin>>elem;
				push(s,elem);
				break;
			}
			case 1:
				pop(s);
				cout<<endl;
				break;

			case 2:
				peek(s);
				cout<<endl;
				break;
			case 3:
				isEmpty(s);
				cout<<endl;
				break;
			case 4:
				display(s);
				break;
			case 5:
				exit(0);
		}
		//cout<<"-1";
	}
	return 0;
}

int push(int s,int elem)
{
	if(s==0)
	{
		if(stk[top0+1]!=-1)
			cout<<"-1"<<endl;
		else
		{
			top0=top0+1;
			stk[top0]=elem;
			cout<<"1"<<endl;
		}
	}
	if(s==1)
	{
		if(stk[top1-1]!=-1)
			cout<<"-1"<<endl;
		else
		{
			top1=top1-1;			
			stk[top1]=elem;
			cout<<"1"<<endl;
		}
	}
}

int pop(int s)
{
	if(s==0)
	{
		if(top0<0)
			cout<<"-1";
		else
		{
			cout<<stk[top0]<<endl;
			stk[top0]=-1;
			top0=top0-1;
			//cout<<stk[top0]<<endl;
		}
	}
	
	if(s==1)
	{
		if(top1>n-1)
			cout<<"-1";
		else
		{
			cout<<stk[top1]<<endl;
			stk[top1]=-1;
			top1=top1+1;
			//cout<<stk[top1]<<endl;
		}
	}
}
 
int peek(int s)
{
	if(s==0)
	{
		if(top0<0)
			cout<<"-1";
		else
			cout<<stk[top0];
	}
	if(s==1)
	{
		if(top1>n-1)
			cout<<"-1";
		else
			cout<<stk[top1];
	}
}

int isEmpty(int s)
{
	if(s==0)
	{
		if(top0<0)
			cout<<"1";
		else
			cout<<"0";
	}
	if(s==1)
	{
		if(top1>n-1)
			cout<<"1";
		else
			cout<<"0";
	}
}

int display(int s)
{
	int i;
	if(s==0)
	{
		if(top0<0)
			cout<<"stack 0 is empty"<<endl;
		else
		{
			for(i=0;i<=top0;i++)
				cout<<stk[i]<<endl;
		}
	}
	else
	{
		if(top1>n-1)
			cout<<"stack 1 is empty"<<endl;
		else
		{
			for(i=n-1;i>=top1;i--)
			{
				cout<<stk[i]<<endl;
			}
		}
	}
}



