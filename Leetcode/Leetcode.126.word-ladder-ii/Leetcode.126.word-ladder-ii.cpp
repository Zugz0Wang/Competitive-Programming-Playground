/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    void getNeighbours(vector<string>& wordList, string& curr_str, vector<string>& neighbours, unordered_set<string>& words) {
        const int kLength = wordList.at(0).length();
        const int kListSize = wordList.size();
        
        if (kListSize >=  kLength * 20) {
            string left_part;
            string right_part = curr_str.substr(1, kLength - 1);
            for (int j = 0; j < kLength; j++) {
                for (char k = 'a'; k <= 'z'; k++) {
                    string new_str = left_part + k + right_part;
                    // cout << new_str << ' ';
                    if (words.count(new_str)) {
                        neighbours.push_back(new_str);
                    }
                }
                left_part += curr_str.at(j);
                right_part.erase(0, 1);
            }
        } else {
            for (int j = 0; j < kListSize; j++) {
                string& comp_str = wordList.at(j);
                int count = 0;
                for (int k = 0; k < kLength; k++) {
                    if (comp_str[k] != curr_str[k]) {
                        count++;
                        if (count == 2) {
                            break;
                        }
                    }
                }
                if (count == 1) {
                    neighbours.push_back(comp_str);
                }
            }
        }
    }

    vector<vector<string>> buildLadders(string& endWord, unordered_map<string, vector<string>>& backtrack) {
        vector<vector<string>> to_return;
        
        vector<string>& prev = backtrack.at(endWord);
        if (prev.empty()) {
            return {{endWord}};
        }
        for (string parent: prev) {
            vector<vector<string>> temp = buildLadders(parent, backtrack);
            for (vector<string> j: temp) {
                j.push_back(endWord);
                to_return.push_back(j);
            }
        }
        return to_return;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> to_return;
        unordered_set<string> words;
        queue<string> waitlist;
        unordered_set<string> visited;
        unordered_map<string, vector<string>> backtrack;
        for (auto i: wordList) {
            words.insert(i);
        }
        
        if (words.count(endWord) == 0) {
            return to_return;
        }

        waitlist.push(beginWord);
        visited.insert(beginWord);
        backtrack.insert(pair<string, vector<string>>(beginWord,{}));
        int length = 0;
        bool found = false;
        unordered_set<string> curr_level;
        while (!waitlist.empty() && !found) {
            length++;
            const int kSize = waitlist.size();
            int i = 0;
            
            while (i < kSize) {
                string curr_str = waitlist.front();
                waitlist.pop();
                
                // cout << curr_str ;//waitlist.size() << ' ' << graph.count(curr_str) << '\n';
                if (curr_str == endWord) {
                    found = true;
                }
                
                vector<string> neighbours;
                getNeighbours(wordList, curr_str, neighbours, words);
                const int kNeighbourSize = neighbours.size();
                for (int j = 0; j < kNeighbourSize; j++) {
                    string& neighbour = neighbours.at(j);
                    
                    if (backtrack.count(neighbour) == 0) {
                        curr_level.insert(neighbour);
                        waitlist.push(neighbour);
                        // visited.insert(neighbour);
                        backtrack.insert(pair<string, vector<string>>(neighbour,{}));
                    }
                    if (curr_level.count(neighbour)) {
                        backtrack.at(neighbour).push_back(curr_str); 
                    }
                    
                }
                i++;
                // cout << "!\n";
            }
            // cout << "!!\n";
            curr_level.clear();
        }
        if (found) to_return = buildLadders(endWord, backtrack);
        return to_return;
    }
};
// @lc code=end

