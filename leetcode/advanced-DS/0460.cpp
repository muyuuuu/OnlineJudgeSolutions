class Node {
public:
    int cnt;
    int tim;
    int key;
    int val;

    Node() = default;

    Node(int c, int t, int k, int v) {
        cnt = c;
        tim = t;
        key = k;
        val = v;
    }

    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? tim < rhs.tim : cnt < rhs.cnt;
    }

};

class LFUCache {
public:

    int capcity{0};
    int time{0};
    int size{0};

    set<Node> list;
    unordered_map<int, Node> m;

    LFUCache(int c) {
        capcity = c;
    }
    
    int get(int key) {
        if (capcity == 0)
            return -1;
        if (!m.count(key)) {
            return -1;
        }

        list.erase(m[key]);
        m[key].cnt ++;
        m[key].tim = ++time;
        list.insert(m[key]);

        return m[key].val;
    }
    
    void put(int key, int value) {
        if (capcity == 0)
            return;
        if (!m.count(key)) {
            if (size >= capcity) {
                m.erase(list.begin()->key);
                list.erase(list.begin());
            }
            size++;
            Node tmp = Node(1, ++time, key, value);
            list.insert(tmp);
            m[key] = tmp;
        }
        else {
            list.erase(m[key]);
            m[key].cnt++;
            m[key].tim = ++time;
            m[key].val = value;
            list.insert(m[key]);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// 执行用时： 472 ms , 在所有 C++ 提交中击败了 50.53% 的用户
// 内存消耗： 178.2 MB , 在所有 C++ 提交中击败了 37.62% 的用户
