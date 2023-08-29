class Solution { // Independently solved
public:
    int bestClosingTime(string customers) {
        const size_t N(customers.size());
        vector<int> count_v(N + 1, 0);
        int* count(count_v.data());
        for (size_t i(0); i < N; ++i) {
            count[i + 1] = count[i] + (int)(customers.at(i) == 'Y');
        }
        int total(count[N]);
        int min_idx(0);
        int min_val(total);

        for (size_t i(1); i <= N; ++i) {
            int curr(i + total - count[i] * 2 );
            // cout << curr << ' ';
            if (curr < min_val) {
                min_idx = i;
                min_val = curr;
            }
        }
        
        return min_idx;
    }
};