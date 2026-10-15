class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> hash;
        vector<int> output = {};

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            if (hash.count(num)) hash[num].push_back(i);
            else hash[num] = {i};
        }

        int index = 0;
        for (index = 0; index < nums.size(); index++) {
            int num = nums[index];

            if (hash.count(target - num)) {
                if (num == target - num && hash[num].size() > 1) {
                    output.push_back(index);
                    output.push_back(hash[num][1]);
                    break;
                }

                else if (num != target - num) {
                    output.push_back(index);
                    output.push_back(hash[target - num][0]);
                    break;
                }
            }
        }

        return output;
    }
};
