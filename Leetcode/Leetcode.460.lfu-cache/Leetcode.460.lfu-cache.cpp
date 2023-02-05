
// @lc app=leetcode id=460 lang=cpp
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
// Learned from a java solution, debugged for hours.
struct node {
    node* prev;
    node* next;
    int key;
    int val;
    int freq;

    node(int k, int v): prev(nullptr), next(nullptr), key(k), val(v), freq(1) {}
};

class DDL {
    public:
    DDL() {
        size_ = 0;
        head_ = nullptr;
        tail_ = nullptr;
    }

    void addToTail(node* curr) {
        
        size_ += 1;
        if (head_ == nullptr) {
            head_ = curr;
            tail_ = curr;
            return;
        }
        // cout << "!Size: " << size_ << " and " << (head_ == nullptr) ? 1 : 0 << '\n';
        // cout << '\n';
        

        curr->prev = tail_;
        tail_->next = curr;
        tail_ = curr;
    }

    node* getTail() {
        return tail_;
    }
    node* getHead() {
        return head_;
    }


    bool empty() {
        // cout << "Size: " << size_ << " and " << (tail_ == nullptr) ? 1 : 0 << '\n';
        // cout << '\n';
        return head_ == nullptr;
    }

    bool remove(node* curr) {
        // cout << "removing, size: " << size_ << '\n'; 
        size_ -= 1;
        if (curr == nullptr) {
            return false;
        }
        if (curr->prev) {
            curr->prev->next = curr->next;
            
        } else {
            head_ = curr->next;
        }
        if (curr->next) {
            curr->next->prev = curr->prev;
            
        } else {
            tail_ = curr->prev;
        }
        // if (head_) {
        //     cout << head_->val << " val\n";
        // }
        
        curr->prev = nullptr;
        curr->next = nullptr;
        return true;
    }

    ~DDL() {
        while (head_ && remove(tail_)) {}
    }

    private:
    node* head_;
    node* tail_;
    int size_;
};

class LFUCache {
public:
    int capacity;
    int size = 0;
    int minFreq = 0;
    node* cache[100000];
    DDL* map[200000];
    LFUCache(int c) {
        for (int i = 0; i < 100000; i++) {
            cache[i] = nullptr;
        }
        for (int i = 0; i < 200000; i++) {
            map[i] = nullptr;
        } 
        capacity = c;
    }
    
    void update(node* curr) {
        int freq = curr->freq;
        DDL* currList = map[freq];
        if (currList == nullptr) {
            return;
        }
        currList->remove(curr);
        if (freq == minFreq && currList->empty()) {
            minFreq += 1;
            map[freq] = nullptr;
            delete currList;
        }
        freq += 1;
        curr->freq = freq;
        
        DDL* newList = map[freq];
        if (newList == nullptr) {
            newList = new DDL();
            map[freq] = newList;
        }

        newList->addToTail(curr);
    }

    int get(int key) {
        node* curr = cache[key];
        if (curr == nullptr) {
            return -1;
        } 
        update(curr);
        // cout << curr->val << '\n';
        return curr->val;
    }
    
    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        //cout << size << '\n';
        if (cache[key] != nullptr) {
            node* curr = cache[key];
            curr->val = value;
            update(curr);
            return;
        }

        if (size == capacity) {
            DDL* currList = map[minFreq];
            node* head = currList->getHead();
            // cout << head->key << '!' << minFreq << '\n';
            cache[head->key] = nullptr;
            currList->remove(head);
        } else {
            size++;
        }
        minFreq = 1;
        
        node* newNode = new node(key, value);
        DDL* currList = map[1];
        if (currList == nullptr) {
            currList = new DDL();
            map[1] = currList;
        }
        currList->addToTail(newNode);
        cache[key] = newNode;
    }

    ~LFUCache() {
        // cout << "Deleting LFUCache\n";
        for (int i = 0; i < 200000; i++) {
            if (map[i]) {
                delete map[i];
                map[i] = nullptr;
            }
        } 
        for (int i = 0; i < 100000; i++) {
            if (cache[i]) {
                delete cache[i];
                cache[i] = nullptr;
            }
        }
    }
};

//["LFUCache","put","put","put","put","get"]\n[[2],[3,1],[2,1],[2,2],[4,4],[2]]
//["LFUCache","put","put","get","get","get","put","put","get","get","get","get"]\n[[3],[2,2],[1,1],[2],[1],[2],[3,3],[4,4],[3],[2],[1],[4]]
//["LFUCache","put","put","get","put","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2]]
//["LFUCache","put","put","put", "get"]\n[[2],[1,1],[2,2],[3,3], [1]]
//["LFUCache","put","put","get"]\n[[2],[1,1],[1,2],[1]]
//["LFUCache","put", "get"]\n[[2],[1,1], [1]]
//["LFUCache","put","put","get"]\n[[2],[1,1],[2,2],[1]]


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
/*
 *
 * [460] LFU Cache
 *
 * https://leetcode.com/problems/lfu-cache/description/
 *
 * algorithms
 * Hard (40.01%)
 * Likes:    3992
 * Dislikes: 244
 * Total Accepted:    177.1K
 * Total Submissions: 437.2K
 * Testcase Example:  '["LFUCache","put","put","get","put","get","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[3],[4,4],[1],[3],[4]]'
 *
 * Design and implement a data structure for a Least Frequently Used (LFU)
 * cache.
 * 
 * Implement the LFUCache class:
 * 
 * 
 * LFUCache(int capacity) Initializes the object with the capacity of the data
 * structure.
 * int get(int key) Gets the value of the key if the key exists in the cache.
 * Otherwise, returns -1.
 * void put(int key, int value) Update the value of the key if present, or
 * inserts the key if not already present. When the cache reaches its capacity,
 * it should invalidate and remove the least frequently used key before
 * inserting a new item. For this problem, when there is a tie (i.e., two or
 * more keys with the same frequency), the least recently used key would be
 * invalidated.
 * 
 * 
 * To determine the least frequently used key, a use counter is maintained for
 * each key in the cache. The key with the smallest use counter is the least
 * frequently used key.
 * 
 * When a key is first inserted into the cache, its use counter is set to 1
 * (due to the put operation). The use counter for a key in the cache is
 * incremented either a get or put operation is called on it.
 * 
 * The functions get and put must each run in O(1) average time complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get",
 * "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 * 
 * Explanation
 * // cnt(x) = the use counter for key x
 * // cache=[] will show the last used order for tiebreakers (leftmost element
 * is  most recent)
 * LFUCache lfu = new LFUCache(2);
 * lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
 * lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
 * lfu.get(1);      // return 1
 * ⁠                // cache=[1,2], cnt(2)=1, cnt(1)=2
 * lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest,
 * invalidate 2.
 * // cache=[3,1], cnt(3)=1, cnt(1)=2
 * lfu.get(2);      // return -1 (not found)
 * lfu.get(3);      // return 3
 * ⁠                // cache=[3,1], cnt(3)=2, cnt(1)=2
 * lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate
 * 1.
 * ⁠                // cache=[4,3], cnt(4)=1, cnt(3)=2
 * lfu.get(1);      // return -1 (not found)
 * lfu.get(3);      // return 3
 * ⁠                // cache=[3,4], cnt(4)=1, cnt(3)=3
 * lfu.get(4);      // return 4
 * ⁠                // cache=[4,3], cnt(4)=2, cnt(3)=3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= capacity <= 10^4
 * 0 <= key <= 10^5
 * 0 <= value <= 10^9
 * At most 2 * 10^5 calls will be made to get and put.
 * 
 * 
 * 
 * 
 */
