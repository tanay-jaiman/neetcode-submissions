class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;

        for (int i : nums) {
            if (hash.count(i)) hash[i]++;
            else hash[i] = 1;

            if (hash[i] > 1) return true;
        }

        return false;
    }
};