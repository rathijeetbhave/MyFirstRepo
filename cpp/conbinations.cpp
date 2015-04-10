#include<iostream>
#include<algorithm>
#include<random>
using namespace std;
void combinationUtil(int *,int* ,int ,int ,int,int );
void printCombination(int *,int,int);

static int counter;
void printCombination(int arr[], int n, int r)

{
    // A temporary array to store all combination one by one
    int data[r];
// 	static int count;
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, n-1, 0, r);
}
 
/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   start & end ---> Staring and Ending indexes in arr[]
   index  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void combinationUtil(int arr[], int data[], int start, int end, int index, int r)
{
	//static int count;
    // Current combination is ready to be printed, print it
    if (index == r)
    {
        //for (int j=0; j<r; j++)
        int j=0;
        	if((data[j]+data[j+1]<data[j+2])||(data[j+1]+data[j+2]<data[j])||(data[j]+data[j+2]<data[j+1]))
        		counter++;
            //cout<< data[j];
//        cout<<endl;;
        return;
    }
 
    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    std::sort(arr,arr+5);
    for(int i=0;i<5;i++)
    	cout<<arr[i];
    cout<<endl;
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
    cout<<counter<<endl;
}
