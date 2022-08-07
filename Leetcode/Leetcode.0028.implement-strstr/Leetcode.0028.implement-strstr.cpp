#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        const int kHlength = haystack.length();
        const int kNlength = needle.length();
        for (int i = 0; i < kHlength - kNlength + 1; i++) { // Loop every possible location
            bool find = true;
            for (int j = 0; j < kNlength; j++) {
                if (haystack[i + j] != needle[j]) { // If not match
                    find = false;
                    break;
                }
            }
            if (find) {
                return i;
            }
        }
        return -1;
    }
};