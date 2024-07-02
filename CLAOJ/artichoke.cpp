#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    double p, a, b, c, d, n;
    cin >> p >> a >> b >> c >> d >> n;
    double stock1 = 0, res = 0;
    for (int k = 1; k <= n; k++)
    {
        double stock = p * (sin(a * k + b) + cos(c * k + d) + 2);
        if (stock > stock1)
            stock1 = stock;
        else
            res=max(stock1-stock,res);
    }
    cout<<setprecision(10)<<res;
}
