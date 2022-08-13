#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool new_word = false;
        int curr_length = 0;
        int prev_length = 0;
        char curr_char = ' ';
        const int kLength = s.length();
        for (int i = 0; i < kLength; i++) {
            curr_char = s[i];
            if (curr_char != ' ') {
                curr_length += 1;
                if (!new_word) {
                    new_word = true;
                }
            } else {
                if (new_word) { // If the word ends
                    new_word = false;
                    prev_length = curr_length;
                    curr_length = 0;
                }
            }
        }
        if (curr_length > 0) {
            prev_length = curr_length;
        }
        return prev_length;
    }
};