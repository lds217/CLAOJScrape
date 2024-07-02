#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("COST.INP", "r", stdin);
    freopen("COST.OUT", "w", stdout);

    int n, a, b;

    cin >> n >> a >> b;

    int box[10000000];

    for (int i = 0; i < n; i++)
    {
        cin >> box[i];
    }

    int tong = 0;

    for (int i = 0; i < n; i++)
    {
        if (box[i] == 2)
            tong += (a + b);

        if (box[i] == 1)
            tong += min(a, b);
    }

    cout << tong;
}
