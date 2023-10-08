class Solution { // Modified from solution; Tired today
public:
    int maxDotProduct(vector<int>& nums1_v, vector<int>& nums2_v) {
        size_t m(nums1_v.size());
        size_t n(nums2_v.size());

        int* nums1(nums1_v.data());
        int* nums2(nums2_v.data());

        vector<long> dp_v(n + 1, INT_MIN);
        long* dp(dp_v.data());

        for (size_t i = 0; i < m; i++) {
            long prev = 0;
            for (size_t j = 0; j < n; j++) {
                long tmp = dp[j + 1];
                dp[j + 1] = max(max(prev + (long)nums1[i] * nums2[j],(long)nums1[i] * nums2[j]), max(dp[j], dp[j + 1]));
                prev = tmp;  
            }
        }

        return (int)dp[n];
    }
};