/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 *
 * https://leetcode.com/problems/snapshot-array/description/
 *
 * algorithms
 * Medium (37.26%)
 * Likes:    2676
 * Dislikes: 356
 * Total Accepted:    160K
 * Total Submissions: 429.9K
 * Testcase Example:  '["SnapshotArray","set","snap","set","get"]\n[[3],[0,5],[],[0,6],[0,0]]'
 *
 * Implement a SnapshotArray that supports the following interface:
 * 
 * 
 * SnapshotArray(int length) initializes an array-like data structure with the
 * given length. Initially, each element equals 0.
 * void set(index, val) sets the element at the given index to be equal to
 * val.
 * int snap() takes a snapshot of the array and returns the snap_id: the total
 * number of times we called snap() minus 1.
 * int get(index, snap_id) returns the value at the given index, at the time we
 * took the snapshot with the given snap_id
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: ["SnapshotArray","set","snap","set","get"]
 * [[3],[0,5],[],[0,6],[0,0]]
 * Output: [null,null,0,null,5]
 * Explanation: 
 * SnapshotArray snapshotArr = new SnapshotArray(3); // set the length to be 3
 * snapshotArr.set(0,5);  // Set array[0] = 5
 * snapshotArr.snap();  // Take a snapshot, return snap_id = 0
 * snapshotArr.set(0,6);
 * snapshotArr.get(0,0);  // Get the value of array[0] with snap_id = 0, return
 * 5
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= length <= 5 * 10^4
 * 0 <= index < length
 * 0 <= val <= 10^9
 * 0 <= snap_id < (the total number of times we call snap())
 * At most 5 * 10^4 calls will be made to set, snap, and get.
 * 
 * 
 */

// @lc code=start
class SnapshotArray { // Independently solved
public:
    struct Info {
        size_t begin;
        size_t end;
        size_t val;
        Info(size_t b, size_t e, size_t v): begin(b), end(e), val(v) {}
    };
    size_t snap_id = 0;
    vector<vector<Info>> snaps;
    SnapshotArray(int length) {
        snaps.resize(length, vector<Info>{Info(0, 1e5, 0)});
    }
    
    void set(int index, int val) {
        vector<Info>& curr(snaps.at(index));
        const size_t last_idx(curr.size() - 1);
         Info& last(curr.at(last_idx));
        if (last.val == val) {
            return;
        }

        last.end = snap_id;
        curr.push_back(Info(snap_id, 1e5, val));
    }
    
    int snap() {
        snap_id += 1;
        return snap_id - 1;
    }
    
    int get(int index, int snap_id) {
        vector<Info>& curr(snaps.at(index));
        size_t begin(0);
        size_t end(curr.size());
        while (begin < end) {
            size_t mid_idx((begin + end) / 2);
            Info& mid_val(curr.at(mid_idx));
            if (snap_id >= mid_val.begin && snap_id < mid_val.end) {
                return mid_val.val;
            } else if (snap_id < mid_val.begin) {
                end = mid_idx;
            } else {
                begin = mid_idx + 1;
            }
        }
        return -1;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end

