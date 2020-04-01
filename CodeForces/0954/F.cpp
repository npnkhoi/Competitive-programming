#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>
#define fi first
#define se second
#define mp make_pair
#define task "954F"
typedef long long ll;
typedef ll TMat[3][3];
const ll md = 1e9 + 7;
using namespace std;

int n;
long long m;
int tmp[3];
TMat base1, base2, f, f_;
vector< pair<ll, pair<ll, ll> > > v;

void One(TMat &a, int n) {
    memset(a, 0, sizeof a);
    for (int i = 0; i < n; i++) a[i][i] = 1;
}
void Copy(TMat a, int m, int n, TMat &b) {
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        b[i][j] = a[i][j];
}

void Mul(TMat &a, TMat &b, int m, int n, int p, TMat &c) {
    memset(c, 0, sizeof c);
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
    for (int k = 0; k < p; k++)
        c[i][k] = (c[i][k] + a[i][j]*b[j][k]) % md;
}
void Pow(TMat &a, int n, ll x, TMat &b) {
    TMat e, tmp;
    One(b, 3); Copy(a, 3, 3, e);
    while (x) {
        if (x & 1) {
            Mul(e, b, 3, 3, 3, tmp);
            Copy(tmp, 3, 3, b);
        }
        x >>= 1;
        Mul(e, e, 3, 3, 3, tmp);
        Copy(tmp, 3, 3, e);
    }
}

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    TMat BASE_MAT = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};

    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++) {
        ll x, y, z;
        scanf("%lld%lld%lld", &x, &y, &z);
        v.push_back(mp(y , mp(x - 1, 1)));
        v.push_back(mp(z+1, mp(x - 1, -1)));
    }
    sort(v.begin(), v.end());
    ll cur = 1;
    memset(f, 0, sizeof f);
    f[1][0] = 1;
    Copy(BASE_MAT, 3, 3, base1);
    for (int i = 0; i < v.size(); i++) {
        tmp[v[i].se.fi] += v[i].se.se;
        if (i == v.size() - 1 || v[i+1].fi != v[i].fi) {

            //printf("cur: %d\n", v[i].fi);
            //for (int i = 0; i < 3; i ++) cerr << tmp[i] << " ";
            //cerr << "\n";

            Pow(base1, 3, v[i].fi - cur - 1, base2);
            Mul(base2, f, 3, 3, 1, f_);
            Copy(f_, 3, 1, f);

            Copy(BASE_MAT, 3, 3, base1);
            for (int j = 0; j <= 2; j++)
            if (tmp[j] != 0) {
                memset(base1[j], 0, sizeof base1[j]);
            }

            Mul(base1, f, 3, 3, 1, f_);
            Copy(f_, 3, 1, f);

            cur = v[i].fi;
            //cerr << cur << "\n";
            //for (int i = 0; i < 3; i++) cerr << f[i][0] << " ";
            //cerr << "\n";
        }
    }
    //cerr << "ok\n";
    if (cur != m) {
        Pow(BASE_MAT, 3, m - cur, base2);
        Mul(base2, f, 3, 3, 1, f_);
        Copy(f_, 3, 1, f);
    }
    printf("%lld", f[1][0]);
}
