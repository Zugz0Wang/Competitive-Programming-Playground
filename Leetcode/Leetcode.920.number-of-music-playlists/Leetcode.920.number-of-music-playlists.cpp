/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 *
 * https://leetcode.com/problems/number-of-music-playlists/description/
 *
 * algorithms
 * Hard (50.45%)
 * Likes:    956
 * Dislikes: 100
 * Total Accepted:    24.4K
 * Total Submissions: 47.1K
 * Testcase Example:  '3\n3\n1'
 *
 * Your music player contains n different songs. You want to listen to goal
 * songs (not necessarily different) during your trip. To avoid boredom, you
 * will create a playlist so that:
 * 
 * 
 * Every song is played at least once.
 * A song can only be played again only if k other songs have been played.
 * 
 * 
 * Given n, goal, and k, return the number of possible playlists that you can
 * create. Since the answer can be very large, return it modulo 10^9 + 7.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, goal = 3, k = 1
 * Output: 6
 * Explanation: There are 6 possible playlists: [1, 2, 3], [1, 3, 2], [2, 1,
 * 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 2, goal = 3, k = 0
 * Output: 6
 * Explanation: There are 6 possible playlists: [1, 1, 2], [1, 2, 1], [2, 1,
 * 1], [2, 2, 1], [2, 1, 2], and [1, 2, 2].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 2, goal = 3, k = 1
 * Output: 2
 * Explanation: There are 2 possible playlists: [1, 2, 1] and [2, 1, 2].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= k < n <= goal <= 100
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution
public:
    int k;
    int n;
    int* dp;
    static const int mod = 1e9 + 7;
    int helper(int remain, int goal) {
        if (remain == 0 && goal == 0) {
            return 1;
        }
        if (goal == 0 && remain > 0) {
            return 0;
        }
        // cout << remain << ' ' << goal << '\n';
        int& curr_dp(dp[goal * (n + 1) + remain]);
        if (curr_dp >= 0) {
            return curr_dp;
        }
        int can_relisten(n - remain - k);
        if (can_relisten < 0) {
            can_relisten = 0;
        }
        long long listen_new(0);
        if (remain > 0) {
            listen_new = ((long long)helper(remain - 1, goal - 1) * remain);
        }
        long long listen_old(0);
        if (can_relisten > 0) {
            listen_old = ((long long)helper(remain, goal - 1) * can_relisten);
        }

        curr_dp = (listen_new + listen_old) % mod;
        return curr_dp;
    }
    int numMusicPlaylists(int n_, int goal, int k_) {
        n = n_;
        k = k_;
        vector<int> dp_v((n + 1) * (goal + 1), -1);
        dp = dp_v.data();
        return helper(n, goal);
    }
};
// @lc code=end

