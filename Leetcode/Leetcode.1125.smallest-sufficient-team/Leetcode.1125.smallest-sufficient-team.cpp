/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 *
 * https://leetcode.com/problems/smallest-sufficient-team/description/
 *
 * algorithms
 * Hard (47.16%)
 * Likes:    1524
 * Dislikes: 40
 * Total Accepted:    37K
 * Total Submissions: 69.6K
 * Testcase Example:  '["java","nodejs","reactjs"]\n[["java"],["nodejs"],["nodejs","reactjs"]]'
 *
 * In a project, you have a list of required skills req_skills, and a list of
 * people. The i^th person people[i] contains a list of skills that the person
 * has.
 * 
 * Consider a sufficient team: a set of people such that for every required
 * skill in req_skills, there is at least one person in the team who has that
 * skill. We can represent these teams by the index of each person.
 * 
 * 
 * For example, team = [0, 1, 3] represents the people with skills people[0],
 * people[1], and people[3].
 * 
 * 
 * Return any sufficient team of the smallest possible size, represented by the
 * index of each person. You may return the answer in any order.
 * 
 * It is guaranteed an answer exists.
 * 
 * 
 * Example 1:
 * Input: req_skills = ["java","nodejs","reactjs"], people =
 * [["java"],["nodejs"],["nodejs","reactjs"]]
 * Output: [0,2]
 * Example 2:
 * Input: req_skills = ["algorithms","math","java","reactjs","csharp","aws"],
 * people =
 * [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
 * Output: [1,2]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= req_skills.length <= 16
 * 1 <= req_skills[i].length <= 16
 * req_skills[i] consists of lowercase English letters.
 * All the strings of req_skills are unique.
 * 1 <= people.length <= 60
 * 0 <= people[i].length <= 16
 * 1 <= people[i][j].length <= 16
 * people[i][j] consists of lowercase English letters.
 * All the strings of people[i] are unique.
 * Every skill in people[i] is a skill in req_skills.
 * It is guaranteed a sufficient team exists.
 * 
 * 
 */

// @lc code=start
class Solution { // Learned from solution
public:
    vector<size_t> ppl;
    size_t* dp;
    size_t req_size;
    size_t ppl_size;
    size_t goal;

    vector<int> curr;
    vector<int> ans;

    size_t helper(size_t i, size_t curr_skill) {

        size_t& curr_dp(dp[curr_skill * ppl_size + i]);

        if (i >= ppl_size) {
            if (curr_skill == goal) {
                if (ans.size() == 0 || curr.size() < ans.size()) {
                    // for (auto s : curr) {
                    //     cout << s << ' ';
                    // }
                    // cout << '\n';
                    ans = curr;
                }
            }
            return curr_dp;
        }
        
        if (curr_dp <= curr.size()) {
            return curr_dp;
        }


        curr.push_back(i);

        size_t select(helper(i + 1, curr_skill | ppl.at(i)));

        curr.pop_back();

        size_t non_select(helper(i + 1, curr_skill));

        // if (select < non_select) {
        //     curr_dp = select;
        // } else {
        //     curr_dp = non_select;
        // }

        if (curr.size() > 0) {
            // cout << select << ' ' << non_select << '\n';

            curr_dp = curr.size(); // This is a key
        }
        return curr_dp;
    }

    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string, size_t> dict;
        req_size = req_skills.size();
        for (size_t i(0); i < req_size; ++i) {
            dict.insert(pair<string, size_t>(req_skills.at(i), 1 << i));
        }
        ppl_size = people.size();
        
        ppl.resize(ppl_size);
        for (size_t i(0); i < ppl_size; ++i) {
            size_t& curr(ppl.at(i));
            curr = 0;
            for (string& skill : people.at(i)) {
                if (dict.count(skill) == 0) {
                    continue;
                }
                size_t skill_idx(dict.at(skill));
                curr = curr | skill_idx;
            }
        }
        goal = (1 << req_size) - 1;
        vector<size_t> dpv((ppl_size + 1) * (1 << req_size), req_size + 1);
        dp = dpv.data();
        helper(0, 0);
        return ans;
    }
};
// @lc code=end

