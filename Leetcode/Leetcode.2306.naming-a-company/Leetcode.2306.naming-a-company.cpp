/*
 * @lc app=leetcode id=2306 lang=cpp
 *
 * [2306] Naming a Company
 *
 * https://leetcode.com/problems/naming-a-company/description/
 *
 * algorithms
 * Hard (33.68%)
 * Likes:    390
 * Dislikes: 23
 * Total Accepted:    8.9K
 * Total Submissions: 25.2K
 * Testcase Example:  '["coffee","donuts","time","toffee"]'
 *
 * You are given an array of strings ideas that represents a list of names to
 * be used in the process of naming a company. The process of naming a company
 * is as follows:
 * 
 * 
 * Choose 2 distinct names from ideas, call them ideaA and ideaB.
 * Swap the first letters of ideaA and ideaB with each other.
 * If both of the new names are not found in the original ideas, then the name
 * ideaA ideaB (the concatenation of ideaA and ideaB, separated by a space) is
 * a valid company name.
 * Otherwise, it is not a valid name.
 * 
 * 
 * Return the number of distinct valid names for the company.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ideas = ["coffee","donuts","time","toffee"]
 * Output: 6
 * Explanation: The following selections are valid:
 * - ("coffee", "donuts"): The company name created is "doffee conuts".
 * - ("donuts", "coffee"): The company name created is "conuts doffee".
 * - ("donuts", "time"): The company name created is "tonuts dime".
 * - ("donuts", "toffee"): The company name created is "tonuts doffee".
 * - ("time", "donuts"): The company name created is "dime tonuts".
 * - ("toffee", "donuts"): The company name created is "doffee tonuts".
 * Therefore, there are a total of 6 distinct company names.
 * 
 * The following are some examples of invalid selections:
 * - ("coffee", "time"): The name "toffee" formed after swapping already exists
 * in the original array.
 * - ("time", "toffee"): Both names are still the same after swapping and exist
 * in the original array.
 * - ("coffee", "toffee"): Both names formed after swapping already exist in
 * the original array.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ideas = ["lack","back"]
 * Output: 0
 * Explanation: There are no valid selections. Therefore, 0 is returned.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= ideas.length <= 5 * 10^4
 * 1 <= ideas[i].length <= 10
 * ideas[i] consists of lowercase English letters.
 * All the strings in ideas are unique.
 * 
 * 
 */
#include <string>
#include <vector>
#include <set>
using namespace std;
// @lc code=start
class Solution {
public:
   
    set<string> strs[26];
    long long distinctNames(vector<string>& ideas) {
       
        for (string& idea : ideas) {
            strs[idea.at(0) - 'a'].insert(idea.substr(1));
        }
        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            set<string>& a = strs[i];
            for (int j = i + 1; j < 26; j++) {
                set<string>& b = strs[j];
                int same = 0;
                for (string str : a) {
                    if (b.count(str) > 0) {
                        same += 1;
                    }
                }
                ans += (a.size() - same) * (b.size() - same);
            }
        }
        
        return ans;
    }
};
// @lc code=end

