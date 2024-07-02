#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O2")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define task "long"
#define pb emplace_back
#define ll long long
#define ull unsigned long long
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define MASK(i) ((1LL)<<(i))
#define GETBIT(x,i) (((x)>>(i))&1)
#define TURNOFF(x,i) ((x)&(~(1<<i)))
#define CNTBIT(x) __builtin_popcount(x)
#define LOG 20
#define MASK(i) ((1LL)<<(i))
#define EL cout << "\n"
#define FU(i, a, b) for(int i=a; i<=b; ++i)
#define FD(i, a, b) for(int i=a; i>=b; --i)
#define REP(i, x) for(int i=0; i<x; i++)
const int MAX = 1e3 + 1, N = 1e6 + 1;
const int mod = 1e9 + 7;
const int base = 31;
const int INF = 1e9 + 7;
typedef pair<int, int> ii;
void init()
{
    if (fopen(task".inp","r"))
    {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
}
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
template<class X, class Y> bool maximize(X &x, Y y){ if (x < y) {x = y; return true;} return false;};
int n, m, c, cnt = 0;
int a[MAX][MAX], comp[MAX][MAX], node[N], color1[N], color2[N];
vector<int> adj[N];
void read()
{
   cin >> n >> m >> c;
   FU(i, 1, n) FU(j, 1, m) cin >> a[i][j];
}
ii q[N];
void bfs(int i, int j)
{
   int l = 1, r = 1;
   q[1] = ii(i, j);
   comp[i][j] = cnt;
   while(l <= r)
   {
      int x = q[l].fi, y = q[l].se;
      ++l;
      REP(dir, 4)
      {
         int newX = x + dx[dir];
         int newY = y + dy[dir];
         if (newX < 1 || newY < 1 || newX > n || newY > m || comp[newX][newY] > 0) continue;
         if (a[newX][newY] == a[i][j])
         {
            comp[newX][newY] = cnt;
            q[++r] = {newX, newY};
         }
      }
   }
}
int dfs2(int s)
{
   FU(i, 1, cnt) color2[i] = 0;
   int sz = 0, mx = 0;
   node[++sz] = s;
   while(sz > 0)
   {
      int mask = 0;
      int u = node[sz]; --sz;
      for(int v: adj[u]) if (color2[v]) mask |= MASK(color2[v]-1);
      FU(i, 1, 5) if (!GETBIT(mask, i-1))
      {
         mx = max(mx, i);
         color2[u] = i;
         break;
      }
      for(int v: adj[u]) if (!color2[v]) node[++sz] = v;
   }
   return mx;
}

int dfs1(int s)
{
   //FU(i, 1, cnt) color1[i] = 0;
   int sz = 0, mx = 0;
   node[++sz] = s;
   while(sz > 0)
   {
      int mask = 0;
      int u = node[sz]; --sz;
      if (color1[u]) continue;
      for(int v: adj[u]) if (color1[v]) mask |= MASK(color1[v]-1);
      FU(i, 1, 5) if (!GETBIT(mask, i-1))
      {
         mx = max(mx, i);
         color1[u] = i;
         break;
      }
      //for(int v: adj[u]) if (!color2[v]) node[++sz] = v;
      FD(i, (int)adj[u].size() - 1, 0) if (!color1[adj[u][i]]) node[++sz] = adj[u][i];
   }
   return mx;
}
void sol()
{
   FU(i, 1, n) FU(j, 1, m) if (!comp[i][j])
   {
      ++cnt;
      bfs(i, j);
   }
   FU(i, 1, n) FU(j, 1, m)
   {
      REP(dir, 4)
      {
         int x = i + dx[dir];
         int y = j + dy[dir];
         if (x < 1 || y < 1 || x > n || y > m || comp[i][j] == comp[x][y]) continue;
         adj[comp[i][j]].pb(comp[x][y]);
      }
   }
   ii res = {-1, -1};
   FU(i, 1, cnt)
   {
      sort(ALL(adj[i]));
      adj[i].resize(unique(ALL(adj[i]))-adj[i].begin());
      maximize(res, ii((int)adj[i].size(), i));
   }
   int mx1 = dfs1(res.se);
   int mx2 = dfs2(res.se);
   cout << min(mx1, mx2), EL;
   if (mx1 < mx2)
   {
      FU(i, 1, n)
      {
         FU(j, 1, m) cout << color1[comp[i][j]] << " ";
         EL;
      }
   }
   else
   {
      FU(i, 1, n)
      {
         FU(j, 1, m) cout << color2[comp[i][j]] << " ";
         EL;
      }
   }
}
signed main()
{
    fastio();
    init();
    int T = 1;
    //cin >> T;
    while(T--)
    {
        read();
        sol();
    }
}
