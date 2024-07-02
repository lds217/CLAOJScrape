#include <bits/stdc++.h>

using namespace std;

bool tonghet(string a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
        sum += a[i] - '0';
    if (sum % 3 == 0)
        return 1;
    else
        return 0;
}

int main(int argc, char **argv)
{
    int T;
    cin >> T;
    while (T--)
    {
        string a;
        int k;
        cin >> a >> k;
        if (k == 1)
            cout << "YES" << endl;
        else if (k == 2)
        {
            if ((a[a.size() - 1] - '0') % 2 == 0)
                cout << "YES" << endl;
            else
                    cout << "NO" << endl;
        }
        else if (k == 3)
        {
            if ((a[a.size() - 1] - '0') % 2 == 0 && tonghet(a))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}
