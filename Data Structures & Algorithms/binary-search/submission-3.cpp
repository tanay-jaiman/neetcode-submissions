class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int mid = l + (r - l) / 2;

        while (l < r) {
            mid = l + (r - l) / 2;
            printf("%d\n", mid);

            if (nums[mid] == target) return mid;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }

        return nums[l] == target ? l : -1;
    }
};
