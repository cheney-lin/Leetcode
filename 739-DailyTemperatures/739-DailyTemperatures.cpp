class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> res(temperatures.size(), 0);
            stack<int> help;
            for (int i = 0; i < temperatures.size(); ++i) {
                while (!help.empty()) {
                    if (temperatures[i] > temperatures[help.top()]) {
                        res[help.top()] = i - help.top();
                        help.pop();
                    } else {
                        break;
                    }
                }
                help.push(i);
            }
            return res;
        }
};
