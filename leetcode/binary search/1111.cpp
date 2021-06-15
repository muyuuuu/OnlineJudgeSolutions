class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int a{0};
        vector<int> res;
        for (auto& i : seq) {
            if (i == '(') {
                a++;
                res.push_back(a%2);
            }
            else{
                res.push_back(a%2);
                a--;
            }
        }
        return res;
    }
};

// 执行用时：4 ms, 在所有 C++ 提交中击败了73.31%的用户
// 内存消耗：7.3 MB, 在所有 C++ 提交中击败了58.57%的用户