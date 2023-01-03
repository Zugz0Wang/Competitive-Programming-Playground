/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 *
 * https://leetcode.com/problems/peak-index-in-a-mountain-array/description/
 *
 * algorithms
 * Medium (69.69%)
 * Likes:    4356
 * Dislikes: 1763
 * Total Accepted:    499K
 * Total Submissions: 719.9K
 * Testcase Example:  '[0,1,0]'
 *
 * An array arr a mountain if the following properties hold:
 * 
 * 
 * arr.length >= 3
 * There exists some i with 0 < i < arr.length - 1 such that:
 * 
 * arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
 * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
 * 
 * 
 * 
 * 
 * Given a mountain array arr, return the index i such that arr[0] < arr[1] <
 * ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
 * 
 * You must solve it in O(log(arr.length)) time complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [0,1,0]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [0,2,1,0]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [0,10,5,2]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= arr.length <= 10^5
 * 0 <= arr[i] <= 10^6
 * arr is guaranteed to be a mountain array.
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int head = 1;
        int tail = arr.size() - 1;
        while (head < tail) {
            int mid_idx = (head + tail) / 2;
            int prev = arr.at(mid_idx - 1);
            int curr = arr.at(mid_idx);
            int next = arr.at(mid_idx + 1);
            if (prev < curr && next < curr) {
                return mid_idx;
            } else if (prev < curr && curr < next) {
                head = mid_idx + 1;
            } else {
                tail = mid_idx;
            }
        }
        return -1;
    }
};
// @lc code=end

