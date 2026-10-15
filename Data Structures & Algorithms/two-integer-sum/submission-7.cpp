class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int want = target - nums[i];

            if (hash.count(want)) {
                return {hash[want], i};
            }

            hash[num] = i;
        }

        return {};
    
    }
};
