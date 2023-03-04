// @lc app=leetcode id=2444 lang=cpp
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) { // Learned from solution
        int kSize = nums.size();
        long long ans = 0;
        int last_min = -1;
        int last_max = -1;
        int last_bad = -1;

        for (int i = 0; i < kSize; ++i) {
            int num = nums.at(i);
            if (num == minK) {
                last_min = i;
            }
            if (num == maxK) {
                last_max = i;
            }
            if (num < minK || num > maxK) {
                last_bad = i;
            }
            if (last_bad < last_min && last_bad < last_max) {
                if (last_max < last_min) {
                    ans += last_max - last_bad;
                } else {
                    ans += last_min - last_bad;
                }
            }
        }

        return ans;
    }
};
// @lc code=end