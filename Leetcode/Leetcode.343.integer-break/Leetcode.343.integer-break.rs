impl Solution {
    pub fn integer_break(n: i32) -> i32 {
        let n = n as usize;
        let mut dp : Vec<i32> = vec![1; n + 1];
        dp[2] = 1;

        for i in (3..n+1) {
            dp[i - 1] = dp[i - 1].max(i as i32 - 1);
            let mut curr_dp: i32 = dp[i];
            curr_dp = i as i32 - 1;
            for j in (1..(i / 2 + 2)) {
                let curr : i32 = dp[j] * dp[i - j]; // if I use mutable i32 reference for curr_dp, then this dp[num] might change due to the change of curr_dp
                if curr_dp < curr {
                    curr_dp = curr;
                }
            }
            dp[i] = curr_dp;
        }

        dp[n]
    }
}