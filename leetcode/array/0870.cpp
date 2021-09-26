class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int> tmp;
        unordered_map<int, vector<int>> m;
        int cnt{0};
        tmp.assign(nums2.begin(), nums2.end());

        sort(nums1.begin(), nums1.end(), greater<>());
        sort(tmp.begin(), tmp.end(), greater<>());

        for (int i = 0; i < tmp.size(); i++) {
            // cout << tmp[i] << endl;
            if (nums1[cnt] > tmp[i]) {
                m[tmp[i]].push_back(nums1[cnt]);
                // cout << nums1[cnt] << endl;
                cnt++;
            }
            else {
                m[tmp[i]].push_back(nums1.back());
                // cout << nums1.back() << endl;
                nums1.pop_back();
            }
        }

        for (auto& i : nums2) {
            if (!m[i].empty()) {
                res.push_back(m[i].back());
                m[i].pop_back();
            }
        }

        return res;
    }
};

// 执行用时： 304 ms , 在所有 C++ 提交中击败了 7.43% 的用户
// 内存消耗： 87.4 MB , 在所有 C++ 提交中击败了 5.08% 的用户
