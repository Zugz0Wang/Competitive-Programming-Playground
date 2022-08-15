/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> exists;
        const int kSize = nums.size();
        bool duplicate_flag = false;
        for (int i = 0; i < kSize; i++) {
            int current = nums.at(i);
            if (exists.count(current) == 0) { // If not duplicate
                exists.insert(pair<int,int>(current, i)); // Record the index
            } else {
                int prev_idx = exists.at(current); // The recorded nearest possible duplicated number
                if (i - prev_idx <= k) { // If a close enough index
                    duplicate_flag = true; // Duplicated
                    break;
                } else {
                    exists.at(current) = i;
                }
                
            }
        }
        return duplicate_flag;
    }
};
// @lc code=end

