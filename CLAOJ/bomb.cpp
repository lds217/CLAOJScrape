#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[2000][2000];
vector<int> slicks;
string a[2000];
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};

void bfs(int sx, int sy)
{
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int u = x + moveX[i];
            int v = y + moveY[i];
            if (u >= n || u < 0 ||v >= m || v < 0)
                continue;
            if (a[u][v]=='1' && !visited[u][v])
            {
                visited[u][v] = true;
                q.push(make_pair(u, v));
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
        int res=0;
    for (int i = 0; i <n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j]=='1' && !visited[i][j])
            {
               bfs(i, j);
                res++;
            }
    cout<<res;
}
