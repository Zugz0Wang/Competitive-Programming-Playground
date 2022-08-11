#include <string>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string to_return;
        
        while (columnNumber > 0) { // Strange 26-cimal number
            columnNumber -= 1;
            int mod = columnNumber % 26;
            to_return = char('A' + mod) + to_return;
            columnNumber = columnNumber / 26;
        }
        return to_return;
    }
};