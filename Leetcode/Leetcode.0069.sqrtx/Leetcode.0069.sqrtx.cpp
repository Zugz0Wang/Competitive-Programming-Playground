class Solution {
public:
    int mySqrt(int x) {
        int head = 0;
        int tail = x;
        int mid = 0;
        while (head < tail) { // A binary search
            mid = (head + tail) / 2;
            long long pow = static_cast<long long>(mid) * mid;
            if (pow == x) {
                return mid;
            } else if (pow > x) {
                tail = mid;
            } else {
                head = mid + 1;
            }
        }
        mid = (head + tail) / 2;
        long long pow = static_cast<long long>(mid) * mid;
        if (pow > x) {
            mid -= 1;
        }
        return mid;
    }
};