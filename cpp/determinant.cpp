#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void myprint(vector<vector<int> > &);
int main()
{
		vector<vector<int> > ::iterator i;
		vector<int>  ::iterator j;
		int k,l,n,elem;
		cin>>n;
		vector<vector<int> > matrix;
		for(k=0;k<n;k++)
		{
				vector<int> row;
				for(l=0;l<n;l++)
				{
						cin>>elem;
						row.push_back(elem);
				}		
				matrix.push_back(row);
		}
		//myprint(matrix);

}

void myprint(vector<vector<int> > &matrix)
{
		vector<vector<int> > ::iterator i;
		vector<int>  ::iterator j;
		for(i=matrix.begin();i!=matrix.end();i++)
		{
				for(j=i->begin();j!=i->end();j++)
				{
						
						cout<<*j<<" ";
				}
				cout<<endl;
		
		}

}

void determinant(vector<vector<int> > &matrix,int n)
{
		int i,j,j1,j2,det;
		vector<vector<int> > temp;
		if(n<=0)
				cout<<"invalid inputs";
		else if(n==1)
				det=matrix[0][0];
		else if(n==2)
		{
				det=matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
		}
		else
		{
				det=0;
				for(j1=0;j1<n;j1++)
				{
						for(i=1;i<n;i++)
						{
								j2=0;
								vector<int> subrow;
								for(j=0;j<n;j++)
								{
										if(j==j1)
												continue;
										subrow.push_back(matrix[i][j]);
										j2++;
								}
								temp.push_back(subrow);
						}
				}
				det=det+ pow(-1,j1+1)*matrix[0][j1]*determinant(temp,n-1);
		}
				
}
