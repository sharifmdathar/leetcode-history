#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        int mini = INT_MAX;

        for (int x: prices) {
            // if (x < mini) mini = x;
            cout << x << " " << ans << " " << mini << endl;
            mini = min(mini, x);
            ans = max(ans, x - mini);
        }
        return ans;
    }
};


int main() {
    vector<int> arr =  {7,6,4,3,1};
    Solution sol;
    cout << sol.maxProfit(arr);
}
