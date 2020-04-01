// THINHK CAREFULLY ... ARE YOU READY !?

#include <bits/stdc++.h>
#define ll long long

using namespace std;
//==================<< END OF TEMPLATE >>========================

string a,b;
int n,m,cnt[30],res;
bool ok;
//--------------<< ENF OF VARIABLES DECLARATION >>---------------
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin>>a; n=a.size();
    cin>>b; m=b.size();

    res=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
    {
        memset(cnt,0,sizeof(cnt));
        for (int k=1;k<min(n-i+1,m-j+1);k++)
        {
            cnt[a[i+k-1]-'a']++;
            cnt[b[j+k-1]-'a']--;
            ok=1;
            for (int i=0;i<26;i++) if (cnt[i]!=0) ok=0;
            if (ok) res=max(res,k);
        }
    }
    cout<< res;
    return 0;
}
/* -----BACKUP -------------

*/
// ACCEPTED ONE HIT, OR BE A DOGG :)
