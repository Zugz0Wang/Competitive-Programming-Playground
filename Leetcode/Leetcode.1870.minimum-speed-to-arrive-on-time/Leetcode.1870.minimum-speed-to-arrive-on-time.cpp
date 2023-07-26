/*
 * @lc app=leetcode id=1870 lang=cpp
 *
 * [1870] Minimum Speed to Arrive on Time
 *
 * https://leetcode.com/problems/minimum-speed-to-arrive-on-time/description/
 *
 * algorithms
 * Medium (37.04%)
 * Likes:    922
 * Dislikes: 119
 * Total Accepted:    33.5K
 * Total Submissions: 83.8K
 * Testcase Example:  '[1,3,2]\n6'
 *
 * You are given a floating-point number hour, representing the amount of time
 * you have to reach the office. To commute to the office, you must take n
 * trains in sequential order. You are also given an integer array dist of
 * length n, where dist[i] describes the distance (in kilometers) of the i^th
 * train ride.
 * 
 * Each train can only depart at an integer hour, so you may need to wait in
 * between each train ride.
 * 
 * 
 * For example, if the 1^st train ride takes 1.5 hours, you must wait for an
 * additional 0.5 hours before you can depart on the 2^nd train ride at the 2
 * hour mark.
 * 
 * 
 * Return the minimum positive integer speed (in kilometers per hour) that all
 * the trains must travel at for you to reach the office on time, or -1 if it
 * is impossible to be on time.
 * 
 * Tests are generated such that the answer will not exceed 10^7 and hour will
 * have at most two digits after the decimal point.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: dist = [1,3,2], hour = 6
 * Output: 1
 * Explanation: At speed 1:
 * - The first train ride takes 1/1 = 1 hour.
 * - Since we are already at an integer hour, we depart immediately at the 1
 * hour mark. The second train takes 3/1 = 3 hours.
 * - Since we are already at an integer hour, we depart immediately at the 4
 * hour mark. The third train takes 2/1 = 2 hours.
 * - You will arrive at exactly the 6 hour mark.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dist = [1,3,2], hour = 2.7
 * Output: 3
 * Explanation: At speed 3:
 * - The first train ride takes 1/3 = 0.33333 hours.
 * - Since we are not at an integer hour, we wait until the 1 hour mark to
 * depart. The second train ride takes 3/3 = 1 hour.
 * - Since we are already at an integer hour, we depart immediately at the 2
 * hour mark. The third train takes 2/3 = 0.66667 hours.
 * - You will arrive at the 2.66667 hour mark.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: dist = [1,3,2], hour = 1.9
 * Output: -1
 * Explanation: It is impossible because the earliest the third train can
 * depart is at the 2 hour mark.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == dist.length
 * 1 <= n <= 10^5
 * 1 <= dist[i] <= 10^5
 * 1 <= hour <= 10^9
 * There will be at most two digits after the decimal point in hour.
 * 
 * 
 */

// @lc code=start
class Solution { // Hinted
public:
    int* dist;
    size_t size;
    double helper(int speed) {
        double hour(0);
        for (size_t i(0); i < size; ++i) {
            int curr(dist[i]);
            if (curr % speed == 0) {
                hour += curr / speed;
            } else {
                if (i < size - 1) {
                    hour += curr / speed + 1;
                } else {
                    hour += (double) curr / speed;
                }
            }
        }
        return hour;
    }
    int minSpeedOnTime(vector<int>& dist_, double hour) {
        dist = dist_.data();
        size = dist_.size();
        int begin(1);
        int end(2);
        for (size_t i(0); i < size; ++i) {
            if (end < dist[i]) {
                end = dist[i];
            }
        }
        if (hour != (int)hour) {
            end /= hour - (int)hour;
        }
        
        end += 2;
        bool found(false);
        while (begin < end) {
            int mid((begin + end) / 2);
            double mid_val(helper(mid));
            // if (mid_val == hour) {
            //     return mid;
            // } else 
            if (mid_val <= hour) {
                end = mid;
                found = true;
            } else {
                begin = mid + 1;
            }
        }
        
        // cout << helper(3);
        if (!found) {
            return -1;
        }
        return begin;
    }
};
// @lc code=end

