#include<vector>
#include<algorithm>
using namespace std;
//https://leetcode.com/problems/maximum-units-on-a-truck/
class Solution {
public:
    static bool compareFunc(vector<int> &a, vector<int> &b) { //compare function for sort
        return a.at(1) > b.at(1);
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), compareFunc);
        int sum = 0;
        int count = 0;
        for (auto i:boxTypes) {
            if (count + i.at(0) > truckSize) {
                sum += (truckSize - count) * i.at(1);
                break;
            } else {
                sum += i.at(0) * i.at(1);
                count += i.at(0);
            }
        }
        return sum;
    }
};