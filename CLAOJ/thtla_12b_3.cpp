#include <bits/stdc++.h>
using namespace std;

long long m,cnt;

int main()
{
    freopen("CHANGE.INP","r",stdin);
    freopen("CHANGE.OUT","w",stdout);
    cin >> m;
    if(m%5!=0||m==0)
    {
        cout <<"-1";
        return 0;
    }
    cout << m/50+(m%50)/20+((m%50)%20)/10+(((m%50)%20)%10)/5;
}
