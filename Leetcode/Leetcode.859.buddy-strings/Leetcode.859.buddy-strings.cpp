// @lc app=leetcode id=859 lang=cpp
// @lc code=start
class Solution { // Independently solved
public:
    bool buddyStrings(string s, string goal) {
        const size_t size(s.size());
        if (size != goal.size()) {
            return false;
        }
        size_t slot1(size);
        size_t slot2(size);
        size_t count(0);
        bool* dic = new bool[26];
        for (size_t i(0); i < 26; ++i) {
            dic[i] = false;
        }
        bool flag(false);
        for (size_t i(0); i < size; ++i) {
            if (s.at(i) != goal.at(i)) {
                if (count == 2) {
                    return false;
                }
                count += 1;
                if (slot1 == size) {
                    slot1 = i;
                } else {
                    slot2 = i;
                }
            } else if (!flag) {
                size_t idx(s.at(i) - 'a');
                if (dic[idx] == true) {
                    flag = true;
                } else {
                    dic[idx] = true;
                }
            }
        }

        return (count == 0 && flag) || (count == 2 && s.at(slot1) == goal.at(slot2) && s.at(slot2) == goal.at(slot1));
    }
};
// @lc code=end