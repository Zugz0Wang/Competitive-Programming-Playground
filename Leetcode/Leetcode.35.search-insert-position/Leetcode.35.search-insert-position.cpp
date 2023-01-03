// @lc app=leetcode id=35 lang=cpp
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0;
        int mid = 0;
        int tail = nums.size();
        if (target < nums.at(head)) {
            return 0;
        }
        if (target > nums.at(tail - 1)) {
            return tail;
        }
        while (head < tail) { // Binary search
            mid = (head + tail) / 2;
            // cout << head << ' ' << mid << ' ' << tail << '\n';
            int curr_int = nums.at(mid);
            if (curr_int == target) {
                return mid;
            } else if (curr_int < target) {
                head = mid + 1;
            } else {
                tail = mid;
            }
        }
        mid = (head + tail) / 2; // Update mid
        return mid;
    }
};
// @lc code=end