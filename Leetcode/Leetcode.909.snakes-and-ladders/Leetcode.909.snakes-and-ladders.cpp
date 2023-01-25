/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 *
 * https://leetcode.com/problems/snakes-and-ladders/description/
 *
 * algorithms
 * Medium (40.73%)
 * Likes:    1116
 * Dislikes: 294
 * Total Accepted:    89.6K
 * Total Submissions: 219K
 * Testcase Example:  '[[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]'
 *
 * You are given an n x n integer matrix board where the cells are labeled from
 * 1 to n^2 in a Boustrophedon style starting from the bottom left of the board
 * (i.e. board[n - 1][0]) and alternating direction each row.
 * 
 * You start on square 1 of the board. In each move, starting from square curr,
 * do the following:
 * 
 * 
 * Choose a destination square next with a label in the range [curr + 1,
 * min(curr + 6, n^2)].
 * 
 * 
 * This choice simulates the result of a standard 6-sided die roll: i.e., there
 * are always at most 6 destinations, regardless of the size of the
 * board.
 * 
 * 
 * If next has a snake or ladder, you must move to the destination of that
 * snake or ladder. Otherwise, you move to next.
 * The game ends when you reach the square n^2.
 * 
 * 
 * A board square on row r and column c has a snake or ladder if board[r][c] !=
 * -1. The destination of that snake or ladder is board[r][c]. Squares 1 and
 * n^2 do not have a snake or ladder.
 * 
 * Note that you only take a snake or ladder at most once per move. If the
 * destination to a snake or ladder is the start of another snake or ladder,
 * you do not follow the subsequent snake or ladder.
 * 
 * 
 * For example, suppose the board is [[-1,4],[-1,3]], and on the first move,
 * your destination square is 2. You follow the ladder to square 3, but do not
 * follow the subsequent ladder to 4.
 * 
 * 
 * Return the least number of moves required to reach the square n^2. If it is
 * not possible to reach the square, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: board =
 * [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
 * Output: 4
 * Explanation: 
 * In the beginning, you start at square 1 (at row 5, column 0).
 * You decide to move to square 2 and must take the ladder to square 15.
 * You then decide to move to square 17 and must take the snake to square 13.
 * You then decide to move to square 14 and must take the ladder to square 35.
 * You then decide to move to square 36, ending the game.
 * This is the lowest possible number of moves to reach the last square, so
 * return 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: board = [[-1,-1],[-1,3]]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == board.length == board[i].length
 * 2 <= n <= 20
 * grid[i][j] is either -1 or in the range [1, n^2].
 * The squares labeled 1 and n^2 do not have any ladders or snakes.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int b[4000];
    bool visited[4000];
    bool jumped[4000];
    int snakesAndLadders(vector<vector<int>>& board) {
        memset(b, 0, sizeof(b));
        memset(visited, false, sizeof(visited));
        memset(jumped, false, sizeof(jumped));
        const int n = board.size();
        int curr = 1;
        int row = n - 1;
        int col = 0;
        bool dire = true;
        while (row >= 0) {
            if (dire) {
                col = 0;
                while (col < n) {
                    if (board.at(row).at(col) >= 0) {
                        b[curr] = board.at(row).at(col);
                    }
                    curr++;
                    col++;
                }
            } else {
                col = n - 1;
                while (col >= 0) {
                    if (board.at(row).at(col) >= 0) {
                        b[curr] = board.at(row).at(col);
                    }
                    curr++;
                    col--;
                }
            }
            dire = !dire;
            row--;
        }
        // for (int i = 1; i < n * n; i++) {
        //     cout << b[i] << ' ';
        // }
        queue<int> wait;
        const int max = n * n;
        wait.push(1);
        // visited[1] =true;
        int move = 0;
        while (wait.size() > 0) {
            int curr_size = wait.size();
            for (int i = 0; i < curr_size; i++) {
                int curr_idx = wait.front();
                // visited[curr_idx] = true;
                wait.pop();
                for (int jump = 1; jump <= 6; jump++) {
                    int next = curr_idx + jump;
                    if (next > max) {
                        continue;
                    }

                    if (b[next] > 0) {
                        if (jumped[next]) {
                            continue;
                        }
                        jumped[next] = true;
                        next = b[next];   
                    }
                    if (visited[next] || next > max) {
                        continue;
                    }
                    visited[next] = true;
    
                    if (next == max) {
                        return move + 1;
                    }
                    // cout << next << ' ';
                    wait.push(next);
                }
            }
            // cout << curr_size;
            // cout << '\n';
            move++;
        }
        return -1;
    }
    //[[-1,-1],[-1,3]] -1
    //[[1,1,-1],[1,1,1],[-1,1,1]]
    //[[-1,1,2,-1],[2,13,15,-1],[-1,10,-1,-1],[-1,6,2,8]] forgot 6
    //[
    //[-1,-1,-1,46,47,-1,-1,-1],
    //[51,-1,-1,63,-1,31,21,-1],
    //[-1,-1,26,-1,-1,38,-1,-1],
    //[-1,-1,11,-1,14,23,56,57],
    //[11,-1,-1,-1,49,36,-1,48],
    //[-1,-1,-1,33,56,-1,57,21],
    //[-1,-1,-1,-1,-1,-1,2,-1],
    //[-1,-1,-1,8,3,-1,6,56]]
    //[[-1,-1,-1,46,47,-1,-1,-1],[51,-1,-1,63,-1,31,21,-1],[-1,-1,26,-1,-1,38,-1,-1],[-1,-1,11,-1,14,23,56,57],[11,-1,-1,-1,49,36,-1,48],[-1,-1,-1,33,56,-1,57,21],[-1,-1,-1,-1,-1,-1,2,-1],[-1,-1,-1,8,3,-1,6,56]]
    //[[-1,1,1,1],[-1,7,1,1],[16,1,1,1],[-1,1,9,1]]
    //[[-1,-1,-1,30,-1,144,124,135,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,167,93,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1,77,-1,-1,90,-1,-1],[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,122,-1],[-1,-1,-1,23,-1,-1,-1,-1,-1,155,-1,-1,-1],[-1,-1,140,29,-1,-1,-1,-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,115,-1,-1,-1,109,-1,-1,5],[-1,57,-1,99,121,-1,-1,132,-1,-1,-1,-1,-1],[-1,48,-1,-1,-1,68,-1,-1,-1,-1,31,-1,-1],[-1,163,147,-1,77,-1,-1,114,-1,-1,80,-1,-1],[-1,-1,-1,-1,-1,57,28,-1,-1,129,-1,-1,-1],[-1,-1,-1,-1,-1,-1,-1,-1,-1,87,-1,-1,-1]]
};  
// @lc code=end

