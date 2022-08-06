#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string to_return = "";
        const int kSize = strs.size();
        if (kSize == 0) {
            return to_return;
        }
        
        string first_str = strs.at(0);
        const int kLength = first_str.length();
        bool flag = false;
        for(int i = 0; i < kLength; i++) {
            char curr_char = first_str[i];
            for(int j = 1; j < kSize; j++) {
                if (strs.at(j).length() <= i || strs.at(j)[i] != curr_char) {
                    flag = true;
                    break; // if not match, the prefix is done
                }
            }
            if (flag) {
                break;
            }
            to_return += curr_char;
        }
            
        return to_return;
        
    }
};