/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 *
 * https://leetcode.com/problems/shortest-path-to-get-all-keys/description/
 *
 * algorithms
 * Hard (45.30%)
 * Likes:    1666
 * Dislikes: 74
 * Total Accepted:    49.2K
 * Total Submissions: 96.8K
 * Testcase Example:  '["@.a..","###.#","b.A.B"]'
 *
 * You are given an m x n grid grid where:
 * 
 * 
 * '.' is an empty cell.
 * '#' is a wall.
 * '@' is the starting point.
 * Lowercase letters represent keys.
 * Uppercase letters represent locks.
 * 
 * 
 * You start at the starting point and one move consists of walking one space
 * in one of the four cardinal directions. You cannot walk outside the grid, or
 * walk into a wall.
 * 
 * If you walk over a key, you can pick it up and you cannot walk over a lock
 * unless you have its corresponding key.
 * 
 * For some 1 <= k <= 6, there is exactly one lowercase and one uppercase
 * letter of the first k letters of the English alphabet in the grid. This
 * means that there is exactly one key for each lock, and one lock for each
 * key; and also that the letters used to represent the keys and locks were
 * chosen in the same order as the English alphabet.
 * 
 * Return the lowest number of moves to acquire all keys. If it is impossible,
 * return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = ["@.a..","###.#","b.A.B"]
 * Output: 8
 * Explanation: Note that the goal is to obtain all the keys not to open all
 * the locks.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = ["@..aA","..B#.","....b"]
 * Output: 6
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = ["@Aa"]
 * Output: -1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 30
 * grid[i][j] is either an English letter, '.', '#', or '@'.
 * The number of keys in the grid is in the range [1, 6].
 * Each key in the grid is unique.
 * Each key in the grid has a matching lock.
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution
public:
    struct State {
        size_t r;
        size_t c;
        size_t keys;
        State(size_t r_, size_t c_, size_t k_): r(r_), c(c_), keys(k_) {}
    };
    int shortestPathAllKeys(vector<string>& grid) {
        size_t kRow(grid.size());
        size_t kCol(grid.at(0).size());
        size_t key_size(0);
        queue<State> q;
        int key_map[26];
        for (size_t i(0); i < 26; ++i) {
            key_map[i] = -1;
        }
        for (size_t r(0); r < kRow; ++r) {
            for (size_t col(0); col < kCol; ++col) {
                char c(grid.at(r).at(col));
                if (c == '@') {
                    q.push(State(r, col, 0));
                } else if (c >= 'A' && c <= 'Z') {
                    key_map[c - 'A'] = key_size;
                    key_size += 1;
                }
            }
        }
        int ans(0);
        size_t key_end(1 << key_size);
        size_t goal(key_end - 1);
        size_t arr_size(kRow * kCol * key_end);
        bool* visited = new bool[arr_size];
        for (size_t i(0); i < arr_size; ++i) {
            visited[i] = false;
        }
        while (!q.empty()) {
            size_t size(q.size());
            for (size_t i(0); i < size; ++i) {
                State curr(q.front());
                q.pop();
                size_t r1;
                size_t c1;
                size_t k1;
                char c;
                if (curr.keys == goal) {
                    return ans;
                }

                r1 = curr.r - 1;
                c1 = curr.c;
                k1 = curr.keys;
                if (r1 < kRow && (c = grid.at(r1).at(c1)) != '#') {
                    if (c >= 'A' && c <= 'Z') {
                        size_t key_idx(key_map[c - 'A']);
                        if (k1 & (1 << key_idx)) {
                            bool& curr_v(visited[(r1 * kCol + c1) * key_end + k1]);
                            if (!curr_v) {
                                curr_v = true;
                                q.push(State(r1, c1, k1));
                            }
                        }
                    } else {
                        if (c >= 'a' && c <= 'z') {
                            size_t key_idx(key_map[c - 'a']);
                            k1 = k1 | (1 << key_idx);
                        }
                        bool& curr_v(visited[(r1 * kCol + c1) * key_end + k1]);
                        if (!curr_v) {
                            curr_v = true;
                            q.push(State(r1, c1, k1));
                        }
                    }
                }

                r1 = curr.r + 1;
                c1 = curr.c;
                k1 = curr.keys;
                if (r1 < kRow && (c = grid.at(r1).at(c1)) != '#') {
                    if (c >= 'A' && c <= 'Z') {
                        size_t key_idx(key_map[c - 'A']);
                        if (k1 & (1 << key_idx)) {
                            bool& curr_v(visited[(r1 * kCol + c1) * key_end + k1]);
                            if (!curr_v) {
                                curr_v = true;
                                q.push(State(r1, c1, k1));
                            }
                        }
                    } else {
                        if (c >= 'a' && c <= 'z') {
                            size_t key_idx(key_map[c - 'a']);
                            k1 = k1 | (1 << key_idx);
                        }
                        bool& curr_v(visited[(r1 * kCol + c1) * key_end + k1]);
                        if (!curr_v) {
                            curr_v = true;
                            q.push(State(r1, c1, k1));
                        }
                    }
                }

                r1 = curr.r;
                c1 = curr.c - 1;
                k1 = curr.keys;
                if (c1 < kCol && (c = grid.at(r1).at(c1)) != '#') {
                    if (c >= 'A' && c <= 'Z') {
                        size_t key_idx(key_map[c - 'A']);
                        if (k1 & (1 << key_idx)) {
                            bool& curr_v(visited[(r1 * kCol + c1) * key_end + k1]);
                            if (!curr_v) {
                                curr_v = true;
                                q.push(State(r1, c1, k1));
                            }
                        }
                    } else {
                        if (c >= 'a' && c <= 'z') {
                            size_t key_idx(key_map[c - 'a']);
                            k1 = k1 | (1 << key_idx);
                        }
                        bool& curr_v(visited[(r1 * kCol + c1) * key_end + k1]);
                        if (!curr_v) {
                            curr_v = true;
                            q.push(State(r1, c1, k1));
                        }
                    }
                }

                r1 = curr.r;
                c1 = curr.c + 1;
                k1 = curr.keys;
                if (c1 < kCol && (c = grid.at(r1).at(c1)) != '#') {
                    if (c >= 'A' && c <= 'Z') {
                        size_t key_idx(key_map[c - 'A']);
                        if (k1 & (1 << key_idx)) {
                            bool& curr_v(visited[(r1 * kCol + c1) * key_end + k1]);
                            if (!curr_v) {
                                curr_v = true;
                                q.push(State(r1, c1, k1));
                            }
                        }
                    } else {
                        if (c >= 'a' && c <= 'z') {
                            size_t key_idx(key_map[c - 'a']);
                            k1 = k1 | (1 << key_idx);
                        }
                        bool& curr_v(visited[(r1 * kCol + c1) * key_end + k1]);
                        if (!curr_v) {
                            curr_v = true;
                            q.push(State(r1, c1, k1));
                        }
                    }
                }
            }
            ans += 1;
        }
        delete[] visited;
        return -1;
    }
};
// @lc code=end

