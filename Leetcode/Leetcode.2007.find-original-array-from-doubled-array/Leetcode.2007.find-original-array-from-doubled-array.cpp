/*
 * @lc app=leetcode id=2007 lang=cpp
 *
 * [2007] Find Original Array From Doubled Array
 *
 * https://leetcode.com/problems/find-original-array-from-doubled-array/description/
 *
 * algorithms
 * Medium (38.43%)
 * Likes:    765
 * Dislikes: 55
 * Total Accepted:    52.1K
 * Total Submissions: 134.7K
 * Testcase Example:  '[1,3,4,2,6,8]'
 *
 * An integer array original is transformed into a doubled array changed by
 * appending twice the value of every element in original, and then randomly
 * shuffling the resulting array.
 * 
 * Given an array changed, return original if changed is a doubled array. If
 * changed is not a doubled array, return an empty array. The elements in
 * original may be returned in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: changed = [1,3,4,2,6,8]
 * Output: [1,3,4]
 * Explanation: One possible original array could be [1,3,4]:
 * - Twice the value of 1 is 1 * 2 = 2.
 * - Twice the value of 3 is 3 * 2 = 6.
 * - Twice the value of 4 is 4 * 2 = 8.
 * Other original arrays could be [4,3,1] or [3,1,4].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: changed = [6,3,0,1]
 * Output: []
 * Explanation: changed is not a doubled array.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: changed = [1]
 * Output: []
 * Explanation: changed is not a doubled array.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= changed.length <= 10^5
 * 0 <= changed[i] <= 10^5
 * 
 * 
 */
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        const int kSize = changed.size();
        if (kSize % 2 == 1) return {};
        vector<int> to_return;
        vector<int> keys;
        unordered_map<int, int> mp;
        for (int i : changed) {
            mp[i]++;
        }
        for (pair<int,int> i : mp) {
            keys.push_back(i.first);
        }
        sort(keys.begin(), keys.end(), [](int a, int b) {return abs(a) < abs(b);});
        for (int key : keys) {
            int key2 = 2 * key;
            // cout << key << ' ';
            if (mp[key] > mp[key2]) return {};
            for (int i = 0; i < mp.at(key); i++) {
                mp.at(key2)--;
                to_return .push_back(key);
            }
        }
        return to_return;
    }
};
// @lc code=end

