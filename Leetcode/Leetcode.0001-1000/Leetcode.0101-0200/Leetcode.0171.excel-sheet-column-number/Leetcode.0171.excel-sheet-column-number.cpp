#include <string>
using namespace std;
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int sum = 0;
        int power = 1;
        const int kLength = columnTitle.length();
        for (int i = kLength - 1; i >= 0; i--) {
            if (i < kLength - 1) { // Prevent overflow of the last iteration
                power *= 26;
            }
            int curr_num = static_cast<int>(columnTitle[i] - 'A') + 1;
            sum += power * curr_num;
        }
        return sum;
    }
};