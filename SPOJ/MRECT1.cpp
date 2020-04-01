#include <bits/stdc++.h>
using namespace std;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++) {
        scanf("%d%d", &p[i].fi, &p[i].se)
        vx.push_back(p[i].fi);
        vy.push_back(p[i].se);
    }
    scanf("%d", &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &r[i].fi.fi);
        scanf("%d", &r[i].fi.se);
        scanf("%d", &r[i].se.fi);
        scanf("%d", &r[i].se.se);
        vx.push_back(r[i].fi.fi);
        vx.push_back(r[i].se.fi);
        vy.push_back(r[i].fi.se);
        vy.push_back(r[i].se.se);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    nX = nY = 0;
    for (int i = 0; i < vx.size(); i++)
    if (i == 0 || vx[i] != vx[i-1]) {
        id[vx[i]] = ++nX;
    }
    for (int i = 0; i < vy.size(); i++)
    if (i == 0 || vy[i] != vyi-1]) {
        id[vy[i]] = ++nY;
    }


}
