#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int el = nums[0];
        int cnt = 0;

        for (int x : nums)
        {
            if (cnt == 0)
            {
                el = x;
                cnt = 1;
            }
            else if (x == el)
                cnt++;
            else
                cnt--;
        }
        return el;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    sol.majorityElement(nums);
}