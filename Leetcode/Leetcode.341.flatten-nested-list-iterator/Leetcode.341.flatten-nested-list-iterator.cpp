/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    struct Trav {
        vector<NestedInteger>* node;
        size_t i;
        Trav(vector<NestedInteger>* n): node(n), i(0) {}
        bool hasNext() {
            return i < node->size();
        }
        bool nextInt() {
            return node->at(i).isInteger();
        }
        int getInt() {
            int ret(node->at(i).getInteger());
            ++i;
            return ret;
        }
        vector<NestedInteger>* getList() {
            vector<NestedInteger>* ret(&(node->at(i).getList()));
            ++i;
            return ret;
        }
    };

    stack<Trav> s;

    void toNext() {
        if (s.empty()) {
            return;
        }
        Trav* curr(&(s.top()));
        while (!s.empty() && !curr->hasNext()) {
            s.pop();
            if (s.empty()) {
                return;
            }
            curr = &(s.top());
        }
        
        while (curr->hasNext() && !(curr->nextInt())) {
            s.push(Trav(curr->getList()));
            curr = &(s.top());
        }
    }

    void toTrueNext() {
        toNext();
        while (!s.empty()) {
            if (s.top().hasNext()) {
                break;
            }
            s.pop();
            toNext();
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        s.push(Trav(&nestedList));
        toTrueNext();
    }
    
    int next() {
        Trav curr(s.top());
        s.pop();
        int ret(curr.getInt());
        if (curr.hasNext()) {
            s.push(curr);
        }
    
        toTrueNext();
        
        // cout << ret << '\n';
        return ret;
    }
    
    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */