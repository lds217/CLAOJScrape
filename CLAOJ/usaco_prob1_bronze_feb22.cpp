#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, a[100001] = {0}, sum = 0, res = 1e9;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], sum += a[i];

        for (int i = n; i >= 1; i--)
        {

            if (sum % i == 0)
            {
                bool possible = true;
                int val = sum / i;
                int csum = 0;

                for (int j = 1; j <= n; j++)
                {
                    csum += a[j];
                    if (csum > val)
                    {
                        possible = false;
                        break;
                    }
                    else if (val == csum)
                        csum = 0;
                    else
                        continue;
                }

                if (possible)
                    res = min(res, n - i);
            }
        }
        cout << res << endl;
    }
}
