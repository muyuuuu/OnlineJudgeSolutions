class Solution {
private:
    int b_size;
    vector<int> res;
    unordered_map<int, int> vtoi;
public:

    void deleteItem(int val) {

        int idx1 = vtoi[res[res.size() - 1]];
        int idx2 = vtoi[val];
        int tmp;

        tmp = res[idx1];

        res[idx1] = res[idx2];
        res[idx2] = tmp;
        vtoi[tmp] = idx2;

        res.pop_back();
        vtoi.erase(val);

    }

    Solution(int n, vector<int>& blacklist) {
        b_size = blacklist.size();
        for (int i = 0; i < n; i++) {
            res.push_back(i);
            vtoi[i] = i;
        }
        for (auto& i : blacklist) {
            deleteItem(i);
        }
    }
    
    int pick() {
        return res[rand() % res.size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
