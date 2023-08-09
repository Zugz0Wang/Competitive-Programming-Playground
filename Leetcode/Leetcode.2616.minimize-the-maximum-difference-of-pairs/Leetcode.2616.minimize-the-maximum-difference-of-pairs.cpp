class Solution { // Hinted
public:
    size_t size;
    int p;
    int* nums;
    int* dp;
    int helper(size_t i, int x, int skip, int select) {
        if (x >= p) {
            return 0;
        }
        if (i >= size) {
            return 2147483647;
        }
        if (size - i < 2 * (p - x)) {
            return 2147483647;
        }
        
        int curr_diff(nums[i + 1] - nums[i]);

        if (skip < 0) {
            skip = 2147483647;
        }
        if (select < 0) {
            select = 0;
            // select = 2147483647;
        }
        if (skip < curr_diff) {
            return skip;
        }
        
        return min(max(curr_diff, select), skip);
    }
    int minimizeMax(vector<int>& nums_, int p_) {
        p = p_;
        sort(nums_.begin(), nums_.end());
        size = nums_.size();
        nums = nums_.data();
        vector<int> dp_v((size * 2), -1);
        dp = dp_v.data();

        size_t row(1);
        size_t row1(0);
        for (size_t i(0); i < size; ++i) {
            dp[row1 * size + i] = 0; // p
        }
        
        row = 1;
        for (int curr_p(p - 1); curr_p >= 0; --curr_p) {
            for (size_t i(size - 1); i < size && i >= (2 * curr_p); --i) {
                int skip(-1);
                if (i < size - 1) {
                    skip = dp[row * size + (i + 1)];
                }
                int select(-1);
                if (i < size - 2) {
                    select = dp[row1 * size + (i + 2)];
                }
                dp[row * size + i] = helper(i, curr_p, skip, select);
            }
            swap(row, row1);
        }

        return dp[row1 * size];
    }
    // int* nums;
    // size_t size;
    // bool can_form_pairs(size_t mid_idx, int p) {
    //     int count(0);
    //     for (int i(1); i < size && count < p;) {
    //         if (nums[i] - nums[i - 1] <= mid_idx) {
    //             count++;
    //             i += 2;
    //         } else {
    //             i++;
    //         }
    //     }
    //     return count >= p;
    // }

    // public:
    // int minimizeMax(vector<int>& nums_, int p) {
    //     nums = nums_.data();
    //     size = nums_.size();
    //     sort(nums + 0, nums + size);
        
    //     int begin(0);
    //     int end(nums[size - 1] - nums[0]);
        
    //     while (begin < end) {
    //         size_t mid_idx((begin + end) / 2);
    //         if (can_form_pairs(mid_idx, p)) {
    //             end = mid_idx;
    //         } else {
    //             begin = mid_idx + 1;
    //         }
    //     }
        
    //     return begin;
    // }

};