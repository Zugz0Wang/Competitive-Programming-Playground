/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev_node_k = nullptr;
        ListNode* curr_node_k = head;
        ListNode* prev_node = nullptr;
        ListNode* curr_node = head;
        const int k = 2; // Used my code from Leetcode.25, and simplified the k loop part;
        while(curr_node_k) {
            int n = 0;
            curr_node = curr_node_k;
            while (n++ < k && curr_node_k) {
                curr_node_k = curr_node_k -> next;
            }
            if (n <= k && curr_node_k == nullptr) { // If there are left over
                break;
            }
            prev_node = curr_node;
            curr_node = curr_node->next;
            curr_node->next = prev_node;
            prev_node->next = curr_node_k;
            
            if (prev_node_k) { // If not the first group
                prev_node_k->next = curr_node;
            } else { // If it's the first group of nodes
                head = curr_node;
            }
            prev_node_k = prev_node; // The last node of the current group
        }
        return head;
    }
};
// @lc code=end

