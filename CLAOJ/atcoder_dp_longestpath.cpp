#include <bits/stdc++.h>
using namespace std;
int m, n;
int value[200000]={0};
vector<int> k[200000];
int res = -1;

void dfs(int u)
{
    value[u] = 1;
    for (auto v : k[u])
    {
        if (value[v] == 0)
            dfs(v);
        value[u] = max(value[v] + 1, value[u]);
    }
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        k[u].push_back(v);
    }
    for (int x = 0; x <= n; x++)
    {
        if (value[x] == 0)
        {
            dfs(x);
            res = max(res, value[x]);
        }
    }
    cout << res-1;
}
