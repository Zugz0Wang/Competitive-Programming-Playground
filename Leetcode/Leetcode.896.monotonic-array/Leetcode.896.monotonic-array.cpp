class Solution { // Independently solved
public:
    bool isMonotonic(vector<int>& nums) {
        const int size(nums.size());
        if (size == 1) {
            return true;
        }
        int state(0);
        for (int i(1); i < size; ++i) {
            int prev(nums.at(i - 1));
            int curr(nums.at(i));
            if (prev == curr) {
                continue;
            }
            if (state == 0) {
                if (prev < curr) {
                    state = 1;
                } else {
                    state = -1;
                }
            } else {
                if (state == -1 && prev < curr) {
                    return false;
                } else if (state == 1 && prev > curr) {
                    return false;
                }
            }
        }
        return true;
    }
};