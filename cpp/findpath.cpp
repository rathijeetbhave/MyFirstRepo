#include <iostream>
using namespace std;
void findpath(int,int,int);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t,M,N,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>M;
        
        cin>>N;
        
        
        findpath(M,N,0);
            
    }
  /*  for(i=0;i<t;i++)
    {
        cout<<M[i]<<" "<<N[i]<<endl;
    }*/
    
    
    return 0;
}

void findpath(int M,int N,int count)
{
    
    if(M==N)
    {
        if(M==1)
            cout<<count<<endl;
        else
            cout<<"-1"<<endl;
    }
    else if(M<N)
    {
        count++;
        findpath(M,N-M,count);
    }
    else
    {
        count++;
        findpath(M-N,N,count);
    }
        
}
