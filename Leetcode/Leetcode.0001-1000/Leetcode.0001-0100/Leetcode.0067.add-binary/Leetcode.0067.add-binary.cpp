#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        const int kLengthA = a.length();
        const int kLengthB = b.length();
        string to_return = "";
        int carry = 0;
        int idx = 0;
        while (idx < kLengthA || idx < kLengthB || carry > 0) {
            int curr_sum = carry;
            if (idx < kLengthA && a[kLengthA - 1 - idx] == '1') {
                curr_sum += 1;
            }
            if (idx < kLengthB && b[kLengthB - 1 - idx] == '1') {
                curr_sum += 1;
            }
            if (curr_sum == 3) { // Four cases
                carry = 1;
                to_return = '1' + to_return;
            } else if (curr_sum == 2) {
                carry = 1;
                to_return = '0' + to_return;
            } else if (curr_sum == 1) {
                carry = 0;
                to_return = '1' + to_return;
            } else {
                carry = 0;
                to_return = '0' + to_return;
            }
            idx++;
        }
        return to_return;
    }
};