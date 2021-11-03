class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        vector<int> tmp(n1 + n2, 0);
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int p1 = i + j;
                int p2 = i + j + 1;
                int t = (num1[i] - '0') * (num2[j] - '0') + tmp[p2];
                tmp[p2] = t % 10;
                tmp[p1] += (t / 10);
            }
        }

        int s = 0;
        // cout << tmp[0] << endl;
        while (s < tmp.size() && tmp[s] == 0)
            s++;
        string res{""};
        for (int i = s; i < tmp.size(); i++) {
            res += (tmp[i] + '0');
        }
        if (res.size() == 0)
            return "0";
        return res;
    }
};

// 执行用时： 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户
// 内存消耗： 6.6 MB , 在所有 C++ 提交中击败了 77.09% 的用户
