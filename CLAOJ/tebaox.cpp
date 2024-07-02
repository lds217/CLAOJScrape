#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
int poww(unsigned long long x, unsigned long long n) {
    unsigned long long res = 1;
    unsigned long long temp = x;
    while (n > 0) {
        if (n & 1) res = res * temp % M;
        n >>= 1;
        temp = temp * temp % M;
    }
    return res;
}

int main()
{
    unsigned long long n;
    cin>>n;
    cout<<(poww(2,n+1)-1)%M;
}
