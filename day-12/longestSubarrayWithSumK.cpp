#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int brute(vector<int> &arr, int k)
    {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long sm = 0;
            for (int j = i; j < n; j++)
            {
                sm += arr[j];

                if (sm == k)
                {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }

    int betterWIthPrefixSum(vector<int> &arr, int k)
    {
        unordered_map<long long, int> mp;
        int ans = INT_MIN;
        long long sm = 0;
        for (long unsigned int i = 0; i < arr.size(); i++)
        {
            int x = arr[i];
            sm += x;
            if (sm == k)
                ans = max(ans, (int)i + 1);
            long long req = sm - k;
            if (mp.find(req) != mp.end())
            {
                int len = i - mp[req];
                ans = max(ans, len);
            }
            if (mp.find(sm) == mp.end())
                mp.insert({sm, i});
        }
        return ans;
    }

    int mySol(vector<int> &arr, int k)
    {
        int ans = 0;
        int n = arr.size();
        int l = 0, r = 0;
        long long sm = arr[0];
        while (r < n)
        {
            while (l <= r && sm > k)
            {
                sm -= arr[l];
                l++;
            }
            if (sm == k)
            {
                ans = max(ans, r - l + 1);
            }
            if (r++ < n)
                sm += arr[r];
        }
        return ans;
    }

    int longestSubarrayWithSumK(vector<int> &arr, int k)
    {
        return mySol(arr, k);
    }
};

int main()
{
    Solution sol;
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << sol.longestSubarrayWithSumK(arr, k) << endl;
}