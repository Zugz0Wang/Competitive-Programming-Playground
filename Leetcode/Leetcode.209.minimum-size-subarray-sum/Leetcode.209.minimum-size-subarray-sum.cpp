// @lc app=leetcode id=209 lang=cpp
// @lc code=start
class Solution { // Independently solved
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        size_t begin(0);
        size_t end(1);
        const size_t size(nums.size());
        int sum(nums.at(0));
        int ans(nums.size() + 1);
        while (end <= size && begin < end) {
            while (end < size && sum < target) {
                sum += nums.at(end);
                ++end;
            }
            if (sum >= target && end - begin < ans) {
                ans = end - begin;
            }
            sum -= nums.at(begin);
            ++begin;
        }
        if (ans > size) {
            return 0;
        }
        return ans;
    }
};
// @lc code=end