class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int max = *(max_element(nums.begin(), nums.end()));
        int min = *(min_element(nums.begin(), nums.end()));
        vector<bool> list (max + abs(min) + 1, false);

        for (int num : nums) {
            list[num - min] = true;
        }

        int longest = 0, current = 0;
        for (bool val : list) {
            // printf("%d ", val);
            if (val) current++;
            else {
                if (current > longest) longest = current;
                current = 0;
            }
        }

        return longest > current ? longest : current;
    }
};
