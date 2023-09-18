class Solution {
public:
    struct Info {
        string extra;
        int count = 0;
        long length = 0;
        Info(int count_,  long length_): count(count_), length(length_) {}
    };
    string decodeAtIndex(string str, int k) {
        stack<Info> s;
        s.push(Info(0, 0));
        for (char c : str) {
            Info& curr(s.top());
            string& curr_s(curr.extra);
            if (c - '0' > 0 && c - '0' <= 9) {
                int count(c - '0');
                s.push({count, curr.length * curr.count + (int)curr_s.size()});
            } else {
                curr_s += c;
            }
        }
        k = k - 1;
        Info* top(&(s.top()));
        while (k < top->count * top->length) {
            k %= top->length;
            // cout << top->count << '*' << top->length << ' ' << top->extra << '\n';
            s.pop();
            top = &(s.top());
        }
        string ans;
        ans += top->extra[k - top->length * top->count];
        return ans;
    }
};