#include "header.h"

void point::offset(double offsetx,double offsety)
{
		x+=offsetx;
		y+=offsety;
}

void point::print() const
{
		cout<<"("<<x<<","<<y<<")";
}

void vector::offset(double offsetx,double offsety)
{
		start.offset(offsetx,offsety);
		end.offset(offsetx,offsety);
}

void vector::print() const
{
		start.print();
		cout<<"->";
		end.print();
}
