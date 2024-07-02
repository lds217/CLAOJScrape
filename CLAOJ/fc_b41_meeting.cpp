#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
    int N;
    cin >> N;
    vector<pair<long long, long long>> K;
    map<pair<long long, long long>, long long> pos;
    long long sum = 0;
    for (int x = 0; x < N; x++)
    {
        long long a, b;
        cin >> a >> b;
        K.push_back(pair<long long, long long>(a, b));
        pos[{a, b}] = x + 1;
        sum += b;
    }
    sort(K.begin(), K.end());
    sum/=2;
    for (int x = 0; x < N; x++)
    {
        if (sum < K[x].second)
        {
            cout << pos[K[x]];
            break;
        }
        sum = sum - K[x].second;
    }
}
