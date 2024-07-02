#include <iostream>
#include <cmath>
using namespace std;

int a[1000][1000] = {0},dp[1000][1000] = {0},maxsq=1;
bool final=0;
    int m, n;

void table()
{
    int z=0;
    for (int x = 2; x <= m; x++)
        for(int y=1; y <= n; y++)
        {
            while(dp[x][y]-dp[x][y-maxsq]-dp[x-maxsq][y]+dp[x-maxsq][y-maxsq]==(maxsq*maxsq))
                maxsq++;
        }
}

int main()
{

    cin >> m >> n;
    for (int x = 1; x <= m; x++)
        for(int y=1; y <= n; y++)
        {
            cin>>a[x][y];
            dp[x][y]=a[x][y]+ dp[x-1][y]+dp[x][y-1]-dp[x-1][y-1];
        }
    table();
    cout<<maxsq-1<<endl;
     
}
