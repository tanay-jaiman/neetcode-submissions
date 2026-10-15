class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash;

        for (char c : s) {
            auto it = hash.find(c);

            if (it != hash.end()) hash[c] += 1;
            else hash[c] = 1;
        }

        for (char c : t) {
            auto it = hash.find(c);

            if (it != hash.end()) hash[c] -= 1;
            else return false;
        }

        for (auto it : hash) {
            if (it.second != 0) return false;
        }

        return true;
    }
};
