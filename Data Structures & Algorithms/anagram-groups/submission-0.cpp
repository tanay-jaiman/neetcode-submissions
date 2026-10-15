class Solution {
public:
    string create_key(string s) {
        int count[26] = {0};
        string output = "#";

        for (char c : s) {
            int i = (int)(c - 'a');
            count[i]++;
        }

        for (int num : count) {
            output += to_string(num) + "#";
        }

        return output;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        for (string s : strs) {
            string key = create_key(s);

            if (hash.count(key)) hash[key].push_back(s);
            else hash[key] = {s};
        }

        vector<vector<string>> output;

        for (auto pair : hash) {
            output.push_back(pair.second);
        }

        return output;
    }
};
