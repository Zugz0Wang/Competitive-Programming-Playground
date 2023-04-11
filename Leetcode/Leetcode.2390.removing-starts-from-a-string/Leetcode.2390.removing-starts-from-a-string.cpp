#include <string>
using namespace std;

class Solution {
public:
    string removeStars(string s) { // Independently solved.
        const int size(s.size());
        // string ans(size, 'a');
        int head(0);
        for (char c: s) {
            if (c == '*') {
                --head;
            } else {
                s.at(head) = c;
                ++head;
            }
        }
        s.resize(head, 'a');
        return s;
    }
};