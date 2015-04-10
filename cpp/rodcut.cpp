#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cutrod(vector<int>& ,int,vector<int>&);
#define inf -2000;
int main()
{
	int n,c,elem;
	vector<int> vec,r;
	cin>>n;
	//for(int i=0;i<n;i++)
	while(!cin.eof())
	{
		cin>>elem;
		vec.push_back(elem);
	}
	
	for(int i=0;i<n+1;i++)
		r.push_back(-2000);
	for(int l=0;l<n+1;l++)
		cout<<r[l]<<" ";
	cout<<endl;
	r[0]=0;
	//int p[]={1,5,8,9,10,17,17,20,24,30};
	//vector<int> vec(p,p+sizeof(p) /sizeof(p[0]));
	c=cutrod(vec,n,r);
	cout<<c<<endl;
	return 0;
}

int cutrod(vector<int>& vec,int n,vector<int>& r)
{
	int i,j,q;
	
	for(j=1;j<=n;j++)
	{
		q=-2000;
		for(i=1;i<=j;i++)
		{
			q=max(q,vec[i-1]+r[j-i]);
		}
		r[j]=q;
	}
	return q;
}
	/*int q;
	if(r[n-1]>=0)
		return r[n];	
	if(n==0)
		q = 0;
	else
	{
		q=inf;
		for(int i=1;i<=n;i++)
		{
			q=max(q,vec[i-1]+cutrod(vec,n-i,r));
				
		}
		r[n]=q;
	}	
		
	return q;
}*/
