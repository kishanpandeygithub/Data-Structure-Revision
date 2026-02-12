#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

    int nums[] = {-4, 2, -1, 3, -2, 6, -5, 4, -1};

    int n = 9;
    int ans = -100000009;
    int sum = 0;
    int st = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        if (sum > ans)
        {
            ans = max(sum, ans);
            end = i;
        }

        if (sum < 0)
        {
            st = i + 1;
            sum = 0;
        }
    }
    cout << ans << " St is " << st << " end id " << end;
    for (int i = st; i <= end; i++)
    {
        cout << " " << nums[i] << " ";
    }
    return 0;
}