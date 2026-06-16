#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        long long left = low;
        long long right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (long long i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    long long countPairs(vector<int> &arr, long long low, long long mid, long long high)
    {
        long long right = mid + 1;
        long long cnt = 0;
        for (long long i = low; i <= mid; i++)
        {
            while (right <= high && arr[i] > 2LL * arr[right])
                right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {
        long long cnt = 0;
        if (low >= high)
            return cnt;
        long long mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += countPairs(arr, low, mid, high);
        merge(arr, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int> &nums)
    {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
