/*
 * @lc app=leetcode id=835 lang=cpp
 *
 * [835] Image Overlap
 *
 * https://leetcode.com/problems/image-overlap/description/
 *
 * algorithms
 * Medium (61.08%)
 * Likes:    198
 * Dislikes: 64
 * Total Accepted:    49.9K
 * Total Submissions: 81.6K
 * Testcase Example:  '[[1,1,0],[0,1,0],[0,1,0]]\n[[0,0,0],[0,1,1],[0,0,1]]'
 *
 * You are given two images, img1 and img2, represented as binary, square
 * matrices of size n x n. A binary matrix has only 0s and 1s as values.
 * 
 * We translate one image however we choose by sliding all the 1 bits left,
 * right, up, and/or down any number of units. We then place it on top of the
 * other image. We can then calculate the overlap by counting the number of
 * positions that have a 1 in both images.
 * 
 * Note also that a translation does not include any kind of rotation. Any 1
 * bits that are translated outside of the matrix borders are erased.
 * 
 * Return the largest possible overlap.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: img1 = [[1,1,0],[0,1,0],[0,1,0]], img2 = [[0,0,0],[0,1,1],[0,0,1]]
 * Output: 3
 * Explanation: We translate img1 to right by 1 unit and down by 1 unit.
 * 
 * The number of positions that have a 1 in both images is 3 (shown in red).
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: img1 = [[1]], img2 = [[1]]
 * Output: 1
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: img1 = [[0]], img2 = [[0]]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == img1.length == img1[i].length
 * n == img2.length == img2[i].length
 * 1 <= n <= 30
 * img1[i][j] is either 0 or 1.
 * img2[i][j] is either 0 or 1.
 * 
 * 
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int count[20000] = {0};
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int kSize = img1.size();
        const int kSize2 = 9 * kSize * kSize;
        const int kSize3 = kSize * 3;
        vector<int> a_positions;
        vector<int> b_positions;
        for (int i = 0; i < kSize; i++) {
            for (int j = 0; j < kSize; j++) {
                if (img1.at(i).at(j)) {
                    a_positions.push_back(i * kSize3 + j);
                }
                if (img2.at(i).at(j)) {
                    b_positions.push_back(i * kSize3 + j);
                }
            }
        }
        for (int pos_a : a_positions) {
            for (int pos_b : b_positions) {
                count[(pos_a - pos_b) + kSize2] += 1;
            }
        }
        int max_val = 0;
        for (int i = 0; i < 2 * kSize2; i++) {
            if (count[i] > max_val) {
                max_val = count[i];
            }
        }
        return max_val;
    }
};
// @lc code=end

