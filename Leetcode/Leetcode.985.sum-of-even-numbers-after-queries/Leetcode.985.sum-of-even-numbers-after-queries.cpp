/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
 *
 * https://leetcode.com/problems/sum-of-even-numbers-after-queries/description/
 *
 * algorithms
 * Medium (61.11%)
 * Likes:    823
 * Dislikes: 243
 * Total Accepted:    72.3K
 * Total Submissions: 115.3K
 * Testcase Example:  '[1,2,3,4]\n[[1,0],[-3,1],[-4,0],[2,3]]'
 *
 * You are given an integer array nums and an array queries where queries[i] =
 * [vali, indexi].
 * 
 * For each query i, first, apply nums[indexi] = nums[indexi] + vali, then
 * print the sum of the even values of nums.
 * 
 * Return an integer array answer where answer[i] is the answer to the i^th
 * query.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4], queries = [[1,0],[-3,1],[-4,0],[2,3]]
 * Output: [8,6,2,4]
 * Explanation: At the beginning, the array is [1,2,3,4].
 * After adding 1 to nums[0], the array is [2,2,3,4], and the sum of even
 * values is 2 + 2 + 4 = 8.
 * After adding -3 to nums[1], the array is [2,-1,3,4], and the sum of even
 * values is 2 + 4 = 6.
 * After adding -4 to nums[0], the array is [-2,-1,3,4], and the sum of even
 * values is -2 + 4 = 2.
 * After adding 2 to nums[3], the array is [-2,-1,3,6], and the sum of even
 * values is -2 + 6 = 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1], queries = [[4,0]]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^4 <= nums[i] <= 10^4
 * 1 <= queries.length <= 10^4
 * -10^4 <= vali <= 10^4
 * 0 <= indexi < nums.length
 * 
 * 
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class FenwickTree {
public:
  FenwickTree(int size) {
    size_ = size + 1;
    frequency_table_.assign(size + 1, 0);
  }
  int RangeSumQuery(int upper_bound) {
    int sum = 0;
    for (; upper_bound > 0;
         upper_bound -= LeastSignificantOneBit(upper_bound)) {
      sum += frequency_table_.at(upper_bound);
    }
    return sum;
  }
  int RangeSumQuery(int lower_bound, int upper_bound) {
    return RangeSumQuery(upper_bound) - RangeSumQuery(lower_bound + 1);
  }
  void RangeUpdatePointQuery(int idx, int value) {
    idx += 1;
    for (; idx < size_; idx += LeastSignificantOneBit(idx)) {
      frequency_table_.at(idx) += value;
    }
  }

private:
  int size_ = 0;
  vector<int> frequency_table_;
  int LeastSignificantOneBit(int S) { return (S) & (-S); }
};

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int kSize = nums.size();
        FenwickTree tree(kSize);
        for (int i = 0; i < kSize; i++) {
            int curr = nums.at(i);
            if (curr % 2 == 0) {
                tree.RangeUpdatePointQuery(i, curr);
            }
        }
        vector<int> to_return;
        
        for (vector<int>& query : queries) {
            int idx = query.at(1);
            int val = query.at(0);
            int prev = nums.at(idx);
            
            if ((prev + val) % 2 == 0) {
                if (prev % 2 == 0) {
                    tree.RangeUpdatePointQuery(idx, val);
                } else {
                    cout << idx;
                    tree.RangeUpdatePointQuery(idx, prev + val);
                    cout << idx;
                }
            } else {
                if (prev % 2 == 0) {
                    tree.RangeUpdatePointQuery(idx, -prev);
                }
            }
            nums.at(idx) = prev + val;
            to_return.push_back(tree.RangeSumQuery(kSize));
        }
        return to_return;
    }
};
// @lc code=end

