#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;

const ll N = 1e6+10;
const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll base = 31;

ll n, A[1000001];
void input()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
}

ll res;
void solve()
{
	sort(A, A+n);
	for (int i = ceil(n/2.0); i < n; i++)
	{
		res += A[i];
	}
	cout << res;
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
