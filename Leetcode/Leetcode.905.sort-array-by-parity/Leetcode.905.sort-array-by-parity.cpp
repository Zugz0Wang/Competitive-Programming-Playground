class Solution { // Independently solved
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int head(0);
        const int size(nums.size());
        for (int i(0); i < size; ++i) {
            if (nums.at(i) % 2 == 0) {
                swap(nums.at(i), nums.at(head));
                ++head;
            }
        }
        return nums;
    }
};