#include <iostream>
#include <queue>
#include <cstring>
#include <stdio.h>
using namespace std;

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

int m, n, T, a[101][101], value[101][101], sx, sy, bomb, visit[101][101];

void bfs(int sx, int sy)
{
    queue<pair<int, int> > q;
    q.push(pair<int, int>(1, 1));
    value[1][1] = a[1][1];
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if (u > m || u <= 0 || v > n || v <= 0)
                continue;
            if (value[u][v] > value[x][y] + a[u][v])
            {
                value[u][v] = value[x][y] + a[u][v];
                q.push(pair<int, int>(u, v));
            }
        }
    }
}

int main(int argc, char **argv)
{
    freopen("GIAICUU.INP","r",stdin);
    freopen("GIAICUU.OUT","w",stdout);
    cin >> T;
    while (T--)
    {
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j], value[i][j] = 1e9, visit[i][j] = 0;
        cin >> sx >> sy >> bomb;
        bfs(sx, sy);
        // for(int i=1; i <= m; i++)
        // {
        //     for(int j=1; j<= n;j++)
        //         cout<<value[i][j]<<" ";
        //     cout<<endl;
        // }
        if (bomb - value[sx][sy] < 0)
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;
            cout << bomb - value[sx][sy] << endl;
        }
    }
}
