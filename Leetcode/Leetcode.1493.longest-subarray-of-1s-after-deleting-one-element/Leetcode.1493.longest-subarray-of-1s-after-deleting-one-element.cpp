// @lc app=leetcode id=1493 lang=cpp
// @lc code=start
class Solution { // Independently solved
public:
    int longestSubarray(vector<int>& nums) {
        bool prev_one(false);
        int prev_count(0);
        int count(0);
        int ans(0);
        bool hasOne(false);
        size_t hasZero(false);
        const size_t size(nums.size());
        for (size_t i(0); i <= size; ++i) {
            int num(0);
            if (i < size) {
                num = nums.at(i);
            }
            if (num == 0) {
                if (i < size) {
                    hasZero = true;
                }
                if (prev_one) {
                    if (prev_count + count > ans) {
                        ans = prev_count + count;
                    }
                }
                prev_count = count;
                count = 0;
                prev_one = false;
            } else {
                hasOne = true;
                count += 1;
                prev_one = true;
            }
        }
        if (!hasZero && hasOne) {
            return ans - 1;
        }
        return ans;
    }
};
// @lc code=end