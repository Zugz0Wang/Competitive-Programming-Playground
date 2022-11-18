/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 *
 * https://leetcode.com/problems/minimum-genetic-mutation/description/
 *
 * algorithms
 * Medium (47.68%)
 * Likes:    1728
 * Dislikes: 178
 * Total Accepted:    82K
 * Total Submissions: 163.8K
 * Testcase Example:  '"AACCGGTT"\n"AACCGGTA"\n["AACCGGTA"]'
 *
 * A gene string can be represented by an 8-character long string, with choices
 * from 'A', 'C', 'G', and 'T'.
 * 
 * Suppose we need to investigate a mutation from a gene string start to a gene
 * string end where one mutation is defined as one single character changed in
 * the gene string.
 * 
 * 
 * For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
 * 
 * 
 * There is also a gene bank bank that records all the valid gene mutations. A
 * gene must be in bank to make it a valid gene string.
 * 
 * Given the two gene strings start and end and the gene bank bank, return the
 * minimum number of mutations needed to mutate from start to end. If there is
 * no such a mutation, return -1.
 * 
 * Note that the starting point is assumed to be valid, so it might not be
 * included in the bank.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: start = "AACCGGTT", end = "AAACGGTA", bank =
 * ["AACCGGTA","AACCGCTA","AAACGGTA"]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: start = "AAAAACCC", end = "AACCCCCC", bank =
 * ["AAAACCCC","AAACCCCC","AACCCCCC"]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * start.length == 8
 * end.length == 8
 * 0 <= bank.length <= 10
 * bank[i].length == 8
 * start, end, and bank[i] consist of only the characters ['A', 'C', 'G',
 * 'T'].
 * 
 * 
 */
#include <string>
#include <vector>
#include <set>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    int diff(string& a, string& b) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.at(i) != b.at(i)) {
                count++;
            }
        }
        return count;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> visited;
        queue<string> waitlist;
        waitlist.push(start);
        int count = 0;
        while (!waitlist.empty()) {
            int wait_length = waitlist.size();
            int i = 0;
            while (i < wait_length) {
                string curr = waitlist.front();
                waitlist.pop();
                visited.insert(curr);
                if (curr == end) {
                    return count;
                }
                for (string& dna : bank) {
                    if (visited.count(dna) == 0 && diff(curr, dna) == 1) {
                        waitlist.push(dna);
                    }
                }
                i++;
            }
            count++;
        } 
        return -1;
    }
};
// @lc code=end

