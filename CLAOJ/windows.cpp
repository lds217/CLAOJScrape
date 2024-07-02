#include <bits/stdc++.h>
using namespace std;

struct xy
{
	long long a, b, c, d;	
};

xy A[1001];
long long n;
bool visited[1001];
void input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i].a >> A[i].b >> A[i].c >> A[i].d;
	}
	memset(visited,0,sizeof(visited));
}

long long res = 1;
void collapse(long long a, long long b, long long c, long long d, long long i)
{
	for (int j = 1; j < i; j++)
	{
		long long x = A[j].c;
		long long y = A[j].b;
		
		if (visited[j])
		if (a <= x && b <= y && c >= x && d >= y)
		{
			visited[i] = true;
			res++;
			return;
		}
	}
}

void solve()
{
	visited[1] = true;
	for (int i = 2; i <= n; i++)
	{
		collapse(A[i].a, A[i].b, A[i].c, A[i].d, i);
	}
}

int main()
{
	input();
	solve();
	cout << res << "\n";
	for (int i = n; i >= 0; i--) if (visited[i]) cout << i << ' ';
		
	
	return 0;
}
