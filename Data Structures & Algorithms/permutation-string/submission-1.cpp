class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()) return false; // Shorter string can never contain a permutation

        // Create a hash map for s1
        unordered_map<char, int> hash;
        for (char c : s1) {
            if (hash.count(c)) hash[c]++;
            else hash[c] = 1;
        }

        int l = 0, r = 0;
        unordered_map<char, int> copy = hash;
        while (r < s2.length()) {
            if (!copy.count(s2[r])) {
                copy = hash;
                l++; r = l;
            }

            else {
                copy[s2[r]]--;

                if (!copy[s2[r]]) copy.erase(s2[r]);
                if (copy.empty()) return true;

                r++;
            }
        }

        return false;
    }
};
