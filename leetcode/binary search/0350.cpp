class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        vector<int> res;
        
        for (auto& i : nums1) {
            m[i]++;
        }
        
        for (auto& i : nums2) {
            if (m[i] > 0) {
                res.push_back(i);
                m[i]--;
                if (m[i] == 0)
                    m.erase(i);
            } 
        }
        return res;
    }
};

// 执行用时：12 ms, 在所有 C++ 提交中击败了18.41%的用户
// 内存消耗：10.4 MB, 在所有 C++ 提交中击败了16.68%的用户

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int n1 = nums1.size(), n2 = nums2.size(), idx1{0}, idx2{0}, a, b;
        
        while (idx1 < n1 && idx2 < n2) {
            a = nums1[idx1];
            b = nums2[idx2];
            
            if (a < b)
                idx1++;
            else if (a > b)
                idx2++;
            else {
                res.push_back(a);
                idx1++;
                idx2++;
            }
        }
        return res;
    }
};

// 执行用时：0 ms, 在所有 C++ 提交中击败了100.00%的用户
// 内存消耗：9.8 MB, 在所有 C++ 提交中击败了68.64%的用户