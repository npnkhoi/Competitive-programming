#include <bits/stdc++.h>

using namespace std;
int c, v0, v1, v, a, l, cnt, now;
int main()
{
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    cin >> c >> v0 >> v1 >> a >> l;
    now = v0; v = v0; cnt = 1;
    while (now < c)
    {
        cnt ++;
        v = min(v+a, v1);
        now += v-l;
    }
    cout << cnt;
    return 0;
}
/**/
