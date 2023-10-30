impl Solution { // Hinted(although almost solution)
    pub fn poor_pigs(buckets: i32, minutes_to_die: i32, minutes_to_test: i32) -> i32 {
        let T: u32 = 1 + (minutes_to_test / minutes_to_die) as u32;
        let mut begin: usize = 0;
        let mut end: usize = buckets as usize;
        fn check(mut p: u32, mut k: u32, buckets: u32) -> bool {
            let mut ans: u32 = 1;
            while (k > 0) {
                if k % 2 == 1 {
                    ans *= p;
                    if (ans >= buckets) {
                        return true;
                    }
                }
                p *= p;
                k /= 2;
            }
            return ans >= buckets;
        }
       
        while (begin < end) {
            let mid: usize = (begin + end) / 2;
            if check(T, mid as u32, buckets as u32) {
                end = mid;
            } else {
                begin = mid + 1;
            }
        }
        return (begin as i32);
    }
}