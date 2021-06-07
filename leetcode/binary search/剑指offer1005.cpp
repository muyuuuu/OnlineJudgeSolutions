class Solution {
public:
    int findString(vector<string>& words, string s) {
        int l{0}, mid, r = words.size() - 1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            while (mid <= r && words[mid] == "") {
                mid += 1;
            }
            if (mid >= r) {
                r -= 1;
                continue;
            }
            else {
                if (words[mid] == s)
                    return mid;
                else if (words[mid] < s)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        
        if (l < words.size() && words[l] == s)
            return l;
        return -1;
    }
};

// 执行用时：12 ms, 在所有 C++ 提交中击败了52.08%的用户
// 内存消耗：11.3 MB, 在所有 C++ 提交中击败了11.50%的用户