/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (65.24%)
 * Likes:    14915
 * Dislikes: 717
 * Total Accepted:    1.9M
 * Total Submissions: 2.8M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 * 
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 * 
 * Can you solve it without sorting?
 * 
 * 
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    size_t parent(size_t idx) {
        return ((idx + 1) / 2) - 1;
    }
    size_t left(size_t idx) {
        return (idx + 1) * 2 - 1;
    }
    size_t right(size_t idx) {
        return (idx + 1) * 2;
    }
    size_t size;
    int* nums;
    void down(size_t idx) {
        do {
            size_t l(left(idx));
            size_t r(right(idx));
            size_t next(0);
            if (l < size && r < size) {
                if (nums[l] > nums[r]) {
                    next = l;
                } else {
                    next = r;
                }
            } else if (l < size) {
                next = l;
            } else if (r < size) {
                next = r;
            } else {
                return;
            }

            if (nums[next] > nums[idx]) {
                swap(nums[next], nums[idx]);
                idx = next;
            } else {
                return;
            }
        } while (idx < size);
    }
    int findKthLargest(vector<int>& nums_, int k) {
        size = nums_.size();
        nums = nums_.data();
        for (size_t i(size / 2); i < size; --i) {
            down(i);
        }
        for (int i(0); i < k; ++i) {
            --size;
            swap(nums[size], nums[0]);
            down(0);
        }
        return nums[size];
    }
};
// @lc code=end

