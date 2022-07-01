//Definition for singly-linked list.
struct ListNode {   
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//https://leetcode.com/problems/add-two-numbers/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* number = new ListNode;
        ListNode* number_head = number;
        ListNode* current_l1 = l1;
        ListNode* current_l2 = l2;
        while (1) {
            bool carry = false;// Carry for the next digit.
            int sum = number_head->val;
            if (current_l1 && current_l2) {
                sum += (current_l1->val + current_l2->val);
            } else if (current_l1) {
                sum += current_l1->val;
            } else if (current_l2) {
                sum += current_l2->val;
            }

            if (sum > 9) {// Check carry
                carry = true;
                sum -= 10;
            } else {
                carry = false;
            }

            number_head->val = sum;
            
            if (current_l1) {
                current_l1 = current_l1->next;
            }
            if (current_l2) {
                current_l2 = current_l2->next;
            }
            if (current_l1 || current_l2 || carry) {// If need a new digit
                number_head->next = new ListNode;
                number_head = number_head->next;
                if (carry) {
                    number_head->val = 1;
                }
                carry = false;
            } else {
                break;
            }
        }
        return number;
    }
};