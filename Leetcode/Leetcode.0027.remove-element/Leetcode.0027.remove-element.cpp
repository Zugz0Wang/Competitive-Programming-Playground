#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx = 0;
        int size = nums.size();
        while (idx < size) {
            if (nums.at(idx) == val) {
                nums.at(idx) = nums.at(--size);// If need remove
            } else {
                idx++;
            }
        }
        return size;
    }
};