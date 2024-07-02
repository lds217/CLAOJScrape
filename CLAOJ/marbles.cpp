#include <iostream>
#include <cmath>
using namespace std;

long long dp[2005][2005] = {0};

int main()
{
    long long N, M, D;
    cin >> N >> M >> D;
    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= M; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                if (abs(i - j) <= D)
                {
                   if (i == 0)
                    dp[i][j] = dp[i][j - 1]%(1000000000+7);
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j]%(1000000000+7) ;
                else
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%(1000000000+7);

                }

                else
                    dp[i][j] = 0;
            }
        }
    
    cout << dp[N][M];
}
