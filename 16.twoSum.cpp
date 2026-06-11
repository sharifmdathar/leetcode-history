#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            auto it = indices.find(complement);
            if (it != indices.end())
            {
                return {i, it->second};
            }
            indices[nums[i]] = i;
        }
        return {};
    };
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 11, 7, 15};
    int target = 9;
    vector<int> ans = sol.twoSum(nums, target);
    for (int i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}