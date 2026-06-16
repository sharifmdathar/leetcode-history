#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int brute(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            int curX = nums[i];
            cout << curX;
            while (find(nums.begin(), nums.end(), curX + 1) != nums.end())
            {
                count += 1;
                curX += 1;
            }
            cout << " " << count << endl;
            ans = max(ans, count);
        }
        return ans;
    }

    int betterWithSort(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int longest = 1;
        int lastSeen = nums[0];
        int curRun = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == lastSeen)
            {
                continue;
            }
            if (nums[i] == lastSeen + 1)
            {
                curRun += 1;
                lastSeen = nums[i];
            }
            else
            {
                longest = max(longest, curRun);
                curRun = 1;
                lastSeen = nums[i];
            }
        }
        longest = max(longest, curRun);
        return longest;
    }

    int optimalWithSet(vector<int> &nums)
    {
        unordered_set<int> hs;
        for (int x : nums)
        {
            hs.insert(x);
        }
        int longest = 1;
        for (const int x : hs)
        {
            if (hs.find(x - 1) != hs.end())
            {
                continue;
            }
            int curMax = 1;
            while (hs.find(x + curMax) != hs.end())
            {
                curMax += 1;
            }
            longest = max(curMax, longest);
        }
        return longest;
    }
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        return betterWithSort(nums);
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    cout << sol.longestConsecutive(nums) << endl;
    return 0;
}