impl Solution { // Learned from solution
    pub fn count_vowel_permutation(n: i32) -> i32 {
        let mut prev_a: u64 = 1;
        let mut prev_e: u64 = 1;
        let mut prev_i: u64 = 1;
        let mut prev_o: u64 = 1;
        let mut prev_u: u64 = 1;
        let m: u64 = 1e9 as u64 + 7;
        for i in 2..=n {
            let next_a = (prev_e + prev_u + prev_i) % m;
            let next_e = (prev_a + prev_i) % m;
            let next_i = (prev_e + prev_o) % m;
            let next_o = prev_i;
            let next_u = (prev_o + prev_i) % m;

            prev_a = next_a;
            prev_e = next_e;
            prev_i = next_i;
            prev_o = next_o;
            prev_u = next_u;
        }
        return ((prev_a + prev_e + prev_i + prev_o + prev_u) % m) as i32;
    }
}