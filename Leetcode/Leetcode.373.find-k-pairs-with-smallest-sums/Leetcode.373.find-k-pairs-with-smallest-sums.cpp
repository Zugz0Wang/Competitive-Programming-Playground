/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (38.49%)
 * Likes:    5476
 * Dislikes: 325
 * Total Accepted:    247.2K
 * Total Submissions: 614.2K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k.
 * 
 * Define a pair (u, v) which consists of one element from the first array and
 * one element from the second array.
 * 
 * Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest
 * sums.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
 * Output: [[1,2],[1,4],[1,6]]
 * Explanation: The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
 * Output: [[1,1],[1,1]]
 * Explanation: The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums1 = [1,2], nums2 = [3], k = 3
 * Output: [[1,3],[2,3]]
 * Explanation: All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums1.length, nums2.length <= 10^5
 * -10^9 <= nums1[i], nums2[i] <= 10^9
 * nums1 and nums2 both are sorted in ascending order.
 * 1 <= k <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    struct Info {
        int sum;
        int x;
        int y;
        Info(int s, int x_, int y_): sum(s), x(x_), y(y_) {}
        bool operator<(const Info& other) const {
            if (sum == other.sum) {
                if (x == other.x) {
                    return y < other.y;
                }
                return x < other.x;
            }
            return sum > other.sum;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        const size_t size1(nums1.size());
        const size_t size2(nums2.size());
        vector<int> xs(size1, 0);
        vector<int> ys(size2, 0);
        vector<vector<int>> ans;
        set<pair<int,int>> s;
        
        priority_queue<Info> pq;
        pq.push(Info(nums1.at(0) + nums2.at(0), 0, 0));
        for (int i(0); i < k; ++i) {
            if (pq.empty()) break;
            Info curr(pq.top());
            pq.pop();
            int x(curr.x);
            int y(curr.y);
            // cout << x << ' ' << y << '\n';
            ans.push_back({nums1.at(x), nums2.at(y)});
            int& y0(xs.at(x));
            int& x0(ys.at(y));
            y0 += 1;
            x0 += 1;
            if (y0 < size2 && s.count({x, y0}) == 0) {
                pq.push(Info(nums1.at(x) + nums2.at(y0), x, y0));
                s.insert({x, y0});
            }
            if (x0 < size1 && s.count({x0, y}) == 0) {
                pq.push(Info(nums1.at(x0) + nums2.at(y), x0, y));
                s.insert({x0, y});
            }
        }
        return ans;
    }
};
// @lc code=end

