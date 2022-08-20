/*
 * @lc app=leetcode id=871 lang=cpp
 *
 * [871] Minimum Number of Refueling Stops
 *
 * https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
 *
 * algorithms
 * Hard (35.99%)
 * Likes:    3637
 * Dislikes: 66
 * Total Accepted:    99.9K
 * Total Submissions: 257.5K
 * Testcase Example:  '1\n1\n[]'
 *
 * A car travels from a starting position to a destination which is target
 * miles east of the starting position.
 * 
 * There are gas stations along the way. The gas stations are represented as an
 * array stations where stations[i] = [positioni, fueli] indicates that the
 * i^th gas station is positioni miles east of the starting position and has
 * fueli liters of gas.
 * 
 * The car starts with an infinite tank of gas, which initially has startFuel
 * liters of fuel in it. It uses one liter of gas per one mile that it drives.
 * When the car reaches a gas station, it may stop and refuel, transferring all
 * the gas from the station into the car.
 * 
 * Return the minimum number of refueling stops the car must make in order to
 * reach its destination. If it cannot reach the destination, return -1.
 * 
 * Note that if the car reaches a gas station with 0 fuel left, the car can
 * still refuel there. If the car reaches the destination with 0 fuel left, it
 * is still considered to have arrived.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: target = 1, startFuel = 1, stations = []
 * Output: 0
 * Explanation: We can reach the target without refueling.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: target = 100, startFuel = 1, stations = [[10,100]]
 * Output: -1
 * Explanation: We can not reach the target (or even the first gas station).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: target = 100, startFuel = 10, stations =
 * [[10,60],[20,30],[30,30],[60,40]]
 * Output: 2
 * Explanation: We start with 10 liters of fuel.
 * We drive to position 10, expending 10 liters of fuel.  We refuel from 0
 * liters to 60 liters of gas.
 * Then, we drive from position 10 to position 60 (expending 50 liters of
 * fuel),
 * and refuel from 10 liters to 50 liters of gas.  We then drive to and reach
 * the target.
 * We made 2 refueling stops along the way, so we return 2.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= target, startFuel <= 10^9
 * 0 <= stations.length <= 500
 * 0 <= positioni <= positioni+1 < target
 * 1 <= fueli < 10^9
 * 
 * 
 */
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution { // '1\n1\n[]' // '100\n10\n[[10,60],[20,30],[30,30],[60,40]]'
public:
    vector<vector<int>> stations_;
    vector<int> idxs_;
    
    bool found = false;
    // int minRefuelStopsHelper(int target, int start_idx, int startFuel, int previous_max = -1) {
    //     const int kSize = stations_.size();
    //     int curr_miles = 0;
    //     int new_fuel = 0;
    //     if (start_idx > -1 && start_idx < kSize) {
    //         new_fuel = stations_.at(start_idx).at(1);
    //         startFuel += new_fuel;
    //         curr_miles = stations_.at(start_idx).at(0);
    //     }
    //     cout << target << ' ' << curr_miles << ' ' << start_idx << ' ' << startFuel << '\n';
    //     if (target <= startFuel) {
    //         found = true;
    //         return 0;
    //     }
    //     if (start_idx >= kSize - 1 && target > startFuel) {
    //         return -1;
    //     }
    //     if (previous_max > new_fuel) {
    //         return -1;
    //     }
    //     int next_idx = start_idx + 1;
    //     vector<int> idxs;
    //     while (next_idx < kSize && startFuel >= stations_.at(next_idx).at(0) - curr_miles) {
    //         idxs.push_back(next_idx);
    //         next_idx++;
    //     }
    //     next_idx -= 1;

    //     bool start = false;
    //     int min_stop = -1;
    //     sort(idxs.begin(), idxs.end(), [this](int i, int j) {
    //         return stations_.at(i).at(1) > stations_.at(j).at(1);
    //     });
    //     int i = 0;
    //     // for (int i : idxs) {
    //     //     cout << i << '\n';
    //     // }
    //     const int kIdxsSize = idxs.size();
    //     while (i < kIdxsSize) {
    //         next_idx = idxs.at(i);
    //         int j = 0;
    //         //cout << "loop start\n";
    //         if (i + 1 < kIdxsSize) {
    //             int curr_idx = idxs.at(i + 1);
    //             if (stations_.at(curr_idx).at(1) > previous_max) {
    //                 previous_max = stations_.at(curr_idx).at(1);
    //             }
    //         }
    //         //cout << "loop end\n";
    //         int next_miles = stations_.at(next_idx).at(0);
    //         int next_cost = next_miles - curr_miles;
    //         int stop_number = minRefuelStopsHelper(target - next_cost, next_idx, startFuel - next_cost, previous_max);
    //         // cout << stop_number << '\n';
    //         if (start) {
    //             if ((stop_number > -1 && min_stop == -1) || (stop_number < min_stop) && stop_number > -1) {
    //                 min_stop = stop_number;
    //             }
    //         } else {
    //             start = true;
    //             min_stop = stop_number;
    //         }
    //         if (found) {
    //             cout << target << ' ' << curr_miles << ' ' << start_idx << ' ' << startFuel << ' ' << min_stop + 1 << '\n';
    //             return min_stop + 1;
    //         }
    //         i++;
    //     }
    //     cout << target << ' ' << curr_miles << ' ' << start_idx << ' ' << startFuel << ' ' << min_stop << '\n';
    //     if (min_stop > -1) {
    //         return min_stop + 1;
    //     } else {
    //         return -1;
    //     }
        
    // }
    vector<vector<long long>> dp_table;
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        const int kSize = stations.size() + 1;
        vector<long long> row(kSize ,0);
        dp_table.assign(kSize, row);
        
        if (startFuel >= target) {
            return 0;
        }

        for (int i = 0; i < kSize; i++) {
            dp_table.at(i).at(0) = startFuel;
        }
        int start = 1;
        for (int j = 1; j < kSize; j++) {
            for (int i = start; i < kSize; i++) {
                long long station_mile = stations.at(i - 1).at(0);
                long long station_fuel = stations.at(i - 1).at(1);
                long long curr = dp_table.at(i).at(j);
                long long prev = dp_table.at(i - 1).at(j);
                long long prev1 = dp_table.at(i - 1).at(j - 1);
                if (i > j) {
                    curr = max(curr,prev);
                    dp_table.at(i).at(j) = curr;
                }
                if (prev1 >= station_mile) {
                    dp_table.at(i).at(j) = max(curr, prev1 + station_fuel);
                }
            }
            start++;
            if (dp_table.at(kSize - 1).at(j) >= target) {
                return j;
            }
        }
        return -1;
    }
};
// @lc code=end
// '100\n50\n[[25,50], [50,25]]'
// '1000\n299\n[[26,244],[196,238],[201,279],[318,265],[341,1],[627,69],[647,175],[678,70],[870,255],[993,221]]'
// '1000\n299\n[[13,21],[26,115],[100,47],[225,99],[299,141],[444,198],[608,190],[636,157],[647,255],[841,123]]'
// '1000\n10\n[[7,217],[10,211],[17,146],[21,232],[25,310],[48,175],[53,23],[63,158],[71,292],[96,85],[100,302],[102,295],[116,110],[122,46],[131,20],[132,19],[141,13],[163,85],[169,263],[179,233],[191,169],[215,163],[224,231],[228,282],[256,115],[259,3],[266,245],[283,331],[299,21],[310,224],[315,188],[328,147],[345,74],[350,49],[379,79],[387,276],[391,92],[405,174],[428,307],[446,205],[448,226],[452,275],[475,325],[492,310],[496,94],[499,313],[500,315],[511,137],[515,180],[519,6],[533,206],[536,262],[553,326],[561,103],[564,115],[582,161],[593,236],[599,216],[611,141],[625,137],[626,231],[628,66],[646,197],[665,103],[668,8],[691,329],[699,246],[703,94],[724,277],[729,75],[735,23],[740,228],[761,73],[770,120],[773,82],[774,297],[780,184],[791,239],[801,85],[805,156],[837,157],[844,259],[849,2],[860,115],[874,311],[877,172],[881,109],[888,321],[894,302],[899,321],[908,76],[916,241],[924,301],[933,56],[960,29],[979,319],[983,325],[988,190],[995,299],[996,97]]'
// '1000\n299\n[[14,123],[145,203],[344,26],[357,68],[390,35],[478,135],[685,108],[823,186],[934,217],[959,80]]'
// 0 1 3 6 7
// '11\n2\n[[1,4],[2,5],[3,2],[4,2]]'
// '1000000000\n1000000000\n[[5,1000000000],[1000,1000000000],[100000,1000000000]]'