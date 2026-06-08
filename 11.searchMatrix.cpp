#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int reqRow = 0;

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] <= target)
            {
                reqRow = i;
            }
            else
            {
                break;
            }
        }

        return binary_search(matrix[reqRow].begin(), matrix[reqRow].end(), target);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 23;
    cout << sol.searchMatrix(matrix, target) << endl;
    // vector<vector<int>> matrix = {{1}};
    // int target = 0;
    // cout << sol.searchMatrix(matrix, target) << endl;
    return 0;
}