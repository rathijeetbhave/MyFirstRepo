#include<iostream>
using namespace std;

class point
{
		public:
			double x,y;
			void offset(double offsetx,double offsety);
			void print() const; 
};

class vector
{
		public:
				point start,end;
				void offset(double offsetx,double offsety);
				void print() const;
};

