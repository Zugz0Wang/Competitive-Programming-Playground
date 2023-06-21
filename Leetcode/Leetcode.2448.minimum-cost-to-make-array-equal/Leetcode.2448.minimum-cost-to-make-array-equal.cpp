class Solution { // Independently solved
public:
    long long minCost(vector<int>& nums, vector<int>& cost) { 
        const size_t size(nums.size());

        vector<pair<int, int>> helper(size);
        vector<long> sums(size, 0);
        for (size_t i(0); i < size; ++i) {
            pair<int, int>& curr(helper.at(i));
            curr.first = nums.at(i);
            curr.second = cost.at(i);
        }
        

        sort(helper.begin(), helper.end());
        sums.at(0) = helper.at(0).second;
        for (size_t i(1); i < size; ++i) {
            sums.at(i) = sums.at(i - 1) + helper.at(i).second;
        }

        long long ans(0);
        int curr( helper.at(0).first);
        long long curr_cost(0);
        for (size_t i(1); i < size; ++i) {
        
            int next( helper.at(i).first);
            if (next > curr) {
                curr_cost += (long long) helper.at(i).second * (next - curr);
            } else {
                curr_cost += (long long) helper.at(i).second * (curr - next);
            }
        }
        ans = curr_cost;
        for (size_t i(1); i < size; ++i) {
            int prev_val(helper.at(i - 1).first);
            int curr_val(helper.at(i).first);
            int diff(curr_val - prev_val);

            curr_cost += diff * (sums.at(i - 1));
            curr_cost -= diff * (sums.at(size - 1) - sums.at(i - 1));

            if (ans > curr_cost) {
                ans = curr_cost;
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     long long minCost(vector<int>& nums, vector<int>& cost) {
//         const size_t size(nums.size());
//         vector<size_t> indices(size, 0);
//         vector<long> sums(size, 0);
//         for (size_t i(0); i < size; ++i) {
//             indices.at(i) = i;
//         }

//         auto compare = [nums](const size_t i, const size_t j) {
//             return nums.at(i) < nums.at(j);
//         };

//         sort(indices.begin(), indices.end(), compare);
//         sums.at(0) = cost.at(indices.at(0));
//         for (size_t i(1); i < size; ++i) {
//             sums.at(i) = sums.at(i - 1) + cost.at(indices.at(i));
//         }

//         long long ans(0);
//         int curr(nums.at(indices.at(0)));
//         long long curr_cost(0);
//         for (size_t i(1); i < size; ++i) {
//             const size_t idx(indices.at(i));
//             int next(nums.at(idx));
//             if (next > curr) {
//                 curr_cost += (long long)cost.at(idx) * (next - curr);
//             } else {
//                 curr_cost += (long long)cost.at(idx) * (curr - next);
//             }
//         }
//         ans = curr_cost;
//         for (size_t i(1); i < size; ++i) {
//             int prev_val(nums.at(indices.at(i - 1)));
//             int curr_val(nums.at(indices.at(i)));
//             int diff(curr_val - prev_val);

//             curr_cost += diff * (sums.at(i - 1));
//             curr_cost -= diff * (sums.at(size - 1) - sums.at(i - 1));

//             if (ans > curr_cost) {
//                 ans = curr_cost;
//             }
//         }
//         return ans;
//     }
// };