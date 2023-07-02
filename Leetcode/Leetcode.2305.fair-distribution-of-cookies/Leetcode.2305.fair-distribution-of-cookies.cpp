// @lc app=leetcode id=2305 lang=cpp
// @lc code=start
class Solution {
public:
    
    int min = 0;
    struct Info {
        int idx;
        int start;
        bool add;
        Info(int i, int s): idx(i), start(s), add(true) {}
    };

    int distributeCookies(vector<int>& cookies, int k) {
        const int size(cookies.size());
        
        int* dis(new int[k]);
        int* ava(new int[k]);
        
        int capa(size / k);
        if (size / k != 0) {
            capa = (k + size) / k;
        }
        if (k == size) {
             int curr_max(0);
            for (int i(0); i < k; ++i) {
                if (cookies.at(i) > curr_max) {
                    curr_max = cookies.at(i);
                }
            }
            return curr_max;
        }
        for (size_t i(0); i < k; ++i) {
            dis[i] = 0;
            ava[i] = capa;
        }
        stack<Info> s;
        for (int i(0); i < k; ++i) {
            s.push(Info(0, i));
        }
       
        while (!s.empty()) {
            Info& curr(s.top());

            if (curr.idx == size) {
                int curr_max(0);
                for (int i(0); i < k; ++i) {
                    if (dis[i] > curr_max) {
                        curr_max = dis[i];
                    }
                }
                if (min == 0 || curr_max < min) {
                    min = curr_max;
                }
                s.pop();
                continue;
            }
            if (curr.add) {
                dis[curr.start] += cookies.at(curr.idx);
                ava[curr.start] -= 1;
                if (curr.idx + 1 < size) {
                    for (int i(0); i < k; ++i) {
                        if (ava[i] > 0) {
                            s.push(Info(curr.idx + 1, i));
                        }
                    }
                } else {
                    s.push(Info(curr.idx + 1, 0));
                }

                curr.add = false;
            } else {
                dis[curr.start] -= cookies.at(curr.idx);
                ava[curr.start] += 1;
                s.pop();
            }
        }
        return min;
    }
};
// @lc code=end