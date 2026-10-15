class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stack;

        for (const string& t: tokens) {
            if (t == "+" || t == "*" || t == "/" || t == "-") {
                int b = stack.top(); stack.pop();
                int a = stack.top(); stack.pop();

                if (t == "+") stack.push(a + b);
                if (t == "-") stack.push(a - b);
                if (t == "*") stack.push(a * b);
                if (t == "/") stack.push(a / b);
            }

            else {
                stack.push(stoi(t));
            }
        }

        int ret = stack.top(); stack.pop();
        return ret;
    }
};
