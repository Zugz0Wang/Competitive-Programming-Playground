/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */
#include <vector>
using namespace std;
// @lc code=start
class FenwickTree {
    public:
        FenwickTree(int size) {
            size_ = size + 1;
            frequency_table_.assign(size + 1, 0);
        }
        int RangeSumQuery(int upper_bound) {
            int sum = 0;
            for (; upper_bound > 0; upper_bound -= LeastSignificantOneBit(upper_bound)) {
                sum += frequency_table_.at(upper_bound);
            }
            return sum;
        }
        int RangeSumQuery(int lower_bound, int upper_bound) {
            return RangeSumQuery(upper_bound) - RangeSumQuery(lower_bound - 1);
        }
        void RangeUpdatePointQuery(int idx, int value) {
            for (; idx < size_; idx += LeastSignificantOneBit(idx)) {
                frequency_table_.at(idx) += value;
            }
        }
    private:
        int size_ = 0;
        vector<int> frequency_table_;
        int LeastSignificantOneBit(int S) {
            return (S) & (-S);
        }
};
class NumArray {
public:
    FenwickTree tree_ = FenwickTree(1);
    vector<int> nums_;
    NumArray(vector<int>& nums) {
        const int kSize = nums.size();
        tree_ = FenwickTree(kSize);
        nums_ = nums;
        for (int i = 0; i < kSize; i++) {
            tree_.RangeUpdatePointQuery(i + 1, nums.at(i));
        }
    }
    
    int sumRange(int left, int right) {
        return tree_.RangeSumQuery(left + 1, right + 1);
    }
    
    void update(int index, int val) {
        int current = nums_.at(index);
        nums_.at(index) = val;
        tree_.RangeUpdatePointQuery(index + 1, val - current);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

