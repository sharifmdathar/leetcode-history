#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        long long n = grid.size() * grid.size();
        long long sm = 0;
        long long sq_sm = 0;
        for (auto x : grid)
        {
            for (auto y : x)
            {
                sm += y;
                sq_sm += y * y;
            }
        }
        long long Sn = n * (n + 1) / 2;
        long long x_minus_y = Sn - sm;
        long long x2_minus_y2 = n * (n + 1) * (2 * n + 1) / 6 - sq_sm;
        long long x_plus_y = x2_minus_y2 / x_minus_y;
        int x = (x_minus_y + x_plus_y) / 2;
        int y = x_plus_y - x;
        return {y, x};
    }
};

int main()
{
    vector<vector<int>> grid1 = {{1, 3}, {2, 2}};
    vector<vector<int>> grid2 = {{1, 2, 3}, {3, 5, 6}, {7, 8, 9}};

    Solution solution;
    vector<int> result1 = solution.findMissingAndRepeatedValues(grid1);
    cout << "Missing value: " << result1[0] << ", Repeated value: " << result1[1] << endl;
    vector<int> result2 = solution.findMissingAndRepeatedValues(grid2);
    cout << "Missing value: " << result2[0] << ", Repeated value: " << result2[1] << endl;
}