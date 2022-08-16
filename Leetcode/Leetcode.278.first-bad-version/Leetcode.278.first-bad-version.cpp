/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */
// The API isBadVersion is defined for you.
bool isBadVersion(int version);
// @lc code=start


class Solution {
public:
    int firstBadVersion(int n) { // Binary search the files.
        unsigned int head = 0; // Pervent overflow
        unsigned int tail = n;
        while (head < tail) {
            int mid = (head + tail) / 2;
            bool left = isBadVersion(mid);
            bool right = isBadVersion(mid + 1);
            if (left == right) { // If not found
                if (left == true) { // If both failed, search the left half
                    tail = mid;
                } else { // If both not failed, search the right half
                    head = mid + 1;
                }
            } else {    
                return mid + 1;
            }
        }
        return head;
    }
};
// @lc code=end

