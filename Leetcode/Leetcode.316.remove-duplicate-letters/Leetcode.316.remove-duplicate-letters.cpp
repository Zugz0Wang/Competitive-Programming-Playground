class Solution { // Learned from solution
public:
    string removeDuplicateLetters(string str) {
        const int size(str.size());
        stack<int> s;
        int e(0);
        vector<int> last(26, -1);
        for (int i(0); i < size; ++i) {
            last[str.at(i) - 'a'] = i;
        }
        for (int i(0); i < size; ++i) {
            char c(str.at(i));
            int c_i(c - 'a');
            int mask(1 << c_i);
            if ((e & mask) == 0) {
                e |= mask;
                while (!(s.empty()) && s.top() > c_i && last[s.top()] > i) {
                    e ^= 1 << s.top();
                    s.pop();
                    
                }
                s.push(c_i);
            } 
        }
        string ans;
        while (!(s.empty())) {
            ans += 'a' + s.top();
            s.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};