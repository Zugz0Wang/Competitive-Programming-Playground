/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 *
 * https://leetcode.com/problems/find-k-closest-elements/description/
 *
 * algorithms
 * Medium (44.94%)
 * Likes:    5117
 * Dislikes: 460
 * Total Accepted:    328.3K
 * Total Submissions: 727.2K
 * Testcase Example:  '[1,2,3,4,5]\n4\n3'
 *
 * Given a sorted integer array arr, two integers k and x, return the k closest
 * integers to x in the array. The result should also be sorted in ascending
 * order.
 * 
 * An integer a is closer to x than an integer b if:
 * 
 * 
 * |a - x| < |b - x|, or
 * |a - x| == |b - x| and a < b
 * 
 * 
 * 
 * Example 1:
 * Input: arr = [1,2,3,4,5], k = 4, x = 3
 * Output: [1,2,3,4]
 * Example 2:
 * Input: arr = [1,2,3,4,5], k = 4, x = -1
 * Output: [1,2,3,4]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= arr.length
 * 1 <= arr.length <= 10^4
 * arr is sorted in ascending order.
 * -10^4 <= arr[i], x <= 10^4
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    int findInsertIdx(vector<int>& arr, int x) {
        int head = 0;
        int tail = arr.size() - 1;
        int mid = (head + tail) / 2;
        if (arr.at(head) > x) {
            return 0;
        }
        if (arr.at(tail) <= x) {
            return tail + 1;
        }
        while (head < tail) {
            mid = (head + tail) / 2;
            int prev = arr.at(mid);
            int next = arr.at(mid + 1);
            if (prev <= x && x < next) {
                return mid + 1;
            } else if (x < prev){
                tail = mid;
            } else {
                head = mid + 1;
            }
        }
        return mid;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        const int kSize = arr.size();
        vector<int> to_return;
        if (kSize == 0) {
            return to_return;
        }
        int idx1 = findInsertIdx(arr, x);
        int idx0 = idx1 - 1;cout << idx0;
        for (int i = 0; i < k; i++) {
            if (idx0 >= 0 && idx1 < kSize) {
                int prev = arr.at(idx0);
                int next = arr.at(idx1);
                if ((x - prev) <= (next - x)) {
                    to_return.push_back(prev);
                    idx0--;
                } else {
                    to_return.push_back(next);
                    idx1++;
                }
            } else if (idx0 >= 0) {
                to_return.push_back(arr.at(idx0));
                idx0--;
            } else if (idx1 < kSize) {
                to_return.push_back(arr.at(idx1));
                idx1++;
            }
        }
        sort(to_return.begin(), to_return.end());
        return to_return;
    }
};
// @lc code=end

