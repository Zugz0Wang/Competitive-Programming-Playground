/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 *
 * https://leetcode.com/problems/find-the-distance-value-between-two-arrays/description/
 *
 * algorithms
 * Easy (65.37%)
 * Likes:    644
 * Dislikes: 2399
 * Total Accepted:    72.1K
 * Total Submissions: 109.6K
 * Testcase Example:  '[4,5,8]\n[10,9,1,8]\n2'
 *
 * Given two integer arrays arr1 and arr2, and the integer d, return the
 * distance value between the two arrays.
 * 
 * The distance value is defined as the number of elements arr1[i] such that
 * there is not any element arr2[j] where |arr1[i]-arr2[j]| <= d.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr1 = [4,5,8], arr2 = [10,9,1,8], d = 2
 * Output: 2
 * Explanation: 
 * For arr1[0]=4 we have: 
 * |4-10|=6 > d=2 
 * |4-9|=5 > d=2 
 * |4-1|=3 > d=2 
 * |4-8|=4 > d=2 
 * For arr1[1]=5 we have: 
 * |5-10|=5 > d=2 
 * |5-9|=4 > d=2 
 * |5-1|=4 > d=2 
 * |5-8|=3 > d=2
 * For arr1[2]=8 we have:
 * |8-10|=2 <= d=2
 * |8-9|=1 <= d=2
 * |8-1|=7 > d=2
 * |8-8|=0 <= d=2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr1 = [1,4,2,3], arr2 = [-4,-3,6,10,20,30], d = 3
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr1 = [2,1,100,3], arr2 = [-5,-2,10,-3,7], d = 6
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr1.length, arr2.length <= 500
 * -1000 <= arr1[i], arr2[j] <= 1000
 * 0 <= d <= 100
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int abs(int a, int b) {
        if (a > b) {
            return a - b;
        } else {
            return b - a;
        }
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        const int kSize = arr2.size();
        int count = 0;
        for (int curr : arr1) {
            int head = 0;
            int tail = kSize;
            bool found = false;
            while (head < tail) {
                int mid_idx = (head + tail) / 2;
                int mid_val = arr2.at(mid_idx);
                //cout << mid_val << ' ';
                if (abs(curr, mid_val) > d) {
                    if (curr < mid_val) {
                        tail = mid_idx;
                    } else {
                        head = mid_idx + 1;
                    }
                } else {
                    
                    found = true;
                    break;
                }
            }
            if (found == false) {
                count += 1;

            }
            //cout << '\n';
        }
        return count;
    } // [1,4,2,3]\n[-4,-3,6,10,20,30]\n3
    //[-3,10,2,8,0,10]\n[-9,-1,-4,-9,-8]\n9
};
// @lc code=end

