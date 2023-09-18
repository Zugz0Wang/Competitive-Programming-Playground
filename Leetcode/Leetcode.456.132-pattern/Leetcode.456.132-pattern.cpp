class Solution { // Learned from solution
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int third(INT_MIN);
        const int n(nums.size());
        for (int i(n - 1); i >= 0; --i) {
            int curr(nums.at(i));
            if (curr < third) {
                return true;
            }
            while (!s.empty() && s.top() < curr) {
                third = s.top();
                s.pop();
            }
            s.push(curr);
        }
        return false;
    }
};