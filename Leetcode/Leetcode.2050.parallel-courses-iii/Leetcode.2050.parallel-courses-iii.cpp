template <class K, class V>
class MyPQ {
    /**
    @author Zhifeng Wang
    */

    vector<V*> heap;
    vector<K> i_to_k;
    map<K, size_t> k_to_i;
    size_t N;

    size_t parent(size_t i) const {
        return ((i + 1) / 2) - 1;
    }

    size_t left(size_t i) const {
        return ((i + 1) * 2) - 1;
    }

    size_t right(size_t i) const {
        return (i + 1) * 2;
    }

    void swap_element(size_t a, size_t b) {
        swap(heap[a], heap[b]);
        
        K& a_key(i_to_k[a]);
        K& b_key(i_to_k[b]);
        
        k_to_i[a_key] = b;
        k_to_i[b_key] = a;

        swap(a_key, b_key);
    }

    bool compare_element(size_t a, size_t b) const {
        return *(heap[a]) < *(heap[b]);
    }

    void heapifyUp(size_t i) {
        size_t curr(i);
        
        while (curr < N) {
            // cout << curr << '\n';
            size_t prev(parent(curr));
            if (prev >= N) {
                return;
            }
            if (compare_element(curr, prev)) {
                swap_element(curr, prev);
                curr = prev;
            } else {
                return;
            }
        }
    }

    void heapifyDown(size_t i) {
        size_t curr(i);
        
        while (curr < N) {
            size_t l(left(curr));
            size_t r(right(curr));
            
            size_t next;
            if (l < N && r < N) {
                if (compare_element(l, r)) {
                    next = l;
                } else {
                    next = r;
                }
            } else if (l < N) {
                next = l;
            } else if (r < N) {
                next = r;
            } else {
                return;
            }
            if (compare_element(next, curr)) {
                swap_element(next, curr);
                curr = next;
            } else {
                return;
            }
        }
    }

    void update(size_t i) {
        
        size_t p(parent(i));
        size_t l(left(i));
        size_t r(right(i));
        bool cmp_p(false);
        if (p < N) {
            cmp_p = compare_element(i, p);
        }
        bool cmp_l(false);
        if (l < N) {
            cmp_l = compare_element(l, i);
        }
        bool cmp_r(false);
        if (r < N) {
            cmp_r = compare_element(r, i);
        }
        if (cmp_p && (cmp_l || cmp_r)) {
            
            throw std::out_of_range("It seems the heap structure was broken.");
        }
        
        if (cmp_p) {
            heapifyUp(i);
        } else if (cmp_l || cmp_r) {
            heapifyDown(i);
        }
        // check("After Update"+std::to_string(i));
    }

    public:

    MyPQ(): N(0) {}

    void insert_remote(const K key, V* value) {
        // cout << "insert::" << key << ' ' << value << '\n';
        if (k_to_i.count(key) > 0) {
            return;
        }
        heap.push_back(value);
        k_to_i.insert(pair<K, size_t>(key, N));
        i_to_k.push_back(key);
        ++N;
        heapifyUp(N - 1);
    }

    V* get_value_pointer(const K& key) {
        return heap[k_to_i[key]];
    }

    void update_value(const K& key) {
        size_t i(k_to_i[key]);
        update(i);
    }

    size_t size() const {
        return N;
    }

    K top() const {
        if (N == 0) {
            throw std::out_of_range("Error: empty queue.");
        }
        return i_to_k[0];
    }

    void pop() {
        size_t i(0);
        if (N == 0) {
            throw std::out_of_range("Error: empty queue.");
        }
        const K key(i_to_k[0]);
        swap_element(i, N - 1);
        --N;
        heapifyDown(0);
        
        heap.pop_back();
        k_to_i.erase(key);
        i_to_k.pop_back();
    }

    bool contains(const K& key) const {
        return k_to_i.count(key) > 0;
    }
};

class Solution {
public:
    struct Course {
        size_t needs;
        int finish_time;
        vector<int> nexts;
        Course(): needs(0), finish_time(-1) {}
        bool operator<(const Course& that) {
            return finish_time < that.finish_time;
        }
    };

    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        MyPQ<size_t, Course> learning{};
        vector<Course> courses_v(n);
        Course* courses(courses_v.data());
        
        for (const vector<int>& relation : relations) {
            int a(relation.at(0) - 1);
            int b(relation.at(1) - 1);
            Course& a_c(courses[a]);
            Course& b_c(courses[b]);
            a_c.nexts.push_back(b);
            b_c.needs += 1;
        }

        for (int i(0); i < n; ++i) {
            Course& c(courses[i]);
            if (c.needs == 0) {
                c.finish_time = time.at(i);
                learning.insert_remote(i, courses + i);
            }
        }
        int ans(0);
        while (learning.size() > 0) {
            int c_i(learning.top());
            learning.pop();
            Course& c(courses[c_i]);
            ans = c.finish_time;
            const vector<int>& nexts(c.nexts);
            for (int next : nexts) {
                Course& next_c(courses[next]);
                next_c.needs -= 1;
                if (next_c.needs == 0) {
                    next_c.finish_time = c.finish_time + time[next];
                    learning.insert_remote(next, courses + next);
                }
            }
        }
        return ans;
    }
};