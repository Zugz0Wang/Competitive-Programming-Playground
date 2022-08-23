/*
 * @lc app=leetcode id=936 lang=cpp
 *
 * [936] Stamping The Sequence
 *
 * https://leetcode.com/problems/stamping-the-sequence/description/
 *
 * algorithms
 * Hard (53.83%)
 * Likes:    1231
 * Dislikes: 195
 * Total Accepted:    47.9K
 * Total Submissions: 75.9K
 * Testcase Example:  '"abc"\n"ababc"'
 *
 * You are given two strings stamp and target. Initially, there is a string s
 * of length target.length with all s[i] == '?'.
 * 
 * In one turn, you can place stamp over s and replace every letter in the s
 * with the corresponding letter from stamp.
 * 
 * 
 * For example, if stamp = "abc" and target = "abcba", then s is "?????"
 * initially. In one turn you can:
 * 
 * 
 * place stamp at index 0 of s to obtain "abc??",
 * place stamp at index 1 of s to obtain "?abc?", or
 * place stamp at index 2 of s to obtain "??abc".
 * 
 * Note that stamp must be fully contained in the boundaries of s in order to
 * stamp (i.e., you cannot place stamp at index 3 of s).
 * 
 * 
 * We want to convert s to target using at most 10 * target.length turns.
 * 
 * Return an array of the index of the left-most letter being stamped at each
 * turn. If we cannot obtain target from s within 10 * target.length turns,
 * return an empty array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: stamp = "abc", target = "ababc"
 * Output: [0,2]
 * Explanation: Initially s = "?????".
 * - Place stamp at index 0 to get "abc??".
 * - Place stamp at index 2 to get "ababc".
 * [1,0,2] would also be accepted as an answer, as well as some other
 * answers.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: stamp = "abca", target = "aabcaca"
 * Output: [3,0,1]
 * Explanation: Initially s = "???????".
 * - Place stamp at index 3 to get "???abca".
 * - Place stamp at index 0 to get "abcabca".
 * - Place stamp at index 1 to get "aabcaca".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= stamp.length <= target.length <= 1000
 * stamp and target consist of lowercase English letters.
 * 
 * 
 */
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int matchNumber(string& stamp, string& target, int match_idx) {
        const int kStampLength = stamp.length();
        const int kTargetLength = target.length();
        const int end_idx = match_idx + kStampLength - 1;
        if (match_idx < 0 || end_idx >= kTargetLength) {
            return -1;
        }
        int count = 0;
        for (int i = 0; i < kStampLength; i++) {
            char curr_stamp = stamp.at(i);
            char curr_target = target.at(match_idx + i);
            if (curr_target == curr_stamp) {
                count += 1;
            } else if (curr_target != '?' && curr_stamp != curr_target) {
                return -1;
            }
        }
        return count;
    }
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> to_return;
        const int kStampLength = stamp.length();
        const int kTargetLength = target.length();
        int count = 0;
        int max_possible = kTargetLength;
        
        string new_target;
        bool found = false;
        while (found == false && count < 10 * kTargetLength) {
            bool exist = false;
            bool max = 0;
            int match_idx = 0;
            for (int i = 0; i < kTargetLength - kStampLength + 1; i++) {
                int match_num = matchNumber(stamp, target, i);
                // cout << match_num << ' ';
                if (exist) {
                    if (match_num > max) {
                        match_idx = i;
                        max = match_num;
                    }
                } else {
                    if (match_num > 0) {
                        exist = true;
                        max = match_num;
                        match_idx = i;
                    } 
                }
                if (exist && max > 0) {
                    break; // If can remove at least one char
                }
            }
            // cout << '\n';
            if (exist) {
                int asterisk = 0;
                max_possible = 0;
                for (int i = 0; i < kTargetLength; i++) {
                    if (i >= match_idx && i < match_idx + kStampLength) {
                        new_target += '?';
                        asterisk++;
                    } else {
                        new_target += target[i];
                        if (target[i] == '?') {
                            asterisk++;
                        } else {
                            max_possible += 1;
                        }
                    }
                }
                
                target = new_target;
                // cout << target << '\n';
                new_target = "";
                to_return.push_back(match_idx);
                if (asterisk == kTargetLength) {
                    found = true;
                    break;
                }
            } else {
                break;
            }
            count++;
        }
        if (found) {
            reverse(to_return.begin(), to_return.end());
            return to_return;
        } else {
            return {};
        }
    }
};
// @lc code=end
// '"abc"\n"ababc"'
// '"abca"\n"aabcaca"'
// '"efbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbdde"\n"eefbefbbaefbefbbaabefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddebafccfacccdcdeddfdefbbaceebbddecfacccdcdeddfdefbbaceebbddeaceebbddefacccdcdeddefbbaabcddcaefffbaabafccefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddeeddfdefbbacefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddeccfacccdcdeddfdefbbaceebbdefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddeccdcdeddfdefbbaceebbddecaefffcaabafccfacccdcdefbbaabefbbaabcddcaefffcaabafccfacccdcdefbbaabcddcaefffcaaefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddeefbbaabcddcaefffcaabaefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddedfdefbbaceefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddeabafccfaccefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddedcdeddfdefbbaceebbddeaceebbddebcddcaeffefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddeeddfdefbbaceebbddeaefffcaabafccfacccefbbaabcddcaefffcaabafccfacccefbbaabcddcaefffefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddefacccdcdeddfdefbbaceeefbbaabcddcaefffcaabafccfacccdcdeddfdefbbaceebbddeebbddee"'

