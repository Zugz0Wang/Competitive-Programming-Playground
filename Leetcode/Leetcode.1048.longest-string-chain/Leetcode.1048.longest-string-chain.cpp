class Solution { // Independently solved
public:
    int find_idx(const vector<string>& words, const string& prev) {
        int begin(0);
        int end(words.size());
        while (begin < end) {
            int mid_idx((begin + end) / 2);
            const string& mid_val(words.at(mid_idx));
            if (mid_val == prev) {
                return mid_idx;
            } else if (prev < mid_val) {
                end = mid_idx;
            } else {
                begin = mid_idx + 1;
            }
        }
        return -1;
    }
    int longestStrChain(vector<string>& words) {
        const int size(words.size());
        sort(words.begin(), words.end());
        vector<pair<int, int>> indices(size);
        for (int i(0); i < size; ++i) {
            indices.at(i) = {words.at(i).size(), i};
        }
        sort(indices.begin(), indices.end());
        vector<int> dp_v(size, 1);
        int ans(1);
        // cout << find_idx(words, "ba") << "!!\n";
        for (int i(0); i < size; ++i) {
            const int curr_idx(indices.at(i).second);
            const string& curr(words.at(curr_idx));
            if (curr.size() == 1) {
                continue;
            }
            const int curr_size(curr.size());
            int& curr_dp(dp_v.at(curr_idx));
            // cout << '\n';
            for (int j(0); j < curr_size; ++j) {
                string prev(curr.substr(0, j) + curr.substr(j + 1, curr_size - j - 1));
                int prev_idx(find_idx(words, prev));
                // cout << prev << '\n';
                if (prev_idx < 0) {
                    continue;
                }
                
                if (dp_v.at(prev_idx) + 1 > curr_dp) {
                    curr_dp = dp_v.at(prev_idx) + 1;
                    if (curr_dp > ans) {
                        ans = curr_dp;
                    }
                }
            }
        }
        return ans;
    }
};