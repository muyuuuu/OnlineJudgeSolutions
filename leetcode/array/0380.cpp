class RandomizedSet {
public:

    vector<int> v;
    unordered_map<int, int> m;

    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.count(val))
            return false;
        else {
            m[val] = v.size();
            v.push_back(val);
        }
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!m.count(val))
            return false;
        else {
            int t1 = m[val];
            int t2 = v.size() - 1;
            m[v[t2]] = t1;

            int tmp;
            tmp = v[t1];
            v[t1] = v[t2];
            v[t2] = tmp;
            
            v.pop_back();
            m.erase(val);
        }
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

// 执行用时： 192 ms , 在所有 C++ 提交中击败了 79.24% 的用户
// 内存消耗： 94.9 MB , 在所有 C++ 提交中击败了 11.05% 的用户
