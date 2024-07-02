#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool dk(int a, int b)
{
    return abs(a) < abs(b);
}

int main()
{
    int N;
    cin >> N;
    int a;
    vector<int> mpos, mneg, wpos, wneg;
    for (int x = 0; x < N; x++)
    {

        cin >> a;
        if (a > 0)
            mpos.push_back(a);
        else
            mneg.push_back(a);
    }
    for (int x = 0; x < N; x++)
    {
        cin >> a;
        if (a > 0)
            wpos.push_back(a);
        else
            wneg.push_back(a);
    }

    sort(mpos.begin(), mpos.end(), dk);
    sort(wneg.begin(), wneg.end(), dk);
    sort(mneg.begin(), mneg.end(), dk);
    sort(wpos.begin(), wpos.end(), dk);
//     for(int i = 0; i < wneg.size();i++)
//         cout<<wneg[i]<<' ';
//     cout<<endl;
//     for(int x = 0; x < mpos.size(); x++)
//         cout<<mpos[x]<<" ";
//    cout<<endl;
  int mposs=mpos.size(),mnegs=mneg.size(),wposs=wpos.size(),wnegs=wneg.size();
//  cout<<mnegs<<endl;
    int dem = 0;
    int j = -1;
    if(wnegs>0)
        for (int x = 0; x < mposs; x++)
        {
            do
            {
                j++;
                if(j>=wnegs) break;
            } while (mpos[x] >= abs(wneg[j]) && j < wnegs);
            if(j>=wnegs) break;
            if(mpos[x]<abs(wneg[j]))
                dem++;//cout<<mpos[x]<<' '<<wneg[j]<<endl;
        }
   //// cout<<dem<<endl;
    j = -1;
    if(mnegs>0)
        for (int x = 0; x < wposs; x++)
        {
            do
            {
                j++;
                if(j>=mnegs) break;
            } while (wpos[x] >= abs(mneg[j]) && j < mnegs);
            if(j>=mnegs)
                break;
            if(wpos[x]<abs(mneg[j]))
                dem++;//cout<<wpos[x]<<' '<<mneg[j]<<endl;
        }
    cout << dem;
}
