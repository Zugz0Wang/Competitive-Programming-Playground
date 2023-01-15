// @lc app=leetcode id=1061 lang=cpp
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    char mp[26];

    char find(char a) {
        int a_idx = a - 'a';
        if (mp[a_idx] == a) {
            return a;
        }
        mp[a_idx] = find(mp[a_idx]);
        return mp[a_idx];
    }

    void uni(char a, char b) {
        char a_set = find(a);
        char b_set = find(b);
        if (a_set < b_set) {
            int idx = b_set - 'a';
            mp[idx] = a_set;
        } else {
            int idx = a_set - 'a';
            mp[idx] = b_set;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for (int i = 0; i < 26; i++) {
            mp[i] = 'a' + i;
        }
        
        const int kSize = s1.size();
        for (int i = 0; i < kSize; i++) {
            uni(s1.at(i), s2.at(i));
        }

        string ans;
        for (char s : baseStr) {
            ans += find(s);
        }
        return ans;
    }
};
// @lc code=end