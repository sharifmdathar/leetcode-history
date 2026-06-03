#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int l = 0, r = 1;
        int ans = nums[0];
        int curSum = nums[0];
        while (r < nums.size()) {
            if (curSum < 0) {
                curSum = nums[r];
            } else {
                curSum += nums[r];
            }
            ans = max(ans, curSum);
            r++;
        }
        cout << "Final = " << ans << endl;
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> arr1 = {2,-3,4,-2,2,1,-1,4};
    vector<int> arr2 = {-2,1,-3,4,-1,2,1,-5,4};
    // vector<int> arr1 = {-2,1};
    cout << sol.maxSubArray(arr1) << endl;
    cout << sol.maxSubArray(arr2) << endl;
}
