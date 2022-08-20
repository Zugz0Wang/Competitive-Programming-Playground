/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 *
 * https://leetcode.com/problems/jump-game-iv/description/
 *
 * algorithms
 * Hard (44.15%)
 * Likes:    2021
 * Dislikes: 80
 * Total Accepted:    77.7K
 * Total Submissions: 176.1K
 * Testcase Example:  '[100,-23,-23,404,100,23,23,23,3,404]'
 *
 * Given an array of integers arr, you are initially positioned at the first
 * index of the array.
 * 
 * In one step you can jump from index i to index:
 * 
 * 
 * i + 1 where: i + 1 < arr.length.
 * i - 1 where: i - 1 >= 0.
 * j where: arr[i] == arr[j] and i != j.
 * 
 * 
 * Return the minimum number of steps to reach the last index of the array.
 * 
 * Notice that you can not jump outside of the array at any time.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
 * Output: 3
 * Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that
 * index 9 is the last index of the array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [7]
 * Output: 0
 * Explanation: Start index is the last index. You do not need to jump.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [7,6,9,6,9,6,9,7]
 * Output: 1
 * Explanation: You can jump directly from index 0 to index 7 which is last
 * index of the array.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 5 * 10^4
 * -10^8 <= arr[i] <= 10^8
 * 
 * 
 */
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int kSize = arr.size();
        if (kSize <= 1) return 0;
        
        vector<bool> visited(kSize, false);
        unordered_map<int, vector<int>> neighbours;
        //unordered_map<int, unordered_set<int>> vip;
        queue<int> waitlist;

        for (int i = kSize - 1; i >= 0; i--) {
            int curr_val = arr.at(i);
            // if (vip.count(curr_val) == 0) {
            //     unordered_set<int> empty;
            //     vip.insert(pair<int, unordered_set<int>>(curr_val, empty));
            // }
            bool add = true;
            if (i > 0 && i < kSize - 1) {
                int prev_val = arr.at(i - 1);
                int next_val = arr.at(i + 1);
                if (prev_val == curr_val && next_val == curr_val) {
                    add = false;
                }
                // } else {
                //      unordered_set<int>& temp = vip.at(curr_val);
                //     if (temp.count(prev_val) > 0 && temp.count(next_val) > 0) {
                //         add = false;
                //     } else {
                //         temp.insert(prev_val);
                //         temp.insert(next_val);
                //     }
                // }
               
            }
            if (add) {
                if (neighbours.count(curr_val) > 0) {
                    neighbours.at(curr_val).push_back(i);
                } else {
                    neighbours.insert(pair<int, vector<int>>(curr_val, {i}));
                }
            }
        }
        // cout << "BFS\n";
        waitlist.push(0);
        visited.at(0) = true;
        int step = 0;
        while (!waitlist.empty()) {
            const int level_size = waitlist.size();
            int i = 0;
            while (i < level_size) {
                int curr_idx = waitlist.front();
                // cout << curr_idx << ' ';
                waitlist.pop();
                int next_idx = curr_idx + 1;
                int prev_idx = curr_idx - 1;
                if (next_idx == kSize) {
                    return step;
                }
                if (prev_idx >= 0 && visited.at(prev_idx) == false) {
                    visited.at(prev_idx) = true;
                    waitlist.push(prev_idx);
                }
                if (next_idx < kSize && visited.at(next_idx) == false) {
                    if (next_idx + 1 == kSize) {
                        return step + 1;
                    }
                    visited.at(next_idx) = true;
                    waitlist.push(next_idx);
                }
                int curr_val = arr.at(curr_idx);
                
                if (neighbours.count(curr_val)) {
                    vector<int>& next = neighbours.at(curr_val);
                    // cout << next.at(0) << ' ';
                    for (int j : next) {
                        if (visited.at(j) == false) {
                            if (j + 1 == kSize) {
                                return step + 1;
                            }
                            visited.at(j) = true;
                            waitlist.push(j);
                        }
                    }
                    neighbours.erase(curr_val);
                }
                
                i++;
            }
            // cout << '\n';
            step++;
        }
        return -1;
    }
};
// @lc code=end

