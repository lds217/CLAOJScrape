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

string X;
void input()
{
	cin >> X;
}

void solve()
{
	ll mu = 0, Y = 0;
	for (int i = X.size()-1; i >= 0; i--)
	{
		Y += (X[i]-'0')*pow(2, mu++);
	}
	
	cout << stoll(X)+Y;
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
