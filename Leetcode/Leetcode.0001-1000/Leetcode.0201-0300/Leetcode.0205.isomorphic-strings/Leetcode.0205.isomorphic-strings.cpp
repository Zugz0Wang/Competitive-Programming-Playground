#include <string>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int s_dict[200] = {0};
        int t_dict[200] = {0};
        const int kLength = s.length();
        for (int i = 0; i < kLength; i++) {
            if (s_dict[s[i]] == t_dict[t[i]]) { // If map to the same number or not used yet
                if (s_dict[s[i]] == 0) {
                    s_dict[s[i]] = i + 1;
                    t_dict[t[i]] = i + 1;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};