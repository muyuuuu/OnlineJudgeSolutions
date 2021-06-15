class Solution {
public:
    bool check(int mid, vector<int>& position, int m) {
        // 细节 3：cnt 初始值为 1，是因为先在开始位置放了一个球
        int cnt{1};
        int pre = position[0];
        for (int i = 1; i < position.size(); i++) {
            // 如果后续位置减去当前位置的磁力大于需求，就放置
            if (position[i] - pre >= mid) {
                cnt ++;
                pre = position[i];
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        // 细节 1：最小磁力直接设置为 1，不然的话，就是排序数组两两之间的最小值
        int l = 1, n = position.size(), mid, res;
        // 细节 2：磁力的最大值是末尾减去开始
        int r = position[n-1] - position[0];
        while (l <= r) {
            mid = (l + r) / 2;
            if (check(mid, position, m)) {
                res = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return res;
    }
};

// 执行用时：220 ms, 在所有 C++ 提交中击败了63.41%的用户
// 内存消耗：56.6 MB, 在所有 C++ 提交中击败了16.10%的用户