#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string str;
    char ch,tenp;
    int i,count=0;
    getline (cin,str);
    tenp=str[0];
    ch='d';
    //cout<<int(ch);
   //cout<<tolower('W')<<" "<<int('w');
    
   // cout<<char(tolower(tenp));    
    for(ch='a';ch<='z';ch++)
    {
        for(i=0;i<str.length();i++)
        {
            tenp=str[i];
            if(tolower(str[i])>=int(ch))
            {
                if(tolower(tenp)==ch)
                {
                    count++;
                    break;
                }
            }
        }
        
    }
    if(count==26)
        cout<<"pangram";
    else
        cout<<"not pangram";
    return 0;
}

