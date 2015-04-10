#include<iostream>
using namespace std;
class point
{
		public:
				int xcoor,ycoor;
				char *pointname;

				void setcoor(int x,int y,char *name)
				{
						xcoor=x;
						ycoor=y;
						pointname=name;
				}

				int getcoor()
				{
						return xcoor,ycoor;
				}

				void printpoint()
				{
						cout<<"x coordinate is: "<<xcoor<<endl;
						cout<<"y coordinate is: "<<ycoor;
						cout<<pointname;
				}

				void printquadrant()
				{
						if(xcoor>0 && ycoor>0)
							cout<<"1st quadrant";
						else if(xcoor>0 && ycoor<0)
							cout<<"2nd quadrant";
						else if(xcoor<0 && ycoor>0)
							cout<<"3rd quadrant";
						else
							cout<<"4th quadrant";
				}

};

int main()
{
		int xc=3,yc=4;
		char name[]="rathi";
		point p;
		p.setcoor(xc,yc,name);
		p.printpoint();
		cout<<endl;
		p.printquadrant();
		cout<<endl;
}
