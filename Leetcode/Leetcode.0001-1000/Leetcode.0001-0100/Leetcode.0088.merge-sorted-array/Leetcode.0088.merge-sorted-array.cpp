#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int head1 = m - 1;
        int head2 = n - 1;
        int insert_head = m + n - 1;
        while (head1 >= 0 || head2 >= 0) {// Such an smooth procedure if merging from tail!
            if (head1 >= 0 && head2 >= 0) {
                int int1 = nums1.at(head1);
                int int2 = nums2.at(head2);
                if (int1 >= int2) {
                    nums1.at(insert_head) = int1;
                    head1 -= 1;
                } else {
                    nums1.at(insert_head) = int2;
                    head2 -= 1;
                }
            } else if (head2 >= 0) {
                int int2 = nums2.at(head2);
                nums1.at(insert_head) = int2;
                head2 -= 1;
            } else {
                break;
            }
            insert_head -= 1;
        }
    }
};