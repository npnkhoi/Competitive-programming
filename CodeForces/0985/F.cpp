#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 2e5 + 5;
int n, m, l, r, z[N], ml[30], mr[30], pos[30];
string s;
bool ok(int x, int y) {
    cerr << (char) (x + 'a') << " " << (char) (y + 'a') << "\n";
    if (ml[x] == -1 && mr[y] == -1) ml[x] = y, mr[y] = x;
    cerr << (char)(ml[x] + 'a') << " " << (char)(mr[y] + 'a') << "\n";
    return ml[x] == y;
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d ", &n, &m);
    getline(cin, s);
    memset(pos, -1, sizeof pos);
    REP(i, n) if (pos[s[i] - 'a'] == -1) pos[s[i] - 'a'] = i;

    z[0] = n;
    l = r = 0;
    FOR(i, 1, n-1) {
        cerr << "pos " << i << "\n";
        if (i <= r) {
            z[i] = min(z[i-l], r-i+1);
        }
        cerr << "thua ke " << z[i] << "\n";
        memset(ml, -1, sizeof ml);
        memset(mr, -1, sizeof mr);
        REP(ch, 26) if (pos[ch] != -1 && pos[ch] < z[i]) {
            int ch2 = s[pos[ch]+i] - 'a';
            ml[ch] = ch2;
            mr[ch2] = ch;
            cerr << "prematch " << (char) (ch + 'a') << " " << (char)(ch2 + 'a') << "\n";
        }
        while (i + z[i] - 1 < n && ok(s[z[i]] - 'a', s[i+z[i]] - 'a')) z[i] ++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
        cerr << z[i] << "\n";
    }
    while (m--) {
        int x, y, l;
        scanf("%d%d%d", &x, &y, &l);
        if (min(z[x-1], z[y-1]) >= l) printf("YES\n");
        else printf("NO\n");
    }
}
