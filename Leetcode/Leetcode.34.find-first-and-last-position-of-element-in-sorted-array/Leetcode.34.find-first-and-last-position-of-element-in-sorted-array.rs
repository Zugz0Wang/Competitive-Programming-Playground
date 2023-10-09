impl Solution {
    pub fn search_range(nums: Vec<i32>, target: i32) -> Vec<i32> {
        fn find_begin(nums: &Vec<i32>, target: i32, mut head: usize, mut end: usize) -> usize {
            let mut found: bool = false;
            while (head < end) {
                let mid_idx: usize = (head + end) / 2;
                let mid_val: i32 = nums[mid_idx];
                if (mid_val == target) {
                    end = mid_idx;
                    found = true;
                } else if (target < mid_val) {
                    end = mid_idx;
                } else {
                    head = mid_idx + 1;
                }
            }
            if (found) {
                head
            } else {
                nums.len()
            }
        }

        fn find_end(nums: &Vec<i32>, target: i32, mut head: usize, mut end: usize) -> usize {
            let mut found: bool = false;
            while (head < end) {
                let mid_idx: usize = (head + end) / 2;
                let mid_val: i32 = nums[mid_idx];
                if (mid_val == target) {
                    head = mid_idx + 1;
                    found = true;
                } else if (target < mid_val) {
                    end = mid_idx;
                } else {
                    head = mid_idx + 1;
                }
            }
            if (found) {
                head
            } else {
                nums.len()
            }
        }

        let size: usize = nums.len();
        let begin: usize = find_begin(&nums, target, 0, size);
        let end: usize = find_end(&nums, target, begin, size);

        if (begin == size) {
            vec![-1, -1]
        } else {
            vec![begin as i32, (end as i32) - 1]
        }
    }
}