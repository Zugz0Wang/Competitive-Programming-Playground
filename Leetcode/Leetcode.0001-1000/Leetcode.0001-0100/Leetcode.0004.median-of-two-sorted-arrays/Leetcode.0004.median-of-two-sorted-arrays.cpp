#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            swap(nums1,nums2);
        }
        
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        
        if (nums1_size < 1) {
            int nums2_mid = nums2_size / 2;
            if (nums2_size % 2 == 1) {
                return static_cast<double>(nums2.at(nums2_mid));
            } else {
                return (static_cast<double>(nums2.at(nums2_mid - 1)) + nums2.at(nums2_mid)) / 2;
            }
        }
        
        int begin = 0;
        int end = nums1.size();
        const int tot_size = nums1.size() + nums2.size();
        const int half_s_size = (nums1.size() + nums2.size()) / 2;
        const int half_b_size = tot_size - half_s_size;
        bool tot_size_odd = (nums1.size() + nums2.size()) % 2 == 1;
        while (true) { // Binary search
            int nums1_mid = (begin + end) / 2;
            int nums1_small_size = nums1_mid;
            int nums2_mid = half_s_size - nums1_mid;
            
            int nums1_big_size = nums1_size - nums1_small_size;
            int nums2_small_size = nums2_mid;
            int nums2_big_size = nums2_size - nums2_small_size;
            
            int last_all_small = 0;
            int first_all_big = 0;
            
            if (nums1_mid > 0 && nums1.at(nums1_mid - 1) > nums2.at(nums2_mid)) {
                end = nums1_mid; // Search the left part
            } else if ( nums1_mid < nums1_size && nums2_mid > 0 && nums1.at(nums1_mid) < nums2.at(nums2_mid - 1)) {
                begin = nums1_mid + 1; // Search the right part
            } else {
                if (nums1_big_size < 1) { // Calculating median
                    first_all_big = nums2.at(nums2_mid);
                } else if (nums2_big_size < 1) {
                    first_all_big = nums1.at(nums1_mid);
                } else {
                    first_all_big = min(nums1.at(nums1_mid), nums2.at(nums2_mid));
                }
                if (nums1_small_size < 1) {
                    last_all_small = nums2.at(nums2_mid - 1);
                } else if (nums2_small_size < 1) {
                    last_all_small = nums1.at(nums1_mid - 1);
                } else {
                    last_all_small = max(nums1.at(nums1_mid - 1), nums2.at(nums2_mid - 1));
                }
                
                if (tot_size_odd) {
                    return static_cast<double>(first_all_big);
                } else {
                    return (static_cast<double>(last_all_small) + first_all_big) / 2;
                }
            }
            
        }
    }
};