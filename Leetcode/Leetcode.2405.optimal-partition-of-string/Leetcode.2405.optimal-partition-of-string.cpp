#include <string>
using namespace std;

class Solution { // Original
public:
    bool st[26];
    void clear() {
        for (int i(0); i < 26; ++i) st[i] = false;
    }
    int partitionString(string s) {
        const int kSize(s.size());
        clear();
        int i(0);
        int count(1);
        while (i < kSize) {
            char curr_char(s.at(i));
            int curr_idx(curr_char - 'a');
            // cout << curr_idx << ' ';
            if (st[curr_idx] == true) {
                clear();
                ++count;
            } else {
                st[curr_idx] = true;
                ++i;
            }
        }
        return count;
    }
};