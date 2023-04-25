/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 *
 * https://leetcode.com/problems/smallest-number-in-infinite-set/description/
 *
 * algorithms
 * Medium (71.26%)
 * Likes:    412
 * Dislikes: 36
 * Total Accepted:    30.9K
 * Total Submissions: 43.1K
 * Testcase Example:  '["SmallestInfiniteSet","addBack","popSmallest","popSmallest","popSmallest","addBack","popSmallest","popSmallest","popSmallest"]\n' +
  '[[],[2],[],[],[],[1],[],[],[]]'
 *
 * You have a set which contains all positive integers [1, 2, 3, 4, 5, ...].
 * 
 * Implement the SmallestInfiniteSet class:
 * 
 * 
 * SmallestInfiniteSet() Initializes the SmallestInfiniteSet object to contain
 * all positive integers.
 * int popSmallest() Removes and returns the smallest integer contained in the
 * infinite set.
 * void addBack(int num) Adds a positive integer num back into the infinite
 * set, if it is not already in the infinite set.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["SmallestInfiniteSet", "addBack", "popSmallest", "popSmallest",
 * "popSmallest", "addBack", "popSmallest", "popSmallest", "popSmallest"]
 * [[], [2], [], [], [], [1], [], [], []]
 * Output
 * [null, null, 1, 2, 3, null, 1, 4, 5]
 * 
 * Explanation
 * SmallestInfiniteSet smallestInfiniteSet = new SmallestInfiniteSet();
 * smallestInfiniteSet.addBack(2);    // 2 is already in the set, so no change
 * is made.
 * smallestInfiniteSet.popSmallest(); // return 1, since 1 is the smallest
 * number, and remove it from the set.
 * smallestInfiniteSet.popSmallest(); // return 2, and remove it from the set.
 * smallestInfiniteSet.popSmallest(); // return 3, and remove it from the set.
 * smallestInfiniteSet.addBack(1);    // 1 is added back to the set.
 * smallestInfiniteSet.popSmallest(); // return 1, since 1 was added back to
 * the set and
 * ⁠                                  // is the smallest number, and remove it
 * from the set.
 * smallestInfiniteSet.popSmallest(); // return 4, and remove it from the set.
 * smallestInfiniteSet.popSmallest(); // return 5, and remove it from the
 * set.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num <= 1000
 * At most 1000 calls will be made in total to popSmallest and addBack.
 * 
 * 
 */
#include <set>
using namespace std;
// @lc code=start
class SmallestInfiniteSet { // Independently solved, super slow
public:
    set<int> s;
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        int prev(0);
        for (int i : s) {
            if (i > prev + 1) {
                break;
            }
            prev = i;
        }
        s.insert(prev + 1);
        return prev + 1;
    }
    
    void addBack(int num) {
        if (s.count(num) > 0) {
            s.erase(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

