#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int n;
int a[500][500];
int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};
set<int> value;
int intvalue[250000], cntv = 0;
bool visited[500][500];

void reset()
{
    memset(visited, false, sizeof(visited));
}

void settoarray()
{
    for (auto it = value.begin(); it != value.end(); it++)
        intvalue[cntv++] = *it;
}

int bfs(int sx, int sy, int d)
{
    int points = 1;
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
            if (u >= n || u < 0 || v >= n || v < 0)
                continue;
            if (abs(a[u][v] - a[x][y]) <= d && !visited[u][v])
            {
                visited[u][v] = true;
                q.push(make_pair(u, v));
                points++;
            }
        }
    }
    return points;
}

int process(int d)
{
    reset();
    int k = 0;
    int maxx = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j])
            {
                int k = bfs(i, j, d);
                if (k >= ((n * n) + 1) / 2)
                    return k;
            }
    return k;
}

int main()
{
    ifstream f;
    f.open("ROBOT.INP");
    f >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            f >> a[i][j];
            value.insert(a[i][j]);
        }
    f.close();
    settoarray();
    int square = ((n * n) + 1) / 2;
    int low = 0;
    int high = intvalue[cntv - 1];
    int minn = 1e9;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (process(mid) < square)
            low = mid + 1;
        else if (process(mid) >= square)
        {
            high = mid - 1;
            minn = min(minn, mid);
        }
    }
    ofstream f1;
    f1.open("ROBOT.OUT");
    f1 << minn;
}
