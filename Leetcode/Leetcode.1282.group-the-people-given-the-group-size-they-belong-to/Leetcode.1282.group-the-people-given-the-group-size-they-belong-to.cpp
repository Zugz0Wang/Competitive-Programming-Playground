class Solution { // Hinted
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        const size_t size(groupSizes.size());
        vector<pair<int, int>> people(size);
        for (size_t i(0); i < size; ++i) {
            pair<int, int>& curr(people.at(i));
            curr.first = groupSizes.at(i);
            curr.second = i;
        }
        sort(people.begin(), people.end());
        vector<vector<int>> ans{{}};
        vector<int>* curr_p(&(ans.at(0)));
        for (size_t i(0); i < size; ++i) {
            vector<int>& curr(*curr_p);
            const pair<int, int>& person(people.at(i));
            curr.push_back(person.second);
            if (curr.size() == person.first && i < size - 1) {
                ans.push_back({});
                curr_p = &(ans.at(ans.size() - 1));
            }
        }
        return ans;
    }
};