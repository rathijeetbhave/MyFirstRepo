#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main()
{
	ifstream infile;
	ofstream outfile;
	infile.open("inputfile.txt");

	if(!infile.is_open())
	{
		cout<<"file not found"<<endl;	/*Check for filename errors*/
		exit(0);
	}

	outfile.open("outputfile.txt");
	int i,op,s,elem,n;
	infile>> n;
	int top0=-1,top1=n;

	int *stk;
	stk=(int*)malloc(n);			/*Make a new array*/

	for(i=0;i<n;i++)
		stk[i]=-1;			/*assign all values in array to -1*/


	while(!infile.eof())			/*Program starts here*/
	{
		infile>> op;
		infile>> s;
		if(op==0)
			infile>>elem;
		if(infile.eof())
			break;
		switch(op)
		{
			case 0:			/*Case for push*/
			{
				if(s==0)
				{
					if(stk[top0+1]!=-1)
						outfile<<"-1"<<endl;
					else
					{
						top0=top0+1;
						stk[top0]=elem;
						outfile<<"1"<<endl;
					}
				}
				if(s==1)
				{
					if(stk[top1-1]!=-1)
						outfile<<"-1"<<endl;
					else
					{
						top1=top1-1;			
						stk[top1]=elem;
						outfile<<"1"<<endl;
					}		
				}
			}
				break;

			case 1:				/*Case for pop*/
			{
				if(s==0)
				{
					if(top0<0)
						outfile<<"-1"<<endl;
					else
					{
						outfile<<stk[top0]<<endl;
						stk[top0]=-1;
						top0=top0-1;
					}
				}
	
				if(s==1)		
				{
					if(top1>n-1)
						outfile<<"-1"<<endl;
					else
					{
						outfile<<stk[top1]<<endl;
						stk[top1]=-1;
						top1=top1+1;
					}
				}
			}
			break;

			case 2:			/*Case for peek*/			
			{
				if(s==0)
				{
					if(top0<0)
						outfile<<"-1"<<endl;
					else
						outfile<<stk[top0]<<endl;
				}
				if(s==1)
				{
					if(top1>n-1)
						outfile<<"-1"<<endl;
					else
						outfile<<stk[top1]<<endl;
				}
			}
			break;

			case 3:		/*Case for IsEmpty*/
			{
				if(s==0)
				{
					if(top0<0)
						outfile<<"1"<<endl;
					else
						outfile<<"0"<<endl;
				}
				if(s==1)
				{
					if(top1>n-1)
						outfile<<"1"<<endl;
					else
						outfile<<"0"<<endl;
				}
			}
				break;
		}
	}
	infile.close();
	outfile.close();
	return 0;
}


	

