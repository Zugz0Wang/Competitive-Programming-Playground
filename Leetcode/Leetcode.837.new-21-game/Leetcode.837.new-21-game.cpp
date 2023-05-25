/*
 * @lc app=leetcode id=837 lang=cpp
 *
 * [837] New 21 Game
 *
 * https://leetcode.com/problems/new-21-game/description/
 *
 * algorithms
 * Medium (36.12%)
 * Likes:    1402
 * Dislikes: 1049
 * Total Accepted:    44.7K
 * Total Submissions: 112.9K
 * Testcase Example:  '10\n1\n10'
 *
 * Alice plays the following game, loosely based on the card game "21".
 * 
 * Alice starts with 0 points and draws numbers while she has less than k
 * points. During each draw, she gains an integer number of points randomly
 * from the range [1, maxPts], where maxPts is an integer. Each draw is
 * independent and the outcomes have equal probabilities.
 * 
 * Alice stops drawing numbers when she gets k or more points.
 * 
 * Return the probability that Alice has n or fewer points.
 * 
 * Answers within 10^-5 of the actual answer are considered accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 10, k = 1, maxPts = 10
 * Output: 1.00000
 * Explanation: Alice gets a single card, then stops.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 6, k = 1, maxPts = 10
 * Output: 0.60000
 * Explanation: Alice gets a single card, then stops.
 * In 6 out of 10 possibilities, she is at or below 6 points.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 21, k = 17, maxPts = 10
 * Output: 0.73278
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= k <= n <= 10^4
 * 1 <= maxPts <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    int maxPts;
    int n;
    int k;
    // double helper(int start) {
    //     if (start >= k) {
    //         if (start <= n) {
    //             return 1.0;
    //         } else {
    //             return 0.0;
    //         }
    //     }
    //     double& curr(dp[start]);
    //     if (curr >= 0) {
    //         return curr;
    //     }
    //     double count(0);
    //     for (int i(1); start + i < k && i <= maxPts; ++i) {
    //         int next(start + i);
            
    //         count += helper(next);
            
    //     }
    //     int upper(start + maxPts);
    //     if (upper >= k) {
    //         if (upper >= n) {
    //             count += (n - k + 1);
    //         } else {
    //             count += (upper - k + 1);
    //         }
    //     }
        
    //     curr = count / maxPts;
    //     return curr;
    // }

    double* q;
    double prev = 0.0;
    int count = 0;
    int head = 0;
    int tail = 0;

    void pushProb(double p) {
        if (count >= maxPts) {
            prev -= q[head];
            head = (head + 1) % maxPts;
            --count;
        }
        q[tail] = p;
        prev += p;
        tail = (tail + 1) % maxPts;
        ++count;
        
    }

    double helper(int start) {
        if (start >= k) {
            return 1.0;
        }
        double count(prev);
        int upper(start + maxPts);
        if (upper >= k) {
            if (upper >= n) {
                count += (n - k + 1);
            } else {
                count += (upper - k + 1);
            }
        }
        double prob(count / maxPts);
        pushProb(prob);
        return prob;
    }

    double new21Game(int n_, int k_, int maxPts_) {
        n = n_;
        k = k_;
        maxPts = maxPts_;
        q = new double[maxPts];
        
        for (int i(k - 1); i >= 1; --i) {
            helper(i);
        }
        double ans(helper(0));
        delete[] q;
        return ans;
    }
};
// @lc code=end

