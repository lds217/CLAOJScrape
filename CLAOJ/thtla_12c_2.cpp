#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    long long a[2000001] = {0};
    ifstream f;
    f.open("BAI2.INP");
    f >> N;
    for (int x = 0; x < N; x++)
        f>>a[x];
    f.close();
    sort(a,a+N);
    ofstream f1;
    f1.open("BAI2.OUT");
    for(int x = 0; x < N; x++)
        if(a[x]!=a[x-1]&&a[x]!=a[x+1])
        {
            f1<<a[x];
            return 0;
        }
}
