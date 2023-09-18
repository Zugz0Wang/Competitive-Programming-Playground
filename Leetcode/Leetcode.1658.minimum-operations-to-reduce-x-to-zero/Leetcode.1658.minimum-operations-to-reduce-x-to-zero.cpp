class Solution { // Independently solved
public:
    int minOperations(vector<int>& nums, int x) {
        int size(nums.size());
        vector<int> pre_v(size, 0);
        int* pre(pre_v.data());
        pre[0] = nums.at(0);
        for (int i(1); i < size; ++i) {
            pre[i] = pre[i - 1] + nums[i]; 
        }
        int begin(0);
        int end(0);
        int curr_sum(0);
        int max_len(-1);
        int target(pre[size - 1] - x);
        
        for (; end <= size && begin <= end;) {
            
            while (end < size && curr_sum < target) {
                curr_sum += nums.at(end);
                ++end;
            }
            // cout << begin << ' ' << end << '\n';
            if (curr_sum == target && (max_len < 0 || max_len < end - begin)) {
                // cout << begin << ' ' << end << '\n';
                max_len = end - begin;
            }
            if (begin < end) {
                curr_sum -= nums.at(begin);
                ++begin;
            } else {
                break;
            }
            
        }
        return max_len < 0? -1 : size - max_len;
    }
};