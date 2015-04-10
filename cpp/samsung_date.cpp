#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


				string months []={
												"JAN",
												"FEB",
												"MAR",
												"APR",
												"MAT",
												"JUN",
												"JUL",
												"AUG",
												"SEP",
												"OCT",
												"NOV",
												"DEC"										};
class date
{
		public:
				int dd,yr;
				string mm;

		public:



date(int date,string month,int year)
{
		dd=date;
		mm=month;
		yr=year;
}

bool operator < (date dt1)
{
		int left,right;
		for(int i=0;i<12;i++)
		{
				if(mm==months[i])
						left=i;
		}

		for(int i=0;i<12;i++)
		{
				if(dt1.mm==months[i])
						right=i;
		}
		if(yr<dt1.yr)
				return 1;
		else if(yr==dt1.yr && left<right)
				return 1;
		else if(yr==dt1.yr && left==right && dd<dt1.dd)
				return 1;

		return 0;
}

};

		bool m_comp(string str1,string str2)
		{
				return(str1<str2);
		}


bool compare_date (date dt1,date dt2)
{
		return(dt1<dt2);
}

int main()
{
		date dt1(17,"JAN",1989),dt2(22,"OCT",1989),dt3(17,"APR",1989),dt4(17,"JAN",1989);
		vector<date> dates;
		dates.push_back(dt1);
		dates.push_back(dt2);
		dates.push_back(dt3);
		dates.push_back(dt4);

				cout<<(m_comp(dt1.mm,dt3.mm))<<endl;

				sort(dates.begin(),dates.end(),compare_date);
				for(int i=0;i<dates.size();i++)
						cout<<dates[i].dd<<dates[i].mm<<dates[i].yr<<endl;

				cout<<months[3]<<endl;

}
