#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;

const ll N = 1e6+10;
const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll base = 31;

int n,m,x,y,A[1001][1001];
void input()
{
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> A[i][j];
		}
	}
}

int dem, curr_id, dock, cnt[1001][1001], ids[1001][1001], cx[4] = {0,0,1,-1}, cy[4] = {1,-1,0,0};
bool visited[1001][1001];

void bfs_1(int sx, int sy)
{
	queue <ii> q;
	q.push({sx, sy});
	visited[sx][sy] = true;
	ids[sx][sy] = curr_id;
	dem = 0;
	//memset(cnt, 0x3f, sizeof(cnt));
	
	while(!q.empty())
	{
		int curr_x = q.front().fi, curr_y = q.front().se;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int change_x = curr_x + cx[i], change_y = curr_y + cy[i];
			if (change_x >= 1 && change_x <= n && change_y >= 1 && change_y <= m && A[change_x][change_y] == 1 && visited[change_x][change_y] == false)
			{
				visited[change_x][change_y] = true;
				ids[change_x][change_y] = curr_id;
				dem++;
				q.push({change_x, change_y});
			}
		}
	}
	
	return;
}

void bfs_2(int sx, int sy)
{
	queue <ii> q;
	q.push({sx, sy});
	memset(cnt, 0x3f, sizeof(cnt));
	cnt[sx][sy] = 0;
	
	while(!q.empty())
	{
		int curr_x = q.front().fi, curr_y = q.front().se;
		q.pop();
		
		if (ids[curr_x][curr_y] == dock) 
		{
			cout << cnt[curr_x][curr_y];
			return;
		}
		
		for (int i = 0; i < 4; i++)
		{
			int change_x = curr_x + cx[i], change_y = curr_y + cy[i];
			if (change_x >= 1 && change_x <= n && change_y >= 1 && change_y <= m)
			{
				if (cnt[change_x][change_y] > cnt[curr_x][curr_y] + 1)
				{
					cnt[change_x][change_y] = cnt[curr_x][curr_y] + 1;
					q.push({change_x, change_y});
				}
			}
		}
	}
	
	return;
}

void solve()
{
	curr_id = 1;
	int Max_dem = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (visited[i][j] == false && A[i][j] == 1)
			{
				bfs_1(i,j);
				
				if (dem > Max_dem)
				{
					Max_dem = dem;
					dock = curr_id;	
				}
				curr_id++;
			}
		}
	}
	
	bfs_2(x,y);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("chiahet.INP","r",stdin);
	//freopen("chiahet.OUT","w",stdout);
	int t = 1; //cin >> t;
	while (t--)
	{
		input(), solve();
	}
}
