// @lc app=leetcode id=1575 lang=cpp
// @lc code=start
class Solution { // Independently solved (hinted by tags and titles)
public:
    struct City {
        int pos;
        int idx;
        City(): pos(0), idx(0) {}
        bool operator<(const City& other) {
            if (pos == other.pos) {
                return idx < other.idx;
            }
            return pos < other.pos;
        }
    };
    int* dp;
    City* cities;

    int max_fuel;
    size_t* idx;
    size_t size;
    int finish;

    int mod = 1e9 + 7;
    int helper(int start, int fuel) {
        // cout << start << ' ' << fuel << ' ' <<max_fuel * start + fuel<< '\n';
        int& curr(dp[max_fuel * start + fuel]);
        if (fuel < 1) {
            return 0;
        }
        if (curr >= 0) {
            return curr;
        }
        curr = 0;
        size_t i(idx[start]);
        int curr_pos(cities[i].pos);
        size_t next_i(i - 1);
        int cost(0);
        while (next_i < size && (cost = (curr_pos - cities[next_i].pos)) <= fuel) {
            curr = ((long)curr + helper(cities[next_i].idx, fuel - cost)) % mod;
            if (cities[next_i].idx == finish) {
                curr = (1 + curr) % mod;
            }
            next_i -= 1;
        }
        next_i = i + 1;
        while (next_i < size && (cost = (cities[next_i].pos) - curr_pos) <= fuel) {
            curr = ((long)curr + helper(cities[next_i].idx, fuel - cost)) % mod;
            if (cities[next_i].idx == finish) {
                curr = (1 + curr) % mod;
            }
            next_i += 1;
        }
        return curr;
    }
    int countRoutes(vector<int>& locations, int start, int finish_, int fuel) {
        finish = finish_;
        size = locations.size();
        max_fuel = fuel + 1;

        cities = new City[size];
        for (size_t i(0); i < size; ++i) {
            City& curr(cities[i]);
            curr.pos = locations.at(i);
            curr.idx = i;
        }
        sort(cities, cities + size);

        idx = new size_t[size];
        for (size_t i(0); i < size; ++i) {
            idx[cities[i].idx] = i;
        }

        dp = new int[size * max_fuel];
        
        // cout << size * max_fuel << '\n';
        for (size_t i(0); i < size * max_fuel; ++i) {
            dp[i] = -1;
        }

        int ans(helper(start, fuel));

        delete[] dp;
        delete[] idx;
        delete[] cities;
        if (start == finish) {
            ans = (ans + 1) % mod;
        }
        return ans;
    }
};
// @lc code=end