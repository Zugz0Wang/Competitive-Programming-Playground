#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> to_return;
        vector<int> empty;
        for (int i = 0; i < numRows; i++) {
            to_return.push_back(empty);
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    to_return.at(i).push_back(1); // Base case
                } else {
                    int top_left = to_return.at(i - 1).at(j - 1);
                    int top_right = to_return.at(i - 1).at(j);
                    to_return.at(i).push_back(top_left+top_right); // Recursive definition
                }
            }
        }
        return to_return;
    }
};