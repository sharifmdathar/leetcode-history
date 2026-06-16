#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void transpose(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void row_reverse(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        transpose(matrix);
        row_reverse(matrix);
        for (auto x: matrix) {
            for (auto y: x)
                cout << y << " ";
            cout << endl;
        }
    }
};


int main() {
    Solution sol;
    vector<vector<int>> arr1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> arr2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    sol.rotate(arr1);
    sol.rotate(arr2);
}
