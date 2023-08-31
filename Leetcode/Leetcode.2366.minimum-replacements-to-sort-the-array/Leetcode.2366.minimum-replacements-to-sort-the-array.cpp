class Solution { // Learned from solution
public:
    long long minimumReplacement(vector<int>& nums) {
        const size_t N(nums.size());
        long long ans(0);
        int prev(nums.at(N - 1));
        for (size_t i(N - 2); i < N; --i) {
            int curr(nums.at(i));
            if (curr > prev) {
                ans += ceil((double)curr / prev) - 1;
                if (curr % prev != 0) {
                    prev = curr / (ceil((double) curr / prev));
                }
            } else {
                prev = curr;
            }
        }
        return ans;
    }
};