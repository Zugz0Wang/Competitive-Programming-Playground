/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> exists;
        const int kSize = nums.size();
        bool duplicate_flag = false;
        for (int i = 0; i < kSize; i++) {
            int current = nums.at(i);
            if (exists.count(current) == 0) { // If not duplicate
                exists.insert(current);
            } else {
                duplicate_flag = true;
                break;
            }
        }
        return duplicate_flag;
    }
};
// @lc code=end

