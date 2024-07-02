#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{
    string str[4], guess[4];
    cin >> str[0] >> str[1] >> str[2];
    cin >> guess[0] >> guess[1] >> guess[2];
    string temp1,temp2;
    int resy = 0, resg = 0;
    bool pass = 0;
    for (int x = 0; x < 3; x++)
        for (int y = 0; y <str[x].size(); y++)
                    if(str[x][y]==guess[x][y])
                        resg++;
                    else
                        temp1+=str[x][y],temp2+=guess[x][y];
                   
    for(int x=0;x<temp1.size();x++)
        for(int y=0;y<temp2.size();y++)
        {   
            if(temp1[x]==temp2[y])
            {
                resy++;
                temp2.erase(y,1);
                break;
            }
        }
    cout << resg << endl;
    cout << resy;
}
