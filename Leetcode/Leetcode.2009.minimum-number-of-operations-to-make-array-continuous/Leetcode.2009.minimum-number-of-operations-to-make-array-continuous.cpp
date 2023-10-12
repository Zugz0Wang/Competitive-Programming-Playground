class Solution { // Hinted by (sort this array)
public:

    int minOperations(vector<int>& nums_v) {
        const size_t size(nums_v.size());
        int* nums(nums_v.data());
        sort(nums + 0, nums + size);
        // for (size_t i(0); i < size; ++i) {
        //     cout << nums[i] << ',';
        // }
        size_t i(0);
        size_t j(0);

        size_t length(size - 1);

        // set<int> s;
        // s.insert(nums[0]);
        
        size_t count(0);
        size_t max(0);
        while (j < size) {
            int to_add(nums[j]);
            ++count;
            ++j;
            while (j < size && nums[j] == to_add) {
                ++j;
            }
            
            size_t curr_length(nums[j - 1] - nums[i]);
            while (i < j && curr_length > length) {
                int to_remove(nums[i]);
                --count;
                ++i;
                while (i < j && nums[i] == to_remove) {
                    ++i;
                }
                curr_length = nums[j - 1] - nums[i];
            }
            // cout << i << ' ' << j << ' ' << count << '\n';
            if (count > max) {
                max = count;
            }
        }
        // cout << max;
        return (int)size - (int)max;
    }
};