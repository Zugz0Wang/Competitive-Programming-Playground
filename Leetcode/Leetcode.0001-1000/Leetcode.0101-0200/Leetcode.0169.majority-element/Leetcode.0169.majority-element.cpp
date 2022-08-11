#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int majority = nums.at(0);
        const int kSize = nums.size();
        for (int i = 1; i < kSize; i++) { // If a number is majority, its count must be greater than 0
            int current = nums.at(i);
            if (current == majority) {
                count++;
            } else {
                count--;
            }
            if (count == 0) {
                majority = current;
                count = 1;
            }
        }
        return majority;
    }
};