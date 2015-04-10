#include <iostream>
using namespace std;
#include "header.h"
int main()
{
		point p1,p2;
		vector v;
		p1.x=3;
		p1.y=4;
		p2.x=7;
		p2.y=8;
		p1.print();
		cout<<endl;
		v.start=p1;
		v.end=p2;
		v.offset(1,2);
		v.print();
		cout<<endl;
}
