#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int merge(vector<int> &arr, int low, int mid, int high)
    {
        int toAdd = 0;
        vector<int> temp;
        int i = low, j = mid + 1;
        while (i <= mid && j <= high)
        {
            if (arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
            {
                temp.push_back(arr[j++]);
                toAdd += (mid - i + 1);
            }
        }
        while (i <= mid)
            temp.push_back(arr[i++]);

        while (j <= high)
            temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++)
            arr[low + k] = temp[k];
        return toAdd;
    };

    int mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return 0;
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        return merge(arr, low, mid, high);
    };

    long long int numberOfInversions(vector<int> nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};

int main()
{
    vector<int> nums1 = {2, 3, 7, 1, 3, 5};
    vector<int> nums2 = {-10, -5, 6, 11, 15, 17};
    Solution solution;
    cout << solution.numberOfInversions(nums1) << endl; // Output: 5
    cout << solution.numberOfInversions(nums2) << endl; // Output: 0
}