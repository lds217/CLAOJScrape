#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{
    ll N;
    cin >> N;
    array<string, 4> cube,ORGCUBE;
    
    cin >> cube[0] >> cube[1] >> cube[2] >> cube[3];
    sort(cube.begin(),cube.end());
    ORGCUBE[0]=cube[0]; ORGCUBE[1]=cube[1]; ORGCUBE[2]=cube[2]; ORGCUBE[3]=cube[3];
    while (N--)
    {
        cube[0]=ORGCUBE[0]; cube[1]=ORGCUBE[1]; cube[2]=ORGCUBE[2]  ;cube[3]=ORGCUBE[3];
        string word;
        cin >> word;
        bool app;
       
        do
        {
            app = true;
            for (int i = 0; i < word.length(); i++)
                if (find(cube[i].begin(), cube[i].end(), word[i]) == cube[i].end())
                    app = false;
               // else
                    
          //  cout<<cube[0]<<" "<<cube[1]<<" "<<cube[2]<<" "<<cube[3]<<endl;
            if (app == true)
            {
                cout << "YES" << endl;
                break;
            }
        } while (next_permutation(cube.begin(), cube.end()));
        if(app!=true)
            cout<<"NO" << endl;
    }
}
