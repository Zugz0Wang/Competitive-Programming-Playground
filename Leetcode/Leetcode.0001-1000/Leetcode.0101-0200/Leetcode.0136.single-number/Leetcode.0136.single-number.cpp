#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int kSize = nums.size();
        if (kSize == 1) {
            return nums.at(0);
        }
        sort(nums.begin(),nums.end());
        if (nums.at(0) != nums.at(1)) { // If at head
            return nums.at(0);
        }
        for (int i = 1; i < kSize - 1; i++) {
            if (nums.at(i) != nums.at(i - 1) && nums.at(i) != nums.at(i + 1)) { // If in the middle
                return nums.at(i);
            }
        }
        return nums.at(kSize - 1); // If at tail;
    }
};