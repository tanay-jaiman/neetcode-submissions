class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0 || s.length() == 1) return s.length();

        int l = 0, r = 0, longest = 0;
        unordered_set<char> seen;

        while (r < s.length()) {
            printf("%s ", s.substr(l, r - l + 1).c_str());
            // if (r - l + 1 > longest) longest = r - l + 1;

            if (!seen.count(s[r])) {
                seen.insert(s[r++]);
                if (r - l + 1 > longest) longest = r - l + 1;
                continue;
            }

            if (seen.count(s[r])) {
                if (s[l] == s[r]) {
                    l++;
                    r++;
                }

                else {
                    seen.erase(s[l]);
                    l++;
                }
            }

            if (r - l + 1 > longest) longest = r - l + 1;
        }

        return longest > 0 ? longest - 1 : 0;
    }
};
