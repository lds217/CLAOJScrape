#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long a[n];
    for(int x=0;x<n;x++)
        cin>>a[x];
    sort(a,a+n);
    cout<<a[n-1]-a[0];
}
