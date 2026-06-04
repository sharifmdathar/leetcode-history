#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int maxSubArray(const vector<int>& nums) {
        int r = 1;
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
    vector<int> arr1 = {2,-3,4,-2,2,1,-1,4};
    vector<int> arr2 = {-2,1,-3,4,-1,2,1,-5,4};
    // vector<int> arr1 = {-2,1};
    cout << Solution::maxSubArray(arr1) << endl;
    cout << Solution::maxSubArray(arr2) << endl;
}
