#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <fstream>
using namespace std;

int a[30000][1000] = {0};

int main()
{
    
    ifstream f;
    f.open("WIFI.INP");
    int M, N, K, x, y, R, B, maxx = 0;
    f >> M >> N >> K;
    while (K--)
    {
        f >> x >> y >> R >> B;
        swap(x, y);
        x = M - x + 1;
        for (int i = x + 1; i <= x + R; i++)
        {
            for (int j = y + 1; j <= y + R; j++)
            {
                if ((ceil)(sqrt(pow(i - x, 2) + pow(j - y, 2))) <= R)
                {
                    if (x - (i - x) > 0 && x - (i - x) <= M)
                    {
                        a[x - (i - x)][j] += B;
                        maxx=max(maxx, a[x - (i - x)][j]);
                    }
                    if (i > 0 && i <= M && j > 0 && j <= N)
                    {
                        a[i][j] += B;
                        maxx=max(maxx,a[i][j]);
                    }
                    if (y - (j - y) > 0 && y - (j - y) <= N)
                    {
                        a[i][y - (j - y)] += B;
                        maxx=max(maxx,a[i][y - (j - y)]);
                    }
                    if (x - (i - x) > 0 && x - (i - x) <= M && y - (j - y) > 0 && y - (j - y) <= N)
                    {
                        a[x - (i - x)][y - (j - y)] += B;
                        maxx=max(maxx, a[x - (i - x)][y - (j - y)]);
                    }
                }
            }
        }
        for (int i = x - R; i <= x + R; i++)
            if (i > 0 && i <= M)
            {
                a[i][y] += B;
                maxx=max(maxx,a[i][y]);
            }
        for (int j = y - R; j <= y + R; j++)
            if (j > 0 && j <= N&&j!=y)
            {
                a[x][j] += B;
                maxx=max(maxx,a[x][j]);
            }
    }
    f.close();
    int cnt=0;
    for(int x=1;x<=M;x++)
        for(int y=1;y<=N;y++)
            if(a[x][y]==maxx)
                cnt++;
    ofstream f1;
    f1.open("WIFI.OUT");
    f1<<maxx<<endl;
    f1<<cnt;
}
