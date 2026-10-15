class Solution {
    struct temp {
        int t; // temperature
        int i; // index 
    };

public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<temp> stack;
        vector<int> ret = vector<int>(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            const int t = temperatures[i];

            if (stack.empty() || t <= stack.top().t) {
                stack.push({t, i});
            }

            else if (t > stack.top().t) {
                while (!stack.empty() && t > stack.top().t) {
                    temp temp = stack.top(); stack.pop();
                    ret[temp.i] = i - temp.i; 
                }

                stack.push({t, i});
            }
        }

        while (!stack.empty()) {
            temp temp = stack.top(); stack.pop();
            ret[temp.i] = 0; 
        }

        return ret;
    }
};
