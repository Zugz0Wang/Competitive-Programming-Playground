/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 *
 * https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
 *
 * algorithms
 * Medium (58.82%)
 * Likes:    1079
 * Dislikes: 21
 * Total Accepted:    27.9K
 * Total Submissions: 45.4K
 * Testcase Example:  '"TTFF"\n2'
 *
 * A teacher is writing a test with n true/false questions, with 'T' denoting
 * true and 'F' denoting false. He wants to confuse the students by maximizing
 * the number of consecutive questions with the same answer (multiple trues or
 * multiple falses in a row).
 * 
 * You are given a string answerKey, where answerKey[i] is the original answer
 * to the i^th question. In addition, you are given an integer k, the maximum
 * number of times you may perform the following operation:
 * 
 * 
 * Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i]
 * to 'T' or 'F').
 * 
 * 
 * Return the maximum number of consecutive 'T's or 'F's in the answer key
 * after performing the operation at most k times.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: answerKey = "TTFF", k = 2
 * Output: 4
 * Explanation: We can replace both the 'F's with 'T's to make answerKey =
 * "TTTT".
 * There are four consecutive 'T's.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: answerKey = "TFFT", k = 1
 * Output: 3
 * Explanation: We can replace the first 'T' with an 'F' to make answerKey =
 * "FFFT".
 * Alternatively, we can replace the second 'T' with an 'F' to make answerKey =
 * "TFFF".
 * In both cases, there are three consecutive 'F's.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: answerKey = "TTFTTFTT", k = 1
 * Output: 5
 * Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
 * Alternatively, we can replace the second 'F' to make answerKey =
 * "TTFTTTTT". 
 * In both cases, there are five consecutive 'T's.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == answerKey.length
 * 1 <= n <= 5 * 10^4
 * answerKey[i] is either 'T' or 'F'
 * 1 <= k <= n
 * 
 * 
 */

// @lc code=start
class Solution { // Independently solved (checked hints, but don't understand)
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        const size_t size(answerKey.size());
        int begin(0);
        int end(0);
        int use(0);
        int ans(0);
        while (end < size && begin <= end) {
            while (end < size && use <= k) {
                if (answerKey.at(end) == 'F') {
                    if (use < k) {
                        use += 1;
                    } else {
                        break;
                    }
                }
                end += 1;
            }
            if (end - begin > ans) {
                ans = end - begin;
            }
            // cout << answerKey.substr(begin, end - begin) << '\n';
            if (begin < end) {
                if (answerKey.at(begin) == 'F') {
                    use -= 1;
                }
                begin += 1;
            }
        }

        begin = 0;
        end = 0;
        use = 0;
        while (end < size && begin <= end) {
            while (end < size && use <= k) {
                if (answerKey.at(end) == 'T') {
                    if (use < k) {
                        use += 1;
                    } else {
                        break;
                    }
                }
                end += 1;
            }
            if (end - begin > ans) {
                ans = end - begin;
            }
            // cout << answerKey.substr(begin, end - begin) << '\n';
            if (begin < end) {
                if (answerKey.at(begin) == 'T') {
                    use -= 1;
                }
                begin += 1;
            }
        }
        return ans;
    }
};
// @lc code=end

