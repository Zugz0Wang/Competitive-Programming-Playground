#include <string>
using namespace std;
class Solution {
public:
    string toLowcaseNoBlankString(string s) { // Reformat the string
        string to_return;
        int length = s.length();
        for(int i = 0; i < length; i++) {
            char current = s[i];
            if (current - 'A' >= 0 && current - 'A' < 26) { // If uppercase
                current += 32;
                to_return += current;
            } else if (current - 'a' >= 0 && current - 'a' < 26) { // If lowercase
                to_return += current;
            } else if (current - '0' >= 0 && current - '0' < 10) { // If numeric char
                to_return += current;
            }
        }
        return to_return;
    }
    bool isPalindrome(string s) {
        s = toLowcaseNoBlankString(s);
        int head = 0;
        int tail = s.length() - 1;
        while (head < tail) {
            if (s[head] != s[tail]) {
                return false;
            }
            head++;
            tail--;
        }
        return true;
    }
};