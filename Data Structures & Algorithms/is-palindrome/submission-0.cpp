class Solution {
public:
    string remove_non_alphanum(string s) {
        string out;
        for (char c : s) {
            if (isalnum(c)) out += c;
        }

        printf("%s", out.c_str());
        return out;
    }

    bool isPalindrome(string s) {
        s = remove_non_alphanum(s);
        int l = 0, r = s.length() - 1;

        while (l < r) {
            if (tolower(s[l]) != tolower(s[r])) return false;
            l++; r--;
        }

        return true;
    }
};
