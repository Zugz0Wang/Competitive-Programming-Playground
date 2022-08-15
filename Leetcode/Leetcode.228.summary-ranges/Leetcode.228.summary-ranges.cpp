/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string rangeToString(int lower, int upper) {
        string to_return;
        if (lower == upper) {
            to_return = to_string(lower);
        } else {
            to_return = to_string(lower) + "->" + to_string(upper);
        }
        return to_return;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> to_return;
        const int kSize = nums.size();
        bool start = false;
        int lower_bound = 0;
        int upper_bound = 0;
        int i = 0;
        while (i < kSize) {
            lower_bound = nums.at(i);
            while (i + 1 < kSize && nums.at(i) + 1 == nums.at(i + 1)) { // If consecutive numbers
                i++;
            }
            upper_bound = nums.at(i);
            to_return.push_back(rangeToString(lower_bound, upper_bound));
            i++;
        }
        return to_return;
    }
};
// @lc code=end

