#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithXorK(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<long long, int> mp(n);
        mp.insert({0, 1});
        int ans = 0;
        long long xr = 0;
        for (int i = 0; i < n; i++)
        {
            xr = xr ^ nums[i];
            long long req = xr ^ k;
            ans += mp[req];
            mp[xr]++;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << sol.subarraysWithXorK(nums, k);
}