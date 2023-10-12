class Solution { // Hinted by (started blooming minus stopped blooming and tag binary search)
public:
    size_t bs(const vector<int>& arr, int target) {
        size_t begin(0);
        size_t end(arr.size());
        while (begin < end) {
            size_t mid_idx((begin + end) / 2);
            int mid_val(arr.at(mid_idx));
            if (target < mid_val) {
                end = mid_idx;
            } else {
                begin = mid_idx + 1;
            }
        }
        return begin;
    }

    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        const size_t size(flowers.size());
        vector<int> begin(size, 0);
        vector<int> end(size, 0);
        for (size_t i(0); i < size; ++i) {
            const vector<int>& flower(flowers.at(i));
            begin[i] = flower.at(0);
            end[i] = flower.at(1) + 1;
        }
        
        sort(begin.begin(), begin.end());
        sort(end.begin(), end.end());

        const size_t people_size(people.size());
        vector<int> ans(people_size, 0);

        for (size_t i(0); i < people_size; ++i) {
            int person(people.at(i));
            size_t started(bs(begin, person));
            size_t ended(bs(end, person));
            ans.at(i) = started - ended;
        }

        return ans;
    }
};