#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string a;
    cin >> a; int sum8 = 0;
    for (int i = 0; i <N; i++)
    {
        cin >> a[i];
        if (a[i] == '8')
            sum8++;
    }
    bool y=0;
    int cnt=0;
    while (N > 11)
    {
        sum8--;
        cnt++;
        N -= 2;
    }
    //cout<<cnt;
    int check=0;
    for(int x=0;x<cnt*2;x++)
    {
        if(a[x]== '8')
            check++;
        if(check==cnt)
        {
           // if(x<)
           y=1;
           break;
        }

    }
    if (sum8 > 0&&y==1)
        cout << "YES";
    else
        cout << "NO";
}
