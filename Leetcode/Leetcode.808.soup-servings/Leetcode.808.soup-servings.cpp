/*
 * @lc app=leetcode id=808 lang=cpp
 *
 * [808] Soup Servings
 *
 * https://leetcode.com/problems/soup-servings/description/
 *
 * algorithms
 * Medium (42.82%)
 * Likes:    857
 * Dislikes: 2316
 * Total Accepted:    56K
 * Total Submissions: 100.8K
 * Testcase Example:  '50'
 *
 * There are two types of soup: type A and type B. Initially, we have n ml of
 * each type of soup. There are four kinds of operations:
 * 
 * 
 * Serve 100 ml of soup A and 0 ml of soup B,
 * Serve 75 ml of soup A and 25 ml of soup B,
 * Serve 50 ml of soup A and 50 ml of soup B, and
 * Serve 25 ml of soup A and 75 ml of soup B.
 * 
 * 
 * When we serve some soup, we give it to someone, and we no longer have it.
 * Each turn, we will choose from the four operations with an equal probability
 * 0.25. If the remaining volume of soup is not enough to complete the
 * operation, we will serve as much as possible. We stop once we no longer have
 * some quantity of both types of soup.
 * 
 * Note that we do not have an operation where all 100 ml's of soup B are used
 * first.
 * 
 * Return the probability that soup A will be empty first, plus half the
 * probability that A and B become empty at the same time. Answers within 10^-5
 * of the actual answer will be accepted.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 50
 * Output: 0.62500
 * Explanation: If we choose the first two operations, A will become empty
 * first.
 * For the third operation, A and B will become empty at the same time.
 * For the fourth operation, B will become empty first.
 * So the total probability of A becoming empty first plus half the probability
 * that A and B become empty at the same time, is 0.25 * (1 + 1 + 0.5 + 0) =
 * 0.625.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 100
 * Output: 0.71875
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution
public:
    double* dp;
    size_t size;
    double helper(int a, int b) {
        if (a <= 0) {
            if (b <= 0) {
                return 0.5;
            } else {
                return 1;
            }
        } else if (b <= 0) {
            return 0;
        }

        double& curr(dp[a * size + b]);
        if (curr >= 0) {
            return curr;
        }

        return curr = (helper(a - 4, b) + helper(a - 3, b - 1) + helper(a - 2, b - 2) + helper(a - 1, b - 3)) / 4;
    }

    double soupServings(int n) {
        if (n > 10000) {
            return 1;
        }
        if (n % 25 == 0) {
            n /= 25;
        } else {
            n = (n / 25 + 1);
        }
        size = n + 1;
        vector<double> dp_v(size * size, -1);
        dp = dp_v.data();
        return helper(n, n);
    }
};
// @lc code=end

