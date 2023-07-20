/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 *
 * https://leetcode.com/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (44.36%)
 * Likes:    5788
 * Dislikes: 578
 * Total Accepted:    310.7K
 * Total Submissions: 694.6K
 * Testcase Example:  '[5,10,-5]'
 *
 * We are given an array asteroids of integers representing asteroids in a
 * row.
 * 
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 * 
 * Find out the state of the asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both will
 * explode. Two asteroids moving in the same direction will never meet.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: asteroids = [5,10,-5]
 * Output: [5,10]
 * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
 * collide.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: asteroids = [8,-8]
 * Output: []
 * Explanation: The 8 and -8 collide exploding each other.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: asteroids = [10,2,-5]
 * Output: [10]
 * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
 * resulting in 10.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= asteroids.length <= 10^4
 * -1000 <= asteroids[i] <= 1000
 * asteroids[i] != 0
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved (but TLE if not using stack and using 0s as placeholders)
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        const size_t size(asteroids.size());
        stack<int> s;
        for (size_t i(0); i < size; ++i) {
            // for (int i : asteroids) {
            //     cout << i << ' ';
            // }
            // cout << '\n';
            int curr(asteroids.at(i));
            if (curr > 0 || s.empty()) {
                s.push(curr);
            } else {
                while (!s.empty() && s.top() > 0 && s.top() < -curr) {
                    s.pop();
                }
                if (!s.empty() && s.top() == -curr) {
                    s.pop();
                } else if (s.empty() || s.top() < 0){
                    s.push(curr);
                }
            }
        }
        const size_t size1(s.size());
        asteroids.resize(size1);
        for (size_t i(size1 - 1); i < size1; --i) {
            asteroids.at(i) = s.top();
            s.pop();
        }
        return asteroids;
    }
};
// @lc code=end

