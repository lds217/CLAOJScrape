#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int moveX[4] = {0, 0, 1, -1};
int moveY[4] = {1, -1, 0, 0};
bool visit[1001][1001];
int mark[1001][1001];
string matrix[1001];
int n, m;

void build()
{
    for (int x = 0; x < m; x++)
        for (int y = 0; y < n; y++)
            mark[x][y] = 1e9;
    for (int x = 0; x < m; x++)
        for (int y = 0; y < n; y++)
            if (matrix[x][y] == 'C')
            {
                int u = 0, d = 0, l = 0, r = 0;
                while (matrix[x - u][y] != 'W' && x - u >= 0)
                {
                    if (matrix[x - u][y] == '.' || matrix[x - u][y] == 'S')
                        mark[x - u][y] = -1;
                    u++;
                }
                while (matrix[x + d][y] != 'W' && x + d < m)
                {
                    if (matrix[x + d][y] == '.' || matrix[x + d][y] == 'S')
                        mark[x + d][y] = -1;
                    d++;
                }
                while (matrix[x][y - l] != 'W' && y - l >= 0)
                {
                    if (matrix[x][y - l] == '.' || matrix[x][y - l] == 'S')
                        mark[x][y - l] = -1;
                    l++;
                }
                while (matrix[x][y + r] != 'W' && y + r < n)
                {
                    if (matrix[x][y + r] == '.' || matrix[x][y + r] == 'S')
                        mark[x][y + r] = -1;
                    r++;
                }
            }
}

void bfs(int sx, int sy)
{
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    visit[sx][sy] = 1;
    if (mark[sx][sy] != -1)
        mark[sx][sy] = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        //   cout<<mark[sx][sy]<<" ";
        q.pop();
        if (matrix[x][y] != 'W')
            if (mark[x][y] != -1)
                for (int i = 0; i < 4; i++)
                {
                    int u = x + moveX[i];
                    int v = y + moveY[i];
                    bool slide[1001][1001],check=0;
                    while (matrix[u][v] == 'U' || matrix[u][v] == 'D' || matrix[u][v] == 'R' || matrix[u][v] == 'L')
                    {
                        if(slide[u][v]==true)
                        {
                            check=1;
                            break;
                        }
                        slide[u][v]=true;
                        if (matrix[u][v] == 'U')
                        {
                            u--;
                            continue;
                        }
                        if (matrix[u][v] == 'D')
                        {
                            u++;
                            continue;
                        }
                        if (matrix[u][v] == 'R')
                        {
                            v++;
                            continue;
                        }
                        if (matrix[u][v] == 'L')
                        {
                            v--;
                            continue;
                        }
                    }
                    if (u >= m || u < 0 || v >= n || v < 0 || matrix[u][v] == 'W' || visit[u][v] == 1 || matrix[u][v] == 'C' || mark[u][v] == -1||check==1)
                        continue;
                    if (visit[u][v] == 0 && matrix[u][v] != 'W' && mark[u][v] > mark[x][y] + 1)
                    {
                        //      cout<<mark[u][v]<<" ";
                        visit[u][v] = true;
                        mark[u][v] = mark[x][y] + 1;
                        q.push(make_pair(u, v));
                    }
                }
        //   cout<<endl;
    }
}

int main(int argc, char **argv)
{
    cin >> m >> n;
    int sx = -1, sy = -1;
    for (int x = 0; x < m; x++)
    {
        cin >> matrix[x];
        if (sx == -1)
            for (int y = 0; y < n; y++)
                if (matrix[x][y] == 'S')
                    sx = x, sy = y;
    }
    // cout<<sx<<" "<<sy<<endl;
    //   cout<<mark[sx][sy]<<endl;
    build();
    bfs(sx, sy);
    //  cout<<mark[sx][sy]<<endl;
    for (int x = 0; x < m; x++)
    {
        for (int y = 0; y < n; y++)
            if (matrix[x][y] == '.' && mark[x][y] == 1e9)
                cout << -1 << endl;
            else if (matrix[x][y] == '.')
                cout << mark[x][y] << endl;
        //     else
        //         cout<<0<<' ';
        // cout<<endl;
    }
    // cout<<sx<<" "<<sy<<endl;
}
