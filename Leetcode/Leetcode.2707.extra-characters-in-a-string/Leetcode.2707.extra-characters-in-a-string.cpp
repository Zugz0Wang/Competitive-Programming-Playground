class Solution { // Hinted
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        const size_t size(s.size());
        vector<int> dp_v(size + 1, size);
        int* dp(dp_v.data());
        dp[0] = 0;
        set<string> st;
        for (const string& word : dictionary) {
            st.insert(word);
        }
        for (size_t i(1); i <= size; ++i) {
            dp[i] = dp[i - 1] + 1;
            for (size_t w_size(i); w_size <= i; --w_size) { // I suppose I can use a prefix tree here
                const size_t prev(i - w_size);
                // cout << s.substr(prev, w_size) << '\n';
                if (st.contains(s.substr(prev, w_size)) && dp[i] > dp[prev]) {
                    dp[i] = dp[prev];
                    
                }
            }
        }
        return dp[size];
    }
};