#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int kSize = nums.size();
        int insert_idx = 0;
        int prev_int = 0;
        bool new_flag = true;
        int i = 0;
        while(i < kSize) {
            int curr_int = nums.at(i);
            if (new_flag) { // If new
                new_flag = false;
                nums.at(insert_idx) = curr_int;
                prev_int = curr_int;
                insert_idx++;
                i++;
            } else {
                if (prev_int == curr_int) { // If duplicate
                    i++;
                } else {
                    new_flag = true;
                }
            }
        }
        return insert_idx;
    }
};