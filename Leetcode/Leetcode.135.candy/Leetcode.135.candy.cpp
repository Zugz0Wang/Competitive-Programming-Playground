class PQ { // Independently solved
  size_t* start;
  vector<size_t*> heap;
  vector<size_t> find;
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
      
      find[heap[a] - start] = a;
      find[heap[b] - start] = b;
  }

  bool compare_element(size_t a, size_t b) const {
      return *(heap[a]) < *(heap[b]);
  }

  void heapifyUp(size_t i) {
      size_t curr(i);
      
      while (curr < N) {
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
      return;
  }

  long rawIdx(size_t i) const {
        return heap[i] - start;
    }

    void build() {
        for (size_t i(N - 1); i < N; --i) {
            heapifyDown(i);
        }
    }

  public:
  PQ(size_t* info, size_t N_): start(info), N(N_) {
      heap.resize(N, nullptr);
      find.resize(N,0);
      
      for (size_t i(0); i < N; ++i) {
          heap.at(i) = info + i;
          find.at(i) = i;
      }
      
      build();
  }
  size_t size() const {
      return N;
  }
  size_t top() const {
      if (N == 0) {
          throw std::out_of_range("Error: empty queue.");
      }
      return rawIdx(0);
  }

  void pop(size_t curr) {
      size_t i(find[curr]);
      if (heap[i] - start != (long)curr) {
          throw std::out_of_range("Pointer error.");
      }
      swap_element(i, N - 1);
      --N;
      update(rawIdx(i));
      find[curr] = -1;
  }

  bool contains(size_t curr) const {
      return find[curr] < N;
  }
      
  void update(size_t curr) {
      size_t i(find[curr]);
      // cout << "Updating " << curr << '\n';
      if (heap[i] - start != (long)curr) {
          throw std::out_of_range("Pointer error.");
      }
      
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
  }
};

class Solution { // Independently solved
public:
    int candy(vector<int>& ratings) {
      const size_t size(ratings.size());
      vector<vector<int>> adj0(size);
      vector<vector<int>> adj1(size);
      vector<size_t> degrees(size);
      for (size_t i(0); i < size; ++i) {
        int curr_rate(ratings.at(i));
        vector<int>& prev(adj0.at(i));
        
        if (i > 0 && curr_rate > ratings.at(i - 1)) {
          prev.push_back(i - 1);
          adj1.at(i - 1).push_back(i);
        }
        if (i < size - 1 && curr_rate > ratings.at(i + 1)) {
          prev.push_back(i + 1);
          adj1.at(i + 1).push_back(i);
        }
        degrees.at(i) = prev.size();
      }
      PQ pq(degrees.data(), degrees.size());
      vector<size_t> candies(size, 0);
      int ans(0);
      while (pq.size() > 0) {
        size_t curr(pq.top());
        size_t& curr_candy(candies.at(curr));
        const vector<int>& prevs(adj0.at(curr));
        if (prevs.size() == 0) {
          curr_candy = 1;
        } else {
          size_t max_prev(1);
          for (size_t prev : prevs) {
            if (candies.at(prev) > max_prev) {
              max_prev = candies.at(prev);
            } else if (candies.at(prev) == 0) {
              throw out_of_range("Error!");
            }
          }
          curr_candy = max_prev + 1;
        }
        pq.pop(curr);
        const vector<int>& nexts(adj1.at(curr));
        for (size_t next : nexts) {
          degrees.at(next) -= 1;
          pq.update(next);
        }
        ans += curr_candy;
      }
      return ans;
    }
};