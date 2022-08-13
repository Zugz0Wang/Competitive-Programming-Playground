#include <stdint.h>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t to_return = 0;
        const uint32_t kOne = 1;
        for (int i = 0; i < 32; i++) {
            to_return = to_return << 1; // next digit
            to_return = to_return | (n & kOne);
            n = n >> 1; // next digit
        }
        
        return to_return;
    }
};