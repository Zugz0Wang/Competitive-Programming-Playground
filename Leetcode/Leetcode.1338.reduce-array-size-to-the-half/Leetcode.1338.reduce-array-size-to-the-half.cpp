/*
 * @lc app=leetcode id=1338 lang=cpp
 *
 * [1338] Reduce Array Size to The Half
 *
 * https://leetcode.com/problems/reduce-array-size-to-the-half/description/
 *
 * algorithms
 * Medium (68.29%)
 * Likes:    2320
 * Dislikes: 124
 * Total Accepted:    132.1K
 * Total Submissions: 189K
 * Testcase Example:  '[3,3,3,3,5,5,5,2,2,7]'
 *
 * You are given an integer array arr. You can choose a set of integers and
 * remove all the occurrences of these integers in the array.
 * 
 * Return the minimum size of the set so that at least half of the integers of
 * the array are removed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [3,3,3,3,5,5,5,2,2,7]
 * Output: 2
 * Explanation: Choosing {3,7} will make the new array [5,5,5,2,2] which has
 * size 5 (i.e equal to half of the size of the old array).
 * Possible sets of size 2 are {3,5},{3,2},{5,2}.
 * Choosing set {2,7} is not possible as it will make the new array
 * [3,3,3,3,5,5,5] which has a size greater than half of the size of the old
 * array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [7,7,7,7,7,7]
 * Output: 1
 * Explanation: The only possible set you can choose is {7}. This will make the
 * new array empty.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr.length <= 10^5
 * arr.length is even.
 * 1 <= arr[i] <= 10^5
 * 
 * 
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> unique;
    unordered_map<int, int> counter;
    
    inline bool compareFunc (int i, int j) {
            return counter.at(i) > counter.at(j);
    }
    int minSetSize(vector<int>& arr) {
        const int kHalfSize = arr.size() / 2;
        for (int i : arr) {
            if (counter.count(i) > 0) {
                counter.at(i)++;
            } else {
                unique.push_back(i);
                counter.insert(pair<int, int>(i, 1));
            }
        }
        
        sort(unique.begin(), unique.end(), [this](int i, int j) {
            return compareFunc(i, j);
        });
        int total = 0;
        int count = 0;
        for (int i : unique) {
            if (total >= kHalfSize) {
                break;
            }
            total += counter.at(i);
            count++;
        }
        return count;
    }
};
// @lc code=end

