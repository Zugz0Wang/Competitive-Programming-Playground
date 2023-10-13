impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let len: usize = cost.len();
        let mut dp: Vec<i32> = vec![0; len + 1];
        fn min(a: i32, b: i32) -> i32 {
            if a <= b {
                a
            } else {
                b
            }
        }
        for i in 2..len + 1 {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            // println!("{}, {}", i, dp[i]);
        }
        dp[len]
    }
}