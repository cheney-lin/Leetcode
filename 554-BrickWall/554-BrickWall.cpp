class Solution {
    public:
        int leastBricks(vector<vector<int>>& wall) {
            map<int, int> help;
            for (int i = 0; i < wall.size(); ++i) {
                int tmp_sum = 0;
                for (int j = 0; j < wall[i].size(); ++j) {
                    if (j == wall[i].size() - 1) {
                        break;
                    }
                    tmp_sum += wall[i][j];
                    if (help.find(tmp_sum) == help.end()) {
                        help[tmp_sum] = 1;
                    } else {
                        ++help[tmp_sum];
                    }
                }
            }

            int sum_max = 0;
            map<int,int>::iterator it = help.begin();
            while(it != help.end())
            {
                sum_max = max(sum_max, it->second);
                it++;
            }
            return (int)wall.size() - sum_max;
        }
};
