// @lc app=leetcode id=956 lang=cpp
// @lc code=start
class Solution { // Independently solved (hinted by tags and titles)
public:
    int tallestBillboard(vector<int>& rods) {
        int* need0 = new int[3500];
        int* need = new int[3500];
        for (size_t i(0); i < 2500; ++i) {
            need0[i] = 0;
            need[i] = 0;
        }
        for (int rod : rods) {
            // cout << rod << '\n';
            for (size_t i(0); i < 2500; ++i) {
                need[i] = need0[i];
            }
            for (size_t i(0); i < 2500; ++i) {
                if (need0[i] >= i) { // [5]: 8 // [5]: 8 ->3
                    int opt0(i - rod);
                    int opt1(i + rod);
                    
                    if (opt0 < 0) {
                        need[-opt0] = max(need[-opt0], need0[i] - opt0);
                    } else {
                        need[opt0] = max(need[opt0],need0[i]);
                    }
                    need[opt1] = max(need[opt1], need0[i] + rod);
                }
            }
           
            // for (size_t i(0); i < 2500; ++i) {
            //     if (need[i] >= i) {
            //         cout << "Lack " << i << " to " << need[i] << '\n';
            //     }
            // }
            // cout << "\n\n";

            int* temp(need);
            need = need0;
            need0 = temp;
        }
        return need0[0];
    }
};
// @lc code=end