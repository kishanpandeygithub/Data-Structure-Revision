// rotate the array by the k step
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 3;
    for (int j = 0; j < k-1; j++)
    {
        int num = arr[n-1];
        for (int i = n-2; i >=0; i--)
        {
            arr[i +1] = arr[i];
        }
        arr[0] = num;
    }
    for(int i =0;i< n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}