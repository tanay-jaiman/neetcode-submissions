class Solution {
public:
    unordered_map<char, int> create_hash(string s) {
        unordered_map<char, int> hash;

        for (char c : s) {
            if (hash.count(c)) hash[c] += 1;
            else hash[c] = 1;
        }

        return hash;
    }

    bool isAnagram(string s, string t) {
        unordered_map<char, int> hash = create_hash(s);

        for (char c : t) {
            if (hash.count(c)) {
                hash[c] -= 1;
            }

            else return false;
        }

        for (auto p : hash) {
            if (p.second != 0) return false;
        }

        return true;
    }
};
