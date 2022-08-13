
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prev_node = nullptr;
        ListNode* curr_node = list1;
        
        if(curr_node == nullptr) {
            return list2;
        }
        
        while(list2 != nullptr) {
            while(curr_node != nullptr && curr_node->val < list2->val) {
                prev_node = curr_node;
                curr_node = curr_node->next;
            }
            ListNode* temp = list2;
            list2 = list2->next;
            temp->next = curr_node;
            if (prev_node == nullptr) {
                list1 = temp; // Head case
            } else if (curr_node == nullptr) {
                prev_node->next = temp; // Tail case
            } else {
                prev_node->next = temp; // Middle case
            }
            curr_node = temp;
        }
            
        return list1;
    }
};