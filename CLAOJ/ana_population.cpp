#include <bits/stdc++.h>
using namespace std;

int main()
{


ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    long long n;
    long double a[200005];
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n-1;i++)
        printf("%.7Lf\n",(a[i+1]-a[1])/i);
}
