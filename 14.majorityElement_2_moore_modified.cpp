#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int el1, el2;
        int cnt1 = 0, cnt2 = 0;
        for (int x : nums)
        {
            if (cnt1 == 0 && x != el2)
            {
                el1 = x;
                cnt1 = 1;
            }
            else if (cnt2 == 0 && x != el1)
            {
                el2 = x;
                cnt2 = 1;
            }
            else if (x == el1)
            {
                cnt1++;
            }
            else if (x == el2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;
        for (int x : nums)
        {
            if (x == el1)
            {
                cnt1++;
            }
            else if (x == el2)
            {
                cnt2++;
            }
        }
        int mn = nums.size() / 3;
        vector<int> ans;
        if (cnt1 > mn)
            ans.push_back(el1);
        if (cnt2 > mn)
            ans.push_back(el2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
}