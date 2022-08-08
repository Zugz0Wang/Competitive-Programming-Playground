#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int curr_digit = digits.size() - 1;
        while (curr_digit >= 0) {
            if (digits.at(curr_digit) == 9) {
                digits.at(curr_digit) = 0;
                curr_digit -= 1;
            } else {
                digits.at(curr_digit) += 1;
                break;
            }
        }
        if (curr_digit == -1) { // If adding new leading 1
            const int kSize = digits.size();
            int curr = 1;
            for (int i = 0; i < kSize - 1; i++) {
                digits.at(i) = curr;
                curr = digits.at(i + 1);
            }
            curr = digits.at(kSize - 1);
            digits.push_back(curr);
            digits.at(0) = 1;
        }
        return digits;
    }
};