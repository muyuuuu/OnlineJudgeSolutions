class TimeMap {
public:
    unordered_map<string, map<int, string> > m;
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (m.count(key) == 0)
            return "";
        auto& t = m[key];
        auto it = t.upper_bound(timestamp);
        if (it == t.begin())
            return "";
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

// 执行用时：416 ms, 在所有 C++ 提交中击败了75.25%的用户
// 内存消耗：133 MB, 在所有 C++ 提交中击败了61.39%的用户