#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <xstddef>
using namespace std;

class PrimSolution {
public:
    struct cmp {
        // pair 类型数据之间可以使用 <, >做比较，但优先比较 first, 如果 first 相同才会比较 second.
        // 以下是对括号 () 的操作符重载，用结构体模仿函数的行为，这是仿函数的标准做法。 
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            return a.second > b.second;  //小顶堆, 距离小的优先
        }
    };
    int minimumCost(int N, vector<vector<int>>& connections) {
        vector<bool> vis(N + 1, false);
        vector<vector<pair<int, int>>> edges(N + 1, vector<pair<int, int>>());
        for (auto& c : connections) {
            // edges[i] 是个vector,里面存了i点直接相连的点及其对应的边的权值。
            edges[c[0]].push_back({ c[1],c[2] });
            edges[c[1]].push_back({ c[0],c[2] });
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        int to, distance, total = 0, edge = 0;
        vis[1] = true;  // 第1点是起始点。
        for (auto& e : edges[1])
            q.push(e); // 把第 1 点的所有边加入优先队列；
        while (!q.empty()) {
            to = q.top().first; // to 是 连通分量a中的所有点的相关边里，权值最小的边的另一个顶点
            distance = q.top().second; // 权值最小的边的权值
            q.pop();  // 去掉刚刚处理的边
            if (!vis[to]) { // 如果刚刚处理的点（边）以前访问过，那么说明已经在这个连通分量 a 里面了，不需要再考虑
                vis[to] = true;
                total += distance;
                edge++;
                if (edge == N - 1)  // 放入连通分量 a 的 边的数量等于N-1，最小生成树就形成了。
                    return total;
                // 把刚刚处理的边的另一顶点（to）也加入了 连通分量a， 那么也要把 to  的相关 边 也加入连通分量的相连边这个队列中。          
                for (auto& e : edges[to])
                    q.push(e);
            }
        }
        return -1;  // 如果连通分量 a 的 边的数量无法等于N-1，说明是非连通图，没有生成树。
    }
};
class KruskalSolution
{
public:
    vector<int> parent;
    int find(int x)
    {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void Union(int x,int y)
    {
        int fx = find(x);
        int fy = find(y);
        if (fx != fy)
        {
            parent[fy] = fx;
        }
    }
    bool isconnected(int x,int y)
    {
        if (find(x) != find(y)) return false;
        else return true;
    }
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return a[2] < b[2];
    }
    int minimumCost(int N, vector<vector<int>>& connections) {
        for (int i = 0; i <= N; i++)
        {
            parent.push_back(i);
        }
        sort(connections.begin(), connections.end(), cmp);
        int nums = 0,total=0;
        for (int i = 0; i < connections.size(); i++)
        {
            int x = connections[i][0], y = connections[i][1],dis=connections[i][2];
            if (!isconnected(x, y))
            {
                nums++;
                total += dis;
                if (nums == N - 1)
                {
                    return total;
                }
                Union(x, y);
            }
        }
        return -1;
    }
};

int main()
{
    int N = 3;
    vector<vector<int>> connections = { {1, 2, 5},{1, 3, 6},{2, 3, 1 }};
    KruskalSolution test;//PrimSolution
    int ans=test.minimumCost(N, connections);
    cout << ans;


    //test for sort greater less
    vector<int> tmp{ 1,3,2,7,1 };
    sort(tmp.begin(), tmp.end(), less<int>());
    int index = 0;
    while (index < tmp.size())
    {
        cout << tmp[index++];
    }
    return 0;
}
