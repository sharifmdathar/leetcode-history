#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sort_first(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort_first(intervals);
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            auto cur = intervals[i];
            if (cur[0] <= ans.back()[1]){
                ans.back()[1] = max(ans.back()[1], cur[1]);
            } else {
                ans.push_back(cur);
            }
        }
        for (auto x: ans) {
            cout << "[" << x[0] << "," << x[1] << "], ";
        }
        cout << endl;
        return ans;

    }
};


int main() {
    vector<vector<int>> arr1 = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> arr2 = {{1,4}, {4,5}};
    vector<vector<int>> arr3 = {{4,7},{1,4}};
    vector<vector<int>> arr4 = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    vector<vector<int>> arr5 = {{1,4},{2,3}};

    Solution sol;
    sol.merge(arr1);
    sol.merge(arr2);
    sol.merge(arr3);
    sol.merge(arr4);
    sol.merge(arr5);

}
