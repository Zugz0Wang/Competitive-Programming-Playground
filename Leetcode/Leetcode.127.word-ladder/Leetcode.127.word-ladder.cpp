/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
#include <string>
#include <vector>
#include <map>
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

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        queue<string> waitlist;
        unordered_set<string> visited;
        
        for (auto i: wordList) {
            words.insert(i);
        }
        
        if (words.count(endWord) == 0) {
            return 0;
        }

        waitlist.push(beginWord);
        visited.insert(beginWord);
        int length = 0;
        while (!waitlist.empty()) {
            length++;
            const int kSize = waitlist.size();
            int i = 0;
            while (i < kSize) {
                string curr_str = waitlist.front();
                waitlist.pop();
                
                // cout << curr_str ;//waitlist.size() << ' ' << graph.count(curr_str) << '\n';
                if (curr_str == endWord) {
                    return length;
                }
                
                vector<string> neighbours;
                getNeighbours(wordList, curr_str, neighbours, words);
                const int kNeighbourSize = neighbours.size();
                for (int j = 0; j < kNeighbourSize; j++) {
                    string& neighbour = neighbours.at(j);
                    if (visited.count(neighbour) == 0) {
                        waitlist.push(neighbour);
                        visited.insert(neighbour);
                    }
                }
                i++;
                // cout << "!\n";
            }
            // cout << "!!\n";
        }
        return 0;
    }
};
// @lc code=end
// "qa"\n"sq"\n["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]
