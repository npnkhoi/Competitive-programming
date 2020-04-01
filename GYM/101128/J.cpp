#include <bits/stdc++.h>
using namespace std;

struct point {
    long long  X, Y;
    void operator -= (point v){ X-=v.X; Y-=v.Y; }
    bool operator < (point v){ if (v.Y==Y) return X<v.X; else return Y<v.Y;}
};
const int N = 1e5 + 10;
point p[N];
int hull[N];

int ccw(point p0, point p1, point p2) {
    long long  a1 = p0.Y - p1.Y;
    long long  b1 = p1.X - p0.X;
    long long  a2 = p1.Y - p2.Y;
    long long  b2 = p2.X - p1.X;
    long long  t = a1*b2 - a2*b1;
    if (t == 0) return 0;
    else if (t > 0) return 1;
    else return -1;
}
bool cmp(point u, point v) {return ccw(p[1], u, v) > 0;}

int main() {
    freopen("test.txt", "r", stdin);
    //-------------------------------------
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld %lld", &p[i].X, &p[i].Y);
    for (int i = 2; i <= n; i++)
        if (p[i] < p[1]) swap(p[1], p[i]);
    sort(p+2, p+n+1, cmp);
    for (int i = 1; i <= n; i++) cout << i << " " << p[i].X << " " << p[i].Y << endl;
    cout << endl;
    int m = 0;
    for (int i = 1; i <= n; i++) {
        while (m >= 2 && ccw(p[hull[m-1]], p[hull[m]], p[i]) <= 0)
            m--;
        hull[++m] = i;
    }
    while (m>=4 && ccw(p[hull[m-1]], p[hull[m]], p[1]) <= 0) m--;
    hull[m+1] = 1;
    int t;
    for (t = 2; t <= m; t++) if (p[hull[t]].Y >= p[hull[t+1]].Y) break;
    cout << "Hull: ";
    for (int i = 1; i <= m; i++) cout << i << " " << p[hull[i]].X << " " << p[hull[i]].Y << endl;
    cout << "t: " << t << endl;
    //------------------------------------
    scanf("%d", &n);
    int res = 0;
    while (n--) {
        point tmp;
        scanf("%lld %lld", &tmp.X, &tmp.Y);
        int l = 1, r = t;
        while (l < r) {
            int mi = (l+r+1)/2;
            if (p[hull[l]].Y <= tmp.Y) l = mi;
            else r = mi - 1;
        }
        int cnt = 0;
        if (ccw(p[hull[l]], tmp, p[hull[l+1]]) <= 0 ||
        (p[hull[l]].Y ==  tmp.Y && p[hull[l+1]].Y == tmp.Y)) cnt++;
        cout << l << " " << cnt << endl;
        //---------------------------------
        l = t, r = m+1;
        while (l < r) {
            int mi = (l+r+1)/2;
            if (p[hull[l]].Y >= tmp.Y) l = mi;
            else l = mi - 1;
        }
        if (ccw(p[hull[l]], tmp, p[hull[l-1]]) <= 0 ||
        (p[hull[l]].Y ==  tmp.Y && p[hull[l-1]].Y == tmp.Y)) cnt++;
        cout << l << " " << cnt << endl;

        if (cnt == 1) res ++;
    }
    printf("%d", res);
}
