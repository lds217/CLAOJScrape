#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
long long poww(unsigned long long x, unsigned long long n) {
    unsigned long long res = 1;
    unsigned long long temp = x;
    while (n > 0) {
        if (n & 1) res = res * temp % M;
        n >>= 1;
        temp = temp * temp % M;
    }
    return res;
}

long long mul(unsigned long long x, unsigned long long n) {
    unsigned long long res = 0;
    unsigned long long temp = x;
    while (n > 0) {
        if (n & 1) res =( res + temp) % M;
        n >>= 1;
        temp = (temp + temp) % M;
    }
    return res;
}

int main()
{
    unsigned long long n;
    cin>>n;
     unsigned long long k=(poww(2,n)+1)%M;
     cout<<(k*(k+1)/2)%M;
}
