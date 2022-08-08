#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int curr_idx = 0;
        int sum = 0;
        const int length = s.length();
        while(curr_idx < length) { // Loop each char
            char curr_char = s[curr_idx];
            char next_char = 'A';
            if (curr_idx < length - 1) {
                next_char = s[curr_idx + 1];
            }
            if (curr_char == 'I') {
                if (next_char == 'V') {
                    sum += 4;
                    curr_idx++;
                } else if (next_char == 'X') {
                    sum += 9;
                    curr_idx++;
                } else {
                    sum += 1; 
                }
            } else if (curr_char == 'V') {
                sum += 5;
            } else if (curr_char == 'X') {
                if (next_char == 'L') {
                    sum += 40;
                    curr_idx++;
                } else if (next_char == 'C') {
                    sum += 90;
                    curr_idx++;
                } else {
                    sum += 10; 
                }
            } else if (curr_char == 'L') {
                sum += 50;
            } else if (curr_char == 'C') {
                if (next_char == 'D') {
                    sum += 400;
                    curr_idx++;
                } else if (next_char == 'M') {
                    sum += 900;
                    curr_idx++;
                } else {
                    sum += 100; 
                }
            } else if (curr_char == 'D') {
                sum += 500;
            } else {
                sum += 1000;
            }
            curr_idx++;
        }
        return sum;
    }
};