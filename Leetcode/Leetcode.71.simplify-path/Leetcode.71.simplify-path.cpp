/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (39.07%)
 * Likes:    3381
 * Dislikes: 671
 * Total Accepted:    500.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '"/home/"'
 *
 * Given a string path, which is an absolute path (starting with a slash '/')
 * to a file or directory in a Unix-style file system, convert it to the
 * simplified canonical path.
 * 
 * In a Unix-style file system, a period '.' refers to the current directory, a
 * double period '..' refers to the directory up a level, and any multiple
 * consecutive slashes (i.e. '//') are treated as a single slash '/'. For this
 * problem, any other format of periods such as '...' are treated as
 * file/directory names.
 * 
 * The canonical path should have the following format:
 * 
 * 
 * The path starts with a single slash '/'.
 * Any two directories are separated by a single slash '/'.
 * The path does not end with a trailing '/'.
 * The path only contains the directories on the path from the root directory
 * to the target file or directory (i.e., no period '.' or double period
 * '..')
 * 
 * 
 * Return the simplified canonical path.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: path = "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: path = "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: path = "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= path.length <= 3000
 * path consists of English letters, digits, period '.', slash '/' or '_'.
 * path is a valid absolute Unix path.
 * 
 * 
 */
#include <string>
#include <stack>
using namespace std;
// @lc code=start
class Solution { // Independently solved
public:
    void readSlash(string& path, int& head) {
        const int size(path.size());
        while (head < size && path.at(head) == '/') {
            ++head;
        }
    }

    string readDir(string& path, int& head) {
        const int size(path.size());
        string ans;
        while (head < size && path.at(head) != '/') {
            ans += path.at(head);
            ++head;
        }
        return ans;
    }

    string simplifyPath(string path) {
        int head(0);
        const int size(path.size());
        stack<string> s;
        string ans;
        
        while (head < size) {
            readSlash(path, head);
            string dir(readDir(path, head));
            if (dir.size() == 0) {
                break;
            }
            if (dir == "..") {
                if (!s.empty()) {
                   s.pop(); 
                }
            } else if (dir != ".") {
                s.push(dir);
            }
            
            // cout << dir << ' ';
        }

        while (!s.empty()) {
            ans = "/" + s.top() + ans;
            s.pop();
        }

        if (ans.size() == 0) {
            ans = "/";
        }

        return ans;
    }
};
// @lc code=end

