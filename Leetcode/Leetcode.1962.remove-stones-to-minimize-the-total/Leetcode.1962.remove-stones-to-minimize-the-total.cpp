/*
 * @lc app=leetcode id=1962 lang=cpp
 *
 * [1962] Remove Stones to Minimize the Total
 *
 * https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/
 *
 * algorithms
 * Medium (57.92%)
 * Likes:    477
 * Dislikes: 36
 * Total Accepted:    26.9K
 * Total Submissions: 44.7K
 * Testcase Example:  '[5,4,9]\n2'
 *
 * You are given a 0-indexed integer array piles, where piles[i] represents the
 * number of stones in the i^th pile, and an integer k. You should apply the
 * following operation exactly k times:
 * 
 * 
 * Choose any piles[i] and remove floor(piles[i] / 2) stones from it.
 * 
 * 
 * Notice that you can apply the operation on the same pile more than once.
 * 
 * Return the minimum possible total number of stones remaining after applying
 * the k operations.
 * 
 * floor(x) is the greatest integer that is smaller than or equal to x (i.e.,
 * rounds x down).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: piles = [5,4,9], k = 2
 * Output: 12
 * Explanation: Steps of a possible scenario are:
 * - Apply the operation on pile 2. The resulting piles are [5,4,5].
 * - Apply the operation on pile 0. The resulting piles are [3,4,5].
 * The total number of stones in [3,4,5] is 12.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: piles = [4,3,6,7], k = 3
 * Output: 12
 * Explanation: Steps of a possible scenario are:
 * - Apply the operation on pile 2. The resulting piles are [4,3,3,7].
 * - Apply the operation on pile 3. The resulting piles are [4,3,3,4].
 * - Apply the operation on pile 0. The resulting piles are [2,3,3,4].
 * The total number of stones in [2,3,3,4] is 12.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= piles.length <= 10^5
 * 1 <= piles[i] <= 10^4
 * 1 <= k <= 10^5
 * 
 * 
 */
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        const int kSize = piles.size();
        for (int pile: piles) {
            pq.push(pile);
        }
        for (int i = 0; i < k; i++) {
            int curr = pq.top() + 1;
            pq.pop();
            pq.push(curr / 2);
        }
        int ans = 0;
        for (int i = 0; i < kSize; i++) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

