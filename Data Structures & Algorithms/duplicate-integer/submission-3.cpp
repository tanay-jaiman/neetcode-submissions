class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (int n : nums) {
            if (hash.count(n) > 0) hash[n] += 1;
            else hash[n] = 1;
        }

        for (auto pair : hash) {
            if (pair.second > 1) return true;
        }

        return false;
    }
};