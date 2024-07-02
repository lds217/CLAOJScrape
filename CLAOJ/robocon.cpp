#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

int a[1001][1001];
int m, n, l, k;
int value[1001][1001], visited[1001][1001];

void bfs(int sx, int sy)
{
    sx--;sy--;
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    value[sx][sy] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if (u >= n || u < 0 || v >= m || v < 0)
                continue;
            if (value[u][v]>abs(a[x][y]-a[u][v])*2+1+value[x][y])
            {
                value[u][v]=abs(a[x][y]-a[u][v])*2+1+value[x][y];
                q.push(make_pair(u, v));
            }
        }
    }
}


int main()
{
    cin >> n >> m;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < m; y++)
        {
            cin >> a[x][y], value[x][y] = 1e9;
        }
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    bfs(sx, sy);
      cout<<value[--fx][--fy];
}
