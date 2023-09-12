class Solution { // Independently solved
public:
    int minDeletions(string s) {
        vector<int> dp_v(26, 0);
        int* dp(dp_v.data());
        for (char c : s) {
            dp[c - 'a'] += 1;
        }
        sort(dp + 0, dp + 26);
        int count(0);
        size_t start(0);
        while (start < 26 && dp[start] == 0) {
            ++start;
        }

        for (size_t i(start + 1); i < 26; ++i) {
            
            size_t prev(i - 1);
            size_t curr(i);
            
            while (prev >= start && prev < 26 && dp[prev]> 0 && dp[prev] == dp[curr]) {
                dp[prev] -= 1;
                ++count;
                --prev;
                --curr;
            }
        }
        return count;
    }
};