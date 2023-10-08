impl Solution { // Learned from solution

    pub fn max_dot_product(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let M: usize = nums1.len();
        let N: usize = nums2.len();
        let mut dp: Vec<i32> = vec![i32::min_value(); N + 1];

        fn max(a: i32, b: i32) -> i32 {
            if a >= b {
                a
            } else {
                b
            }
        }

        fn update_max(a: &mut i32, b: i32) {
            if *a < b {
                *a = b;
            }
        }

        for i in 1..M + 1 {
            // let prev: Vec<i32> = dp.to_vec();
            let mut prev0: i32 = max(0, dp[0]);
            for j in 1..N + 1 {
                // let prev0: i32 = max(0, prev[j - 1]);
                let prev1: i32 = dp[j];
                let curr0: i32 = dp[j - 1];

                dp[j] = max(max(prev1, curr0), max(prev1, prev0 + nums1[i - 1] * nums2[j - 1]));
                update_max(&mut prev0, prev1);
            }
        }

        dp[N]
    }
}