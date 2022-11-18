/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 *
 * https://leetcode.com/problems/top-k-frequent-words/description/
 *
 * algorithms
 * Medium (54.88%)
 * Likes:    5323
 * Dislikes: 278
 * Total Accepted:    439.2K
 * Total Submissions: 794.6K
 * Testcase Example:  '["i","love","leetcode","i","love","coding"]\n2'
 *
 * Given an array of strings words and an integer k, return the k most frequent
 * strings.
 * 
 * Return the answer sorted by the frequency from highest to lowest. Sort the
 * words with the same frequency by their lexicographical order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["i","love","leetcode","i","love","coding"], k = 2
 * Output: ["i","love"]
 * Explanation: "i" and "love" are the two most frequent words.
 * Note that "i" comes before "love" due to a lower alphabetical order.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words =
 * ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
 * Output: ["the","is","sunny","day"]
 * Explanation: "the", "is", "sunny" and "day" are the four most frequent
 * words, with the number of occurrence being 4, 3, 2 and 1 respectively.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 500
 * 1 <= words[i].length <= 10
 * words[i] consists of lowercase English letters.
 * k is in the range [1, The number of unique words[i]]
 * 
 * 
 * 
 * Follow-up: Could you solve it in O(n log(k)) time and O(n) extra space?
 * 
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string word : words) {
            freq[word] += 1;
        }

        auto compare = [&](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second > b.second;
        };

        vector<pair<string, int>> vect;
        vector<string> to_return;
        for (pair<string, int> key : freq) {
            vect.push_back(key);
        }
        sort(vect.begin(), vect.end(), compare);
        for (int i = 0; i < k; i++) {
            to_return.push_back(vect.at(i).first);
        }
        return to_return;
    }
};
// @lc code=end

