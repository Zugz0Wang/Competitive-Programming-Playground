/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* curr_node = head;
        while (curr_node != nullptr) {
            v.push_back(curr_node->val);
            curr_node = curr_node->next;
        } // Turn it into vector,
        const int kSize = v.size();
        int v_head = 0;
        int v_tail = kSize - 1;
        while (v_head < v_tail) {
            if (v.at(v_head) != v.at(v_tail)) {
                return false;
            }
            v_head++;
            v_tail--;
        }
        return true;
    }
};
// @lc code=end

