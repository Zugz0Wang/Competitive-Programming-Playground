impl Solution { // Hinted by (sort this array)
    pub fn min_operations(nums0: Vec<i32>) -> i32 {
        let mut nums: Vec<i32> = nums0;
        let len: usize = nums.len();
        let target: usize = len - 1;
        nums.sort();
        let mut i: usize = 0;
        let mut j: usize = 0;

        let mut count: usize = 0;
        let mut max: usize = 0;

        while j < len {
            let to_add: i32 = nums[j];
            count += 1;
            j += 1;
            while j < len && nums[j] == to_add {
                j += 1;
            }
            let mut curr_length: usize = (nums[j - 1] - nums[i]) as usize;
            while i < j && curr_length > target {
                let to_rm: i32 = nums[i];
                i += 1;
                count -= 1;
                while i < j && nums[i] == to_rm {
                    i += 1;
                }
                curr_length = (nums[j - 1] - nums[i]) as usize;
            }
            if count > max {
                max = count;
            }
        }
        (len - max) as i32
    }
}