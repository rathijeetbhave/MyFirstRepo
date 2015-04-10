#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;

int find_index(string&,int,int);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long unsigned int t,i,index,right,left;
    cin>>t;
    cin.ignore();
    string str;
    for(i=0;i<t;i++)
    {
        getline(cin,str);
        left=0;
        right=str.length()-1;
        index=find_index(str,left,right);
        cout<<index<<endl;
    }
 return 0;
}


    
    
int find_index(string &str,int left,int right)
{
    if(left==right)
        return -1;
    else if(right-left==1 && str[left]==str[right])
        return -1;
    else if(right-left==1 && str[left]!=str[right])
        return left;
    else
    {
        if(str[left]==str[right])
            return find_index(str,left+1,right-1);
        else
        {
            if(str[left+1]==str[right])
                return left;
            else 
                return right;
        }
    }
        
}
    
   
