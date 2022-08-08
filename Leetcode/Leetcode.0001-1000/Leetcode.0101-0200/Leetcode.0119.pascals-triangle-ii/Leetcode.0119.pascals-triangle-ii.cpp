#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> to_return{1};
        long previous = 1;
        for(int i = 1; i < rowIndex + 1; i++) {
            previous *= (rowIndex - i + 1);
            previous /= i;
            to_return.push_back(static_cast<int>(previous));
        }
        return to_return;
    }
};