/*
 * @lc app=leetcode id=352 lang=cpp
 *
 * [352] Data Stream as Disjoint Intervals
 *
 * https://leetcode.com/problems/data-stream-as-disjoint-intervals/description/
 *
 * algorithms
 * Hard (51.18%)
 * Likes:    750
 * Dislikes: 168
 * Total Accepted:    56.4K
 * Total Submissions: 109K
 * Testcase Example:  '["SummaryRanges","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals","addNum","getIntervals"]\n' +
  '[[],[1],[],[3],[],[7],[],[2],[],[6],[]]'
 *
 * Given a data stream input of non-negative integers a1, a2, ..., an,
 * summarize the numbers seen so far as a list of disjoint intervals.
 * 
 * Implement the SummaryRanges class:
 * 
 * 
 * SummaryRanges() Initializes the object with an empty stream.
 * void addNum(int value) Adds the integer value to the stream.
 * int[][] getIntervals() Returns a summary of the integers in the stream
 * currently as a list of disjoint intervals [starti, endi]. The answer should
 * be sorted by starti.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["SummaryRanges", "addNum", "getIntervals", "addNum", "getIntervals",
 * "addNum", "getIntervals", "addNum", "getIntervals", "addNum",
 * "getIntervals"]
 * [[], [1], [], [3], [], [7], [], [2], [], [6], []]
 * Output
 * [null, null, [[1, 1]], null, [[1, 1], [3, 3]], null, [[1, 1], [3, 3], [7,
 * 7]], null, [[1, 3], [7, 7]], null, [[1, 3], [6, 7]]]
 * 
 * Explanation
 * SummaryRanges summaryRanges = new SummaryRanges();
 * summaryRanges.addNum(1);      // arr = [1]
 * summaryRanges.getIntervals(); // return [[1, 1]]
 * summaryRanges.addNum(3);      // arr = [1, 3]
 * summaryRanges.getIntervals(); // return [[1, 1], [3, 3]]
 * summaryRanges.addNum(7);      // arr = [1, 3, 7]
 * summaryRanges.getIntervals(); // return [[1, 1], [3, 3], [7, 7]]
 * summaryRanges.addNum(2);      // arr = [1, 2, 3, 7]
 * summaryRanges.getIntervals(); // return [[1, 3], [7, 7]]
 * summaryRanges.addNum(6);      // arr = [1, 2, 3, 6, 7]
 * summaryRanges.getIntervals(); // return [[1, 3], [6, 7]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= value <= 10^4
 * At most 3 * 10^4 calls will be made to addNum and getIntervals.
 * 
 * 
 * 
 * Follow up: What if there are lots of merges and the number of disjoint
 * intervals is small compared to the size of the data stream?
 * 
 */
#include <set>
using namespace std;
// @lc code=start
class SummaryRanges {
private:
    set<int> treeMap;
public:
    // Learned from official solution
    SummaryRanges() {}
    
    void addNum(int value) {
        treeMap.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        if (treeMap.size() == 0) {
            return ans;
        }
        int head = -1;
        int tail = -1;
        for (int val : treeMap) {
            if (head == -1) {
                head = val;
                tail = val;
            } else if (val == tail + 1) {
                tail += 1;
            } else {
                ans.push_back({head, tail});
                head = val;
                tail = val;
            }
        }
        if (head != -1) {
            ans.push_back({head, tail});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
// @lc code=end

