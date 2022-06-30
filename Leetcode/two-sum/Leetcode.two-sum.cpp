#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
//https://leetcode.com/problems/two-sum
class Solution {
public:
    int binary_search(vector<pair<int,int>>& nums, int target, int start, int end) {
        int mid = (start + end) / 2;
        while(start < end) {
            pair<int, int> temp = nums.at(mid);
            if (temp.first == target) {
                return temp.second;
            } else if (temp.first > target) {
                end = mid;
                mid = (start + end) / 2;
            } else {
                start = mid + 1;
                mid = (start + end) / 2;
            }
        }
        return -1;  
    }
    
    static bool compareFunc(pair<int,int> &a, pair<int,int> &b) {
        return a.first < b.first;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> num_index_pair_vector;
        vector<int> to_return{0,0};
        // Initialize the vector for sort and binary search
        for(int i = 0; i < nums.size(); i++) {
            pair<int,int> temp = {nums[i], i};
            num_index_pair_vector.push_back(temp);
        }
        // Sort the vector for binary search
        sort(num_index_pair_vector.begin(),num_index_pair_vector.end(),compareFunc);
        for(int i = 0; i < nums.size(); i++) {
            int tempIndex = binary_search(num_index_pair_vector, target - num_index_pair_vector.at(i).first, i + 1, nums.size());
            if (tempIndex >= 0) { // If found
                to_return.at(0) = (num_index_pair_vector.at(i).second);
                to_return.at(1) = (tempIndex);
                break;
            }
        }
        return to_return;
    }
};