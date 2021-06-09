class Solution {
private:
    struct node {
        int h;
        int w;
    };
public:
    static bool cmp(node& a, node& b) {
        if (a.h <= b.h)
            return a.w < b.w;
        else
            return false;
    }
    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        node tmp;
        int n = height.size(), res{0}, w{-1}, h{-1};
        vector<node> v;
        for (int i = 0; i < n; i++) {
            tmp.h = height[i];
            tmp.w = weight[i];
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), cmp);
        for (auto& i : v) {
            if (w < i.w && h < i.h){
                res++;
                w = i.w;
                h = i.h;
            }
        }
        
        return res;
    }
};