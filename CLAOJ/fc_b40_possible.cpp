#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int K;
    cin >> K;
    long long a, b;
    while (K--)
    {
        cin >> a >> b;
        b=abs(b);
        long long c=a*(a+1)/2;
        if(c%2==b%2&&c>=b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
