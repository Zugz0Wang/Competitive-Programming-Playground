#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max_profit = 0;
        int size = prices.size();
        for (int i = 1; i < size; i++) {
            int current = prices.at(i);
            int profit = current - min;// Maximum profit until this day
            if (profit > max_profit) {
                max_profit = profit;
            }
            if (current < min) {
                min = current;
            }
        }
        return max_profit;
    }
};