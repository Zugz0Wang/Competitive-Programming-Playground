impl Solution { // Independently Solved
    pub fn sort_by_bits(mut arr: Vec<i32>) -> Vec<i32> {
        fn count(mut a: i32) -> u32 {
            let mut ans: u32 = 0;
            while a > 0 {
                if a & 1 == 1 {
                    ans += 1;
                }
                a = a >> 1;
            }
            ans
        }
        fn cmp(a: &i32, b: &i32) -> std::cmp::Ordering {
            let c_a: u32 = count(*a);
            let c_b: u32 = count(*b);
            if c_a == c_b {
                a.cmp(&b)
            } else {
                c_a.cmp(&c_b)
            }
        }

        arr.sort_by(cmp);
        arr
    }
}