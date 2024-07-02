#include <iostream>
using namespace std;

long long n, a[100005], dp[100005];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0]=0;
    for (int i = 0; i <= n; i += 2)
    {
        dp[i + 2] = max(dp[i + 2], dp[i] + a[i + 1]);
        dp[i + 4] = max(dp[i + 4], dp[i] + a[i + 1] + a[i + 2]);
        dp[i + 6] = max(dp[i + 6], dp[i] + a[i + 1] + a[i + 2] + a[i + 3]);
    }
    long long maxx = -1;
    for (int i = 0;i<=n+6;i++)
        maxx=max(maxx,dp[i]);
    cout<<maxx;
}
