class Solution { // Learned from solution
public:
    vector<vector<int>> adj;
    vector<int> ans;
    int size;
    void dfs(int i) {
        vector<int>& nexts(adj.at(i));
        while (!nexts.empty()) {
            int next = nexts.back();
            nexts.pop_back();
            dfs(next);
        }
        ans.push_back(i);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        set<string> s;
        for (const vector<string>& ticket : tickets) {
            if (s.count(ticket.at(0)) == 0) s.insert(ticket.at(0));
            if (s.count(ticket.at(1)) == 0) s.insert(ticket.at(1));
        }
        size = s.size();
        map<string, int> mp;
        vector<string> rmp(size);
        int count(0);
        for (const string& i : s) {
            mp.insert(pair<string, int>(i, count));
            rmp.at(count) = i;
            count += 1;
        }
        
        adj.resize(size);
        for (const vector<string>& ticket : tickets) {
            int from(mp.at(ticket.at(0)));
            int to(mp.at(ticket.at(1)));
            adj.at(from).push_back(to);
        }
        for (vector<int>& curr : adj) {
            sort(curr.rbegin(), curr.rend());
        }
        // cout << mp.at("JFK") << '\n';
        dfs(mp.at("JFK"));
        const int tickets_size(tickets.size() + 1);
        vector<string> str_ans(tickets_size);
        for (int i(0); i < tickets_size; ++i) {
            str_ans.at(i) = rmp.at(ans.at(tickets_size - 1 - i));
        }
        return str_ans;
    }
};