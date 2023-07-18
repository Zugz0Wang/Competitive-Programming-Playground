/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (40.43%)
 * Likes:    18179
 * Dislikes: 805
 * Total Accepted:    1.4M
 * Total Submissions: 3.3M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 * 
 * Implement the LRUCache class:
 * 
 * 
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 * 
 * 
 * The functions get and put must each run in O(1) average time complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 * 
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 * 
 * 
 */

// @lc code=start
class LRUCache { // Independently solved
    struct Node {
        int key;
        int val;
        Node* prev = nullptr;
        Node* next = nullptr;
        Node(int k, int v, Node* p, Node* n): key(k), val(v), prev(p), next(n) {}
    };

    Node* cache[10001];
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;
    int capa;

    void remove(Node* curr) {
        Node* prev_node(curr->prev);
        Node* next_node(curr->next);
        curr->prev = nullptr;
        curr->next = nullptr;
        if (prev_node) {
            prev_node->next = next_node;
        } else {
            head = next_node;
        }
        if (next_node) {
            next_node->prev = prev_node;
        } else {
            tail = prev_node;
        }
    }

    void pushToHead(Node* curr) {
        curr->next = head;
        if (head) {
            head->prev = curr;
        }
        head = curr;
        if (tail == nullptr) {
            tail = head;
        }
    }

    public:
    LRUCache(int capacity): capa(capacity) {
        for (size_t i(0); i < 10001; ++i) {
            cache[i] = nullptr;
        }
    }

    int get(int key) {
        Node* curr(cache[key]);
        if (curr == nullptr) {
            return -1;
        }
        remove(curr);
        pushToHead(curr);
        // print(0);
        return curr->val;
    }
    
    void put(int key, int value) {
        Node* curr(cache[key]);
        // print(1);
        // cout << "Creating\n";
        if (curr == nullptr) {
            if (size == capa) {
                // cout << "deleting\n";
                
                Node* del_node(tail);
                int del_key(tail->key);
                
                cache[del_key] = nullptr;
                
                remove(del_node);
                delete del_node;
                
                --size;
            }
            ++size;
            curr = new Node(key, value, nullptr, nullptr);
            cache[key] = curr;
        } else {
            remove(curr);
            curr->val = value;
        }
        pushToHead(curr);
        // print(2);
    }

    void print(int a) {
        Node* curr(head);
        cout << a << ": ";
        while (curr) {
            cout << '('<< curr->key << ',' << curr->val << ')' << ' ';
            curr = curr->next;
        }
        cout << '\n';
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

