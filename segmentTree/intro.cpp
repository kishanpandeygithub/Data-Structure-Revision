#include <iostream>
#include <vector>
using namespace std;

void build(int ind, int st, int end, vector<int> &segment, vector<int> &arr)
{
    if (st == end)
    {
        segment[ind] = arr[end];
        return;
    }
    int mid = (st + end) / 2;
    build(2 * ind + 1, st, mid, segment, arr);
    build(2 * ind + 2, mid + 1, end, segment, arr);
    segment[ind] = segment[2 * ind + 1] + segment[ind * 2 + 2];
}
int main()
{
    vector<int> arr = {3 , 1 ,2 ,7};
    int n = arr.size();
    vector<int> segment(n*2, -1);
    build(0, 0, n - 1, segment, arr);

    for (int i = 0; i<2*n; i++)
    {
        cout << segment[i] << " ";
    }
    return 0;
}