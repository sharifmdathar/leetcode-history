#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> bruteForce(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                for (int k = j + 1; k < nums.size(); k++)
                {
                    for (int l = k + 1; l < nums.size(); l++)
                    {
                        if ((long long)nums[i] + nums[j] + nums[k] + nums[l] == target)
                        {
                            result.push_back({nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
        }
        return result;
    }
    vector<vector<int>> better(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                set<long long> hs;
                for (int k = j + 1; k < nums.size(); k++)
                {
                    long long sm = (long long)nums[i] + nums[j] + nums[k];
                    long long req = target - sm;

                    if (hs.find(req) != hs.end())
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], (int)req};
                        sort(temp.begin(), temp.end());
                        result.push_back(temp);
                    }
                    hs.insert(nums[k]);
                }
            }
        }
        return result;
    }

    vector<vector<int>> optimal(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int k = j + 1;
                int l = nums.size() - 1;

                while (k < l)
                {
                    long long sm = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if (sm == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        result.push_back(temp);
                        k++;
                        l--;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sm < target)
                    {
                        k++;
                    }
                    else
                    {
                        l--;
                    }
                }
            }
        }
        return result;
    }

    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        return optimal(nums, target);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, -1, 0, 0, 1, 2};
    int target = 0;
    vector<vector<int>> result = sol.fourSum(nums, target);

    for (const auto &quadruplet : result)
    {
        cout << "[";
        for (size_t i = 0; i < quadruplet.size(); ++i)
        {
            cout << quadruplet[i];
            if (i < quadruplet.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}