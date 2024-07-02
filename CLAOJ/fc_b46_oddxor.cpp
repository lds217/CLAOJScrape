#include <bits/stdc++.h>
using namespace std;
 

long long findXOR(long long n)
{
    switch (n & 3) {

    case 0:
        return n;
    case 1:
        return 1;
    case 2:
        return n + 1;
    case 3:
        return 0;
    }
}

long long findOddXOR(long long n)
{

    if (n % 2 == 0)
        return((findXOR(n))^ (2 * findXOR(n / 2)));
    else
       return ((findXOR(n)) ^ (2 * findXOR((n - 1) / 2)));
}

int main()
{
    long long l,r;
    cin>>l>>r;
    cout<<(findOddXOR(r) ^ findOddXOR(l-1));

    return 0;
}
