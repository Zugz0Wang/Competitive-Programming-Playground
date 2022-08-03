/**
 * Definition for singly-linked list.
 */
#include <vector>
using namespace std;
struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {// If lists is empty
            return nullptr;
        }
        while (lists.size() > 1) {// Reducing problem size
            ListNode* to_insert = lists.back();
            lists.pop_back();
            ListNode* prev_main = nullptr;
            ListNode* curr_main = lists.back();
            if (to_insert == nullptr) {
                continue;
            } else if (curr_main == nullptr) {
                lists.at(lists.size() - 1) = to_insert;
                continue;
            }
            while(to_insert != nullptr) {
                if (curr_main == nullptr || curr_main->val > to_insert->val) {
                    ListNode* temp_insert = to_insert->next;
                    if (prev_main == nullptr) { // Insert to head
                        to_insert->next = curr_main;
                        lists.at(lists.size() - 1) = to_insert;
                    } else if (curr_main == nullptr) { // Insert to middle
                        to_insert->next = nullptr;
                        prev_main->next = to_insert;
                    } else { // Insert to end
                        to_insert->next = curr_main;
                        prev_main->next = to_insert;
                    }
                    prev_main = to_insert; // Update state
                    to_insert = temp_insert;
                } else {
                    prev_main = curr_main;
                    curr_main = curr_main->next;
                }
            }
        }
        return lists.at(0);
    }
};