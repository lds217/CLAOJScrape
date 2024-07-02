#include <bits/stdc++.h>
using namespace std;

bool better(int A[], int B[])
{
    int wA = 0, wB = 0;
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
        {
            if (A[x] > B[y])
                wA++;
            else if (A[x] < B[y])
                wB++;
        }
    //      cout<<wA<<" "<<wB<<endl;
    return wA > wB;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        bool y = 0;

        int diceA[4], diceB[4], diceC[4];
        for (int x = 0; x < 4; x++)
            cin >> diceA[x];
        for (int x = 0; x < 4; x++)
            cin >> diceB[x];
        for (int C1 = 1; C1 <= 10; C1++)
            if (y == 0)
                for (int C2 = 1; C2 <= 10; C2++)
                    if (y == 0)
                        for (int C3 = 1; C3 <= 10; C3++)
                            if (y == 0)
                                for (int C4 = 1; C4 <= 10; C4++)
                                {
                                    diceC[0] = C1, diceC[1] = C2, diceC[2] = C3, diceC[3] = C4;
                                        if( (better(diceB, diceC) && better(diceC, diceA)&& better(diceA, diceB))||( better(diceB, diceA)&&better(diceA,diceC)&&better(diceC,diceB) ) )
                                        {
                                        // cout<<diceC[0]<<diceC[1]<<diceC[2]<<diceC[3]<<endl;
                                        cout << "yes" << endl;
                                        y = 1;
                                        break;
                                        }
                                }
        if (y == 0)
            cout << "no" << endl;
    }
}
