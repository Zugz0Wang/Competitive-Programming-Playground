/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    MountainArray* m;
    int* copy;
    int get(size_t idx) {
        int& curr(copy[idx]);
        if (curr < 0) {
            curr = m->get(idx);
        }
        return curr;
    }
    int findInMountainArray(int target, MountainArray &m_r) {
        // cout << "-----\n";
        m = &m_r;
        const size_t size(m->length());
        vector<int> copy_v(size + 1, -1);
        copy = copy_v.data();

        if (target < get(0) && target < get(size - 1)) {
            return -1;
        }

        size_t begin(0);
        size_t end(size - 1);
        while (begin < end) {
            const size_t mid_idx((begin + end) / 2);
            // cout << mid_idx << '\n';
            const int mid_val(get(mid_idx));
            const int mid_val1(get(mid_idx + 1));
            
            if (mid_val1 - mid_val > 0) {
                begin = mid_idx + 1;
            } else {
                end = mid_idx;
            }
        }
        const size_t peak_idx(begin);
        if (target > get(peak_idx)) {
            return -1;
        }
        begin = 0;
        end = peak_idx;
        // cout << "First Part\n";
        while (begin < end) {
            size_t mid_idx((begin + end) / 2);
            // cout << mid_idx << '\n';
            int mid_val(get(mid_idx));
            if (target == mid_val) {
                return mid_idx;
            } else if (target < mid_val) {
                end = mid_idx;
            } else {
                begin = mid_idx + 1;
            }
        }
        // cout << "Second Part\n";
        begin = peak_idx;
        end = size;
        while (begin < end) {
            size_t mid_idx((begin + end) / 2);
            int mid_val(get(mid_idx));
            if (target == mid_val) {
                return mid_idx;
            } else if (target > mid_val) {
                end = mid_idx;
            } else {
                begin = mid_idx + 1;
            }
        }
        return -1;
    }
};