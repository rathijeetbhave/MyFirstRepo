#include<iostream>
#include<algorithm>
#include<set>
#include<iterator>
#include<vector>
using namespace std;

int main()
{
		set<string> names;
		set<string>::iterator iter;
		vector<string>::iterator viter;
		names.insert("peter");
		names.insert("adfsgsgs");
		vector<string> str;
		str.push_back("rathi");
		str.insert(str.begin(),"bhaskar");
		str.push_back("praveen");
		str.insert(str.begin()+2,"kirar");
		for(iter=names.begin();iter!=names.end();iter++)
		//for(int i=0;i<names.size();i++)
				cout<<*iter<<endl;

		for(int i=0;i<str.size();i++)
		//for(int i=0;i<names.size();i++)
				cout<<str[i]<<endl;

		sort(str.begin(),str.end());

		for(int i=0;i<str.size();i++)
		//for(int i=0;i<names.size();i++)
				cout<<str[i]<<endl;

		sort()
}
