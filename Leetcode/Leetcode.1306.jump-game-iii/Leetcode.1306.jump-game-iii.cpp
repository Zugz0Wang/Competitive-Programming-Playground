/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 *
 * https://leetcode.com/problems/jump-game-iii/description/
 *
 * algorithms
 * Medium (62.96%)
 * Likes:    3048
 * Dislikes: 74
 * Total Accepted:    160.6K
 * Total Submissions: 255.1K
 * Testcase Example:  '[4,2,3,0,3,1,2]\n5'
 *
 * Given an array of non-negative integers arr, you are initially positioned at
 * start index of the array. When you are at index i, you can jump to i +
 * arr[i] or i - arr[i], check if you can reach to any index with value 0.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [4,2,3,0,3,1,2], start = 5
 * Output: true
 * Explanation: 
 * All possible ways to reach at index 3 with value 0 are: 
 * index 5 -> index 4 -> index 1 -> index 3 
 * index 5 -> index 6 -> index 4 -> index 1 -> index 3 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [4,2,3,0,3,1,2], start = 0
 * Output: true 
 * Explanation: 
 * One possible way to reach at index 3 with value 0 is: 
 * index 0 -> index 4 -> index 1 -> index 3
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [3,0,2,1,2], start = 2
 * Output: false
 * Explanation: There is no way to reach at index 1 with value 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * 0 <= arr[i] < arr.length
 * 0 <= start < arr.length
 * 
 * 
 */
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int kSize = arr.size();
        queue<int> waitlist;
        unordered_set<int> visited; 
        waitlist.push(start);
        visited.insert(start);
        while (!waitlist.empty()) {
            int curr_idx = waitlist.front();
            waitlist.pop();
            int step = arr.at(curr_idx);
            if (step == 0) {
                return true;
            }
            int left_idx = curr_idx - step; // Left possible reachable index
            int right_idx = curr_idx + step; // Right possible reachable index
            if (left_idx >= 0 && left_idx < kSize && visited.count(left_idx) == 0) {
                waitlist.push(left_idx);
                visited.insert(left_idx);
            }
            if (right_idx >= 0 && right_idx < kSize && visited.count(right_idx) == 0) {
                waitlist.push(right_idx);
                visited.insert(right_idx);
            }
        }
        return false;
    }
};
// @lc code=end

