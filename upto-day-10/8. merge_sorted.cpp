#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i < m; i++)
        {
            swap(nums1[m - 1 - i], nums1[m + n - 1 - i]);
        }

        int i = 0, j = n, k = 0;
        while (i < m + n && j < m + n && k < n)
        {
            if (nums1[j] < nums2[k])
            {
                swap(nums1[i++], nums1[j++]);
            }
            else
            {
                swap(nums1[i++], nums2[k++]);
            }
        }

        while (j < m + n)
        {
            swap(nums1[i++], nums1[j++]);
        }

        while (k < n)
        {
            swap(nums1[i++], nums2[k++]);
        }

        for (int x : nums1)
        {
            cout << x << " ";
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0}, nums2 = {2, 5, 6};
    int m = 3, n = 3;
    sol.merge(nums1, 3, nums2, 3);
}
