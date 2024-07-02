#include <bits/stdc++.h>
    using namespace std;
    const int maxn = 1005;
    
    #define int long long
    
    int n, m, a[maxn][maxn], f[maxn][maxn];
    set <pair<int, int>> s;

    int32_t main()
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
        for (int i = 1; i <= m; i++) {f[1][i] = a[1][i]; s.insert({a[1][i], i});}
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                pair<int, int> tmp = *s.rbegin();
                if (tmp.second == j) {
                    s.erase(tmp);
                    pair<int, int> tmp2 = *s.rbegin();
                    f[i][j] = tmp2.first + a[i][j];
                    s.insert(tmp);
                }
                else {
                    f[i][j] = tmp.first + a[i][j];
                }
            }
            s.clear();
            for (int j = 1; j <= m; j++) s.insert({f[i][j], j});
        }
        cout << (*s.rbegin()).first;
        return 0;
    }
