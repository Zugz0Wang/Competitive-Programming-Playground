// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prev_node_k = nullptr;
        ListNode* curr_node_k = head;
        ListNode* prev_node = nullptr;
        ListNode* curr_node = head;
        
        while(curr_node_k) {
            int n = 0;
            curr_node = curr_node_k;
            while (n++ < k && curr_node_k) {
                curr_node_k = curr_node_k -> next;
            }
            if (n <= k && curr_node_k == nullptr) { // If there are left over
                break;
            }
            prev_node = nullptr;
            n = 0;
            ListNode* head_node = curr_node; // The last node after reverse
            while (n++ < k && curr_node) {
                ListNode* next_node = curr_node->next;
                if (prev_node) { // Link back
                    curr_node->next = prev_node; // Link to previous node
                } else {
                    curr_node->next = curr_node_k; // Link to next group
                }
                prev_node = curr_node;
                curr_node = next_node;
            }
            if (prev_node_k) { // If not the first group
                prev_node_k->next = prev_node;
            } else { // If it's the first group of nodes
                head = prev_node;
            }
            prev_node_k = head_node; // The last node of the current group
        }
        return head;
    }
};