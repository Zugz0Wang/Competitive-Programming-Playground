#include <string>
using namespace std;
class Solution {
public:
    static const int kSize = 13;
    string romans[kSize]{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; // Initialize a table of romans
    int nums[kSize]{1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string intToRoman(int num) {
        string to_return = "";
        int curr_idx = 0;
        while (curr_idx < kSize) { // Loop through roman numbers from big to small
            int curr_num = nums[curr_idx];
            string curr_rom = romans[curr_idx];
            while (num >= curr_num) {
                num -= curr_num;
                to_return += curr_rom;
            }
            curr_idx++;
        }
        return to_return;
    }
};