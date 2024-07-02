#include <bits/stdc++.h>
using namespace std;

int N, A, B, h[100000], p[100000],sorted[100000];
bool taken[100000];

int main()
{
    cin >> N >> A >> B;
    for (int x = 0; x < N; x++)
        cin >> h[x],sorted[x]=h[x];
    for (int x = 0; x < N; x++)
        cin >> p[x];
    sort(sorted,sorted+N);
    int res = 0;
    for (int x = 0; x < N; x++)
    {
        if (taken[h[x]] == 0)
        {
            int remain = 0;
            for (int i = 0; i < N; i++)
            {
                if(taken[sorted[i]] == 0)
                {
                    if(remain==p[x]&&h[x]<sorted[i])
                    {
                        res+=B;
                        taken[sorted[i]]=1;
                        taken[h[x]]=1;
                        break;
                    }
                    remain++;
                }
                if(i==N-1)
                {
                        taken[h[x]]=1;
                        res+=A;
                }
            }
        }
    }
    cout << res;
}
