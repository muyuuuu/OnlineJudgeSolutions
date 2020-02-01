#include <cstdio>
#include <queue>

using namespace std;

struct node {
    int x, y, z;
};

int m, n, l, t;

// 用于判断方向
int X[6] = {1, 0, 0, -1, 0, 0};  // M方向， -1表示回退方向
int Y[6] = {0, 1, 0, 0, -1, 0};  // N方向
int Z[6] = {0, 0, 1, 0, 0, -1};  // L方向

int arr[1300][130][80];

bool visit[1300][130][80];

bool judge(int x, int y, int z) {
    // 超出边界， 搜索停止
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) 
        return false;
    // 无风险不访问，已经访问过不访问
    if(arr[x][y][z] == 0 || visit[x][y][z] == true) 
        return false;
    // 其余情况均访问
    return true;
}

int bfs(int x, int y, int z) {
    int cnt = 0;
    node temp;
    // 当前点的位置
    temp.x = x, temp.y = y, temp.z = z;
    // 创建三维点的队列
    queue<node> q;
    q.push(temp);
    // 当前点被访问
    visit[x][y][z] = true;
    while(!q.empty()) {
        // 取出队首元素
        node top = q.front();
        // 弹出队首元素
        q.pop();
        // 有一个1, 体积++
        cnt++;
        // 六个方向开始寻找
        for(int i = 0; i < 6; i++) {
            int tx = top.x + X[i];
            int ty = top.y + Y[i];
            int tz = top.z + Z[i];
            if(judge(tx, ty, tz)) {
                visit[tx][ty][tz] = true;
                temp.x = tx, temp.y = ty, temp.z = tz;
                // 压入队列，只要压入队列在下次循环时 cnt++ 用于计算体积
                q.push(temp);
            }
        }
    }
    if(cnt >= t)
        return cnt;
    else
        return 0;
}

int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for(int i = 0; i < l; i++)
        for(int j = 0; j < m; j++)
            for(int k = 0; k < n; k++)
                // M x N L个，这样的维度
                scanf("%d", &arr[j][k][i]);
    int ans = 0;
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < n; k++) {
                if(arr[j][k][i] == 1 && visit[j][k][i] == false)
                    ans += bfs(j, k, i);
            }
        }
    }
    printf("%d", ans);
    return 0;
}