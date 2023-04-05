#include <vector>
using namespace std;
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) { // Original
        const int kSize(nums.size());
        long long bar(nums.at(0));
        long long available(0);
        for (int i(1); i < kSize; ++i) {
            long long curr(nums.at(i));
            if (curr <= bar) {
                available += bar - curr;
            } else {
                long long diff(curr - bar);
                if (diff > available) {
                    diff -= available;
                    available = 0;
                    int columns(i + 1);
                    if (diff % columns == 0) {
                        bar += diff / columns;
                    } else {
                        bar += (diff / columns) + 1;
                        available = columns - (diff % columns);
                    }
                } else {
                    available -= diff;
                }
            }
            // cout << bar << ' ' << available << '\n';
        }
        return bar;
    }
};