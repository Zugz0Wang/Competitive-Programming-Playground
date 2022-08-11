#include <vector>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        const int kMsize = 2; // This is for majoryity n problem
        int flag = 0;
        vector<int> majority;
        vector<int> count;
        vector<int> count1;
        for (int i = 0; i < kMsize; i++) {
            majority.push_back(0);
            count.push_back(0);
            count1.push_back(0);
        }
        
        const int kSize = nums.size();
        for (int i = 0; i < kSize; i++) {
            int current = nums.at(i);
            bool not_in = true;// Treat this as a loop based big else if
            for (int j = 0; j < flag; j++) {
                if (current == majority.at(j)) {
                    count.at(j)++;
                    not_in = false;
                    break;
                }
            }
            if (not_in && flag < kMsize) {
                majority.at(flag) = current;
                count.at(flag) = 1;
                flag++;
                not_in = false;
            }
            if (not_in) {
                for (int j = 0; j < flag; j++) {
                    if (count.at(j) == 0) {
                        majority.at(j) = current;
                        count.at(j) = 1;
                        not_in = false;
                        break;
                    }
                }
            }
            
            if (not_in) {
                for (int j = 0; j < flag; j++) {
                    count.at(j)--;
                }
            }
            
        }

        for (int i = 0; i < kSize; i++) {
            int current = nums.at(i);
            for (int j = 0; j < flag; j++) {
                if (majority.at(j) == current) {
                    count1.at(j)++;
                }
            }
        }
        int threshold = kSize / (kMsize + 1);
        vector<int> to_return;
        for (int j = 0; j < flag; j++) {
            if (count1.at(j) > threshold) {
                to_return.push_back(majority.at(j));
            }
        }
        
        return to_return;
    }
};