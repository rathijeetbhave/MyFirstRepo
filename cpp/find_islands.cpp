#include<iostream>
using namespace std;
#define  col 5

int count_islands(int [][col]);
int main()
{
		int a[][col]={	
										{1,1,0,0,0},
										{0,1,0,0,1},
										{1,0,0,1,1},
										{0,0,0,0,0},
										{1,0,1,0,1}
								 };
		cout<<"no. of islands = "<<count_islands(a[][col]);
		return 0;
}

count_islands(a[][col])
{
		bool visited[row][col]={0};


}
