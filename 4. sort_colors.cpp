class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high) {
            int el = nums[mid];
            if (el == 0) {
                swap(nums[low], nums[mid]);
                low++; mid++;
            } else if (el == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
