using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

const int N = 205;
const ll oo = 1e18 + 7;
const int BASE = 10000;
int EXP[5] = {1, 10, 100, 1000, 10000};
const vi one = vi(1, 1);
const vi zero = vi(1, 0);

int n, s, w, m, bMin, bMax;
ll h[N], weight[N];
vi p[N][N], sp[N][N], dp[N][N];
vi bigInit(const string &str) {
    vi c;
    int i = str.size();
    while (i > 0) {
        int s = 0;
        for (int j = 0; j < 4; j++) {
            if (--i < 0) break;
            s += (str[i] - '0') * EXP[j];
        }
        c.push_back(s);
    }
    return c;
}
void bigOut(const vi &a) {
    int n = a.size();
    printf("%d", a[n-1]);
    for (int i = n-2; i >= 0; i--) printf("%04d", a[i]);
    printf("\n");
}
void viOut(const vi &a) {
    for (int i = 0; i < a.size(); i++) cout << a[i] << " " ;
    cout << "\n";
}
bool operator < (const vi &a, const vi &b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--)
        if (a[i] != b[i]) return a[i] < b[i];
    return 0;
}
vi operator + (const vi &a, const vi &b) {
    vi c;
    int carry = 0;
    for (int i = 0; i < max(a.size(), b.size()); ++i) {
        if (i < a.size()) carry += a[i];
        if (i < b.size()) carry += b[i];
        c.push_back(carry % BASE);
        carry /= BASE;
    }
    if (carry > 0) c.push_back(carry);
    return c;
}
vi operator - (const vi &a, const vi &b) {
    vi c;
    int carry = 0;
    for (int i = 0; i < a.size(); ++i) {
        int s = a[i] - carry;
        if (i < b.size()) s -= b[i];
        if (s < 0) s += BASE, carry = 1;
        else carry = 0;
        c.push_back(s);
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
vi operator * (const int b, const vi &a) {
    int carry = 0; vi c;
    for (int i = 0; i < a.size(); i++) {
        carry += a[i] * b;
        c.push_back(carry % BASE);
        carry /= BASE;
    }
    if (carry > 0) c.push_back(carry);
    return c;
}
vi operator * (const vi &a, const vi &b) {
    vi c(a.size() + b.size() + 5, 0);
    for (int i = 0; i < a.size(); ++i)
    for (int j = 0; j < b.size(); ++j) {
        int k = i + j;
        c[k] += a[i] * b[j];
        c[k+1] += c[k] / BASE;
        c[k] %= BASE;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}
void init() {
    p[1][0] = sp[1][0] = one;
    FOR(i, 2, 201) {
        p[i][0] = p[i][i-1] = one;
        sp[i][0] = one;
        FOR(j, 1, i-2) {
            p[i][j] = (j+1) * p[i-1][j] + (i-j) * p[i-1][j-1];
            sp[i][j] = sp[i][j-1] + p[i][j];
        }
        sp[i][i-1] = sp[i][i-2] + one;
    }
    /*FOR(i, 0, 10) {
        FOR(j, 0, 10) printf("%8lld", p[i][j]);
        cerr << "\n";
    }
    cerr << "\n";
    FOR(i, 0, 10) {
        FOR(j, 0, 10) printf("%8lld", sp[i][j]);
        cerr << "\n";
    }*/
    FOR(j, 2, N-1) dp[1][j] = zero;
}
int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("organ.inp", "r", stdin);
    //freopen(".out", "w", stdout);
    //ifstream inp(".inp");
    //ofstream out(".out");
    init();

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d%d%d%d%d", &n, &s, &w, &m, &bMin, &bMax);
        FOR(i, 1, n) {
            scanf("%lld", &h[i]); // sumH
            h[i] *= m;
        }

        //dp[0][0] = zero;
        ll W = 0;
        FOR(i, 1, n) {
            W += h[i];
            if (W > bMax) {
                FOR(j, i, n) dp[j][1] = zero;
                break;
            } else if (W < bMin) dp[i][1] = zero;
            else {
                dp[i][1] = sp[i][min(i-1, w)];
                //viOut(sp[i][min(i, w)]);
            }
        }
        //cerr << "wtf\n";
        //FOR(i, 1, n) viOut(dp[i][1]);

        FOR(i, 2, n) FOR(j, 2, s) {
            dp[i][j] = zero;
            W = 0;
            FORD(k, i, 2) {
                W += h[k];
                if (W > bMax) break;
                if (dp[k-1][j-1] == zero || W < bMin) continue;

                vi tmp = dp[k-1][j-1] + sp[i-k+1][min(i-k, w)];
                if (dp[i][j] < tmp) {
                    dp[i][j] = tmp;
                    //printf("dp[%d][%d] -> dp[%d][%d]\n", k-1, j-1, i, j);
                }
            }
        }
        /*FOR(i, 1, n) FOR(j, 1, min(i, s)) if (!dp[i][j].empty()) {
            printf("dp[%d][%d] = ", i, j);
            bigOut(dp[i][j]);
        }*/
        bigOut(dp[n][s]);
    }
    return 0;
}
/** Happy Coding :D */
