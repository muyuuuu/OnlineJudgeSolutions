class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        double res = INT_MAX;
        int len = quality.size(), p = 0;
        vector<pair<double,int> > m(len);
        // 单价，单份质量需要的钱
        for(int i = 0; i < len; ++i){
            m[i] = {(double)wage[i] / quality[i], quality[i]};
        }
        // 单价升序
        sort(m.begin(), m.end());
        priority_queue<int> que;

        // 按照单价升序，压入质量
        for(auto& x : m){
            if(que.size() < K){ 
                que.push(x.second);
                p += x.second;
            }
            
            // 如果队列满了，就用后面的单价乘以数量，获取价格
            // 如果用前面的，不能保证满足给后面的人开出高于期望的工资
            if(que.size() == K){
                res = min(res, x.first * p);
                p -= que.top();
                que.pop();
            }
        }
        return res;
    }
};
