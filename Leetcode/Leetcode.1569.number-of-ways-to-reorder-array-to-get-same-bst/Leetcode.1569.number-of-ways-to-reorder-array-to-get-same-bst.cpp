/*
 * @lc app=leetcode id=1569 lang=cpp
 *
 * [1569] Number of Ways to Reorder Array to Get Same BST
 *
 * https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/
 *
 * algorithms
 * Hard (48.74%)
 * Likes:    636
 * Dislikes: 71
 * Total Accepted:    14.6K
 * Total Submissions: 28.9K
 * Testcase Example:  '[2,1,3]'
 *
 * Given an array nums that represents a permutation of integers from 1 to n.
 * We are going to construct a binary search tree (BST) by inserting the
 * elements of nums in order into an initially empty BST. Find the number of
 * different ways to reorder nums so that the constructed BST is identical to
 * that formed from the original array nums.
 * 
 * 
 * For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left
 * child, and 3 as a right child. The array [2,3,1] also yields the same BST
 * but [3,2,1] yields a different BST.
 * 
 * 
 * Return the number of ways to reorder nums such that the BST formed is
 * identical to the original BST formed from nums.
 * 
 * Since the answer may be very large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,1,3]
 * Output: 1
 * Explanation: We can reorder nums to be [2,3,1] which will yield the same
 * BST. There are no other ways to reorder nums which will yield the same
 * BST.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,4,5,1,2]
 * Output: 5
 * Explanation: The following 5 arrays will yield the same BST: 
 * [3,1,2,4,5]
 * [3,1,4,2,5]
 * [3,1,4,5,2]
 * [3,4,1,2,5]
 * [3,4,1,5,2]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: 0
 * Explanation: There are no other orderings of nums that will yield the same
 * BST.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= nums.length
 * All integers in nums are distinct.
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved; searched online for calculating "n choose k" and multiplicative inverse.
public:
    vector<int> copy;
    vector<int> nums;
    const int mod = 1e9 + 7;

    int mulInv(int n) {
        int p = mod - 2;
        long multiplier(n);
        long ans(1);
        while (p > 0) {
            if (p % 2 == 1) {
                ans = (ans * multiplier) % mod;
            }
            p /= 2;
            multiplier = (multiplier * multiplier) % mod;
        }
        return (int) ans;
    }

    int choose(size_t n, size_t k) {
        long ans(1);
        
        for (size_t i(0); i < k; ++i) {
            int mul(n - i);
            ans = (ans * mul) % mod;
        }
        long divide(1);
        for (size_t i(2); i <= k; ++i) {
            divide = (divide * i) % mod;
        }

        ans = (ans * mulInv(divide)) % mod;
        return (int) ans;
    }

    int helper(size_t begin, size_t end) {
        if (begin + 1 >= end) {
            return 1;
        }
        int root_val(nums.at(begin));
        begin += 1;
        size_t small_end(begin);
        size_t big_begin(end);
        for (size_t i(begin); i < end; ++i) {
            int curr_val(nums.at(i));
            if (curr_val < root_val) {
                copy.at(small_end) = curr_val;
                small_end += 1;
            } else {
                big_begin -= 1;
                copy.at(big_begin) = curr_val;
            }
        }
        // cout << begin << ' ' << small_end << ' ' << big_begin << ' ' << end << '\n';
        const size_t size(end - begin);
        const size_t small_size(small_end - begin);
        const size_t big_size(end - big_begin);

        for (size_t i(begin); i < small_end; ++i) {
            nums.at(i) = copy.at(i);
        }
        
        for (size_t i(0); i < big_size; ++i) {
            nums.at(big_begin + i) = copy.at(end - 1 - i);
        }

        long ans(choose(size, small_size));
        ans = (ans * helper(begin, small_end)) % mod;
        ans = (ans * helper(big_begin, end)) % mod;

        return (int)ans;
    }
    int numOfWays(vector<int>& nums_) {
        nums = nums_;
        copy.resize(nums.size());
        return helper(0, nums.size()) - 1;
    }
};
// @lc code=end

