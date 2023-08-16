/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (46.48%)
 * Likes:    15518
 * Dislikes: 511
 * Total Accepted:    808.5K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * You are given an array of integers nums, there is a sliding window of size k
 * which is moving from the very left of the array to the very right. You can
 * only see the k numbers in the window. Each time the sliding window moves
 * right by one position.
 * 
 * Return the max sliding window.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation: 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], k = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved, but slow
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const size_t size(nums.size());
        vector<int> ans(size + 1 - k, 0);
        map<int, int> count;
        for (int i(0); i < k; ++i) {
            int curr(nums.at(i));
            if (count.count(curr) > 0) {
                count.at(curr) += 1;
            } else {
                count.insert(pair<int, int>(curr, 1));
            }
        }

        ans.at(0) = (*(count.rbegin())).first;
        for (size_t i(1); i < size + 1 - k; ++i) {
            int prev_val(nums.at(i - 1));
            int curr_val(nums.at(i + k - 1));
            // int curr(sums.at(i - 1) - nums.at(i - 1) + nums.at(i + k - 1));
            // cout << prev_val << ' ' << count.at(prev_val) << ' ' << curr_val << '\n';
            if (count.at(prev_val) > 1) {
                count.at(prev_val) -= 1;
            } else {
                count.erase(prev_val);
            }
            // cout << count.size() << '\n';
            if (count.count(curr_val) > 0) {
                count.at(curr_val) += 1;
            } else {
                count.insert(pair<int, int>(curr_val, 1));
            }

            int curr((*(count.rbegin())).first);
        
            ans.at(i) = curr;
        }
        return ans;
    }
};
// @lc code=end

