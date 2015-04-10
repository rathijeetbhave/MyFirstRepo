#include<iostream>
using namespace std;
void areaperi(int,float &,float &);
int main()
{
	int *p,i,r;
	float area,peri;
	i=20;
	cout<<"enter radius";
	cin>>r;
	p=&i;
	area=peri=0;
	areaperi(r,area,peri);
	cout<< "area is   "<<area<<endl<<peri<<endl;
	//cout<<peri<<endl;
	return 0;
}

void areaperi(int r,float &a,float &p)
{
	a=3.14*r*r;
	p=2*3.14*r;
}
