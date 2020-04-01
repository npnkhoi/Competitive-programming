using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)
const int N = 1e5 + 5;
const int D = 20;
ll a[N], EXP[D];
int p[D];
int n, d, q;

bool ok(ll num, ll tmp) {
    //cout << num << " " << tmp << endl;
    int lo = 1, hi = n;
    while (lo < hi) {
        int mi = (lo + hi) / 2;
        if (a[mi] / tmp >= num) hi = mi;
        else lo = mi + 1;
    }
    //cout << "---\n";
    return (a[lo] / tmp) == num;
}

void numOut(ll num, int cnt) {
    if (cnt == 0) return;
    numOut(num/q, cnt-1);
    printf("%lld", num%q);
}
int main() {
    freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d %d %d", &n, &d, &q);
    EXP[0] = 1;
    FOR(i, 1, D-1) {
        EXP[i] = EXP[i-1] * q;
        //cout << EXP[i] << endl;
    }
    FOR(i, 1, d) {
        scanf("%d", &p[i]);
        p[i] += p[i-1];
    }

    char ch;
    FOR(i, 1, n) {
        REP(j, d) {
            scanf(" %c", &ch);
            a[i] = a[i] * q + ch - '0';
        }
    }
    sort(a+1, a+n+1);
    queue<ll> qu;
    qu.push(0);
    int cnt = 0;
    bool sol = 0;
    ll res = 0;
    //cout << EXP[0] << endl;
    while (++cnt <= d) {
        int t = qu.size();
        while (t--) {
            ll num = qu.front(); qu.pop();
            REP(x, q) {
                if (!ok(num * q + x, EXP[d-cnt])) {
                    sol = 1;
                    res = num * q + x;
                    break;
                } else {
                    qu.push(num*q+x);
                }
            if (sol) break;
            }
        }
        if (sol) break;
    }
    if (sol == 0) {
        for (int i = 1; i <= d; i++) cout << "0";
        cout << "\n";
        cout << p[d];
        return 0;
    }
    numOut(res, cnt);
    for (int i = 1; i <=  d - cnt; i++) printf("0");
    printf("\n");
    printf("%d\n", p[cnt-1]);
    return 0;
}
/** Happy Coding ^^ */
