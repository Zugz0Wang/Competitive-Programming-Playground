// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn find_mode(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        struct Info {
            k: i32,
            v: u32,
        }
        impl Info {
            fn new(k: i32) -> Self {
                Info { k, v: 1}
            }

            fn k(&self) -> i32 {
                self.k.clone()
            }

            fn v(&self) -> u32 {
                self.v.clone()
            }

            fn inc(&mut self) {
                self.v += 1;
            }
        }
        let mut count: Vec<Info> = Vec::new();
        fn trav(root: &Option<Rc<RefCell<TreeNode>>>, count: &mut Vec<Info>) {
            if root.is_none() {
                return;
            }
            let curr_root = root.clone().unwrap();
            let tree_root: &TreeNode = &curr_root.as_ref().borrow();
            let curr_val: i32 = tree_root.val.clone();
            trav(&tree_root.left, count);
            match count.last_mut() {
                Some(info) => {
                    if info.k() == curr_val {
                        info.inc();
                    } else {
                        count.push(Info::new(curr_val));
                    }
                },
                None => {
                    count.push(Info::new(curr_val));
                }
            }
            trav(&tree_root.right, count);
        }
        trav(&root, &mut count);
        let mut max_count: u32 = 0;
        for i in count.iter() {
            if i.v() > max_count {
                max_count = i.v();
            }
        }

        let mut ans: Vec<i32> = Vec::new();
        for i in count.iter() {
            if i.v() == max_count {
                ans.push(i.k());
            }
        }
        ans
    }
}