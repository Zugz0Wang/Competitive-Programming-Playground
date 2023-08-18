/*
 * @lc app=leetcode id=1615 lang=cpp
 *
 * [1615] Maximal Network Rank
 *
 * https://leetcode.com/problems/maximal-network-rank/description/
 *
 * algorithms
 * Medium (57.74%)
 * Likes:    1519
 * Dislikes: 245
 * Total Accepted:    81.1K
 * Total Submissions: 132.1K
 * Testcase Example:  '4\n[[0,1],[0,3],[1,2],[1,3]]'
 *
 * There is an infrastructure of n cities with some number of roads connecting
 * these cities. Each roads[i] = [ai, bi] indicates that there is a
 * bidirectional road between cities ai and bi.
 * 
 * The network rank of two different cities is defined as the total number of
 * directly connected roads to either city. If a road is directly connected to
 * both cities, it is only counted once.
 * 
 * The maximal network rank of the infrastructure is the maximum network rank
 * of all pairs of different cities.
 * 
 * Given the integer n and the array roads, return the maximal network rank of
 * the entire infrastructure.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: n = 4, roads = [[0,1],[0,3],[1,2],[1,3]]
 * Output: 4
 * Explanation: The network rank of cities 0 and 1 is 4 as there are 4 roads
 * that are connected to either 0 or 1. The road between 0 and 1 is only
 * counted once.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: n = 5, roads = [[0,1],[0,3],[1,2],[1,3],[2,3],[2,4]]
 * Output: 5
 * Explanation: There are 5 roads that are connected to cities 1 or 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 8, roads = [[0,1],[1,2],[2,3],[2,4],[5,6],[5,7]]
 * Output: 5
 * Explanation: The network rank of 2 and 5 is 5. Notice that all the cities do
 * not have to be connected.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 100
 * 0 <= roads.length <= n * (n - 1) / 2
 * roads[i].length == 2
 * 0 <= ai, bi <= n-1
 * ai != bi
 * Each pair of cities has at most one road connecting them.
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved
public:
    int n;
    bool neighbor(int a, int b, const set<size_t>& s) {
        if (a > b) {
            swap(a, b);
        }
        return  s.contains(a * n + b);
    }
    int maximalNetworkRank(int n_, vector<vector<int>>& roads) {
        n = n_;
        set<size_t> s;
        vector<size_t> degrees(n, 0);
        for (int i(0); i < n; ++i) {
            degrees.at(i) = i;
        }
        for (auto road : roads) {
            int a(road.at(0));
            int b(road.at(1));
            if (a > b) {
                swap(a, b);
            }
            s.insert(a * (n) + b);
            degrees.at(a) += n;
            degrees.at(b) += n;
        }
        sort(degrees.rbegin(), degrees.rend());
        
        int i0(degrees.at(0) % n);
        int max_val(degrees.at(0) / n + degrees.at(1) / n - (int)neighbor(degrees.at(0) % n, degrees.at(1) % n, s));
        int j(2);
        int curr_val;
        
        while (j < n && degrees.at(j) / n == degrees.at(1) / n) {
            for (int j1(0); j1 < j; ++j1) {
                if ((curr_val = degrees.at(j1) / n + degrees.at(j) / n - (int)neighbor(degrees.at(j) % n, degrees.at(j1) % n, s)) > max_val) {
                    max_val = curr_val;
                    // cout << degrees.at(j) << ' ' << degrees.at(j1) << '\n';
                }
            }
            ++j;
        }

        return max_val;
    }
};
// @lc code=end

