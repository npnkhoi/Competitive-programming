#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
#define mp make_pair
typedef long long ll;
typedef pair<int, ll> il;
const int N = 43;
int n;
ll s, minA, a[N], tong;
map<il, ll> dp;
vector<ll> f[N];
void sub1() {
    bool ok;
    int res = 0;
    FOR (mask, 1, (1<<n) - 1) {
        ok = 1;
        long long sum = 0;
        REP(i, n) {
            sum += a[i+1] * (((1<<i) & mask) > 0);
            if (sum > s) {ok = 0; break;}
        }
        if (ok && sum == s) res ++;
    }
    printf("%d", (res == 0) ? -1 : res);
    //printf("%d", res);
}
void Insert(map<long long, long long> &data, long long val) {
    if (data.find(val) != data.end()) data[val] ++;
    else data[val] = 1;
}
long long Count(map<long long, long long> data, long long val) {
    if (data.find(val) == data.end()) return 0;
    else return data[val];
}
void sub2() {
    map<long long, long long> data1, data2;
    map<long long, long long>::iterator it;
    bool ok;
    long long sum = 0, res = 0;
    int m = n/2;

    FOR(mask, 0, (1<<m) - 1) {
        //cout << mask << endl;
        ok = 1; sum = 0;
        REP(i, m) {
            sum += a[i+1] * (((1<<i) & mask) > 0);
            //cout << "=>" << sum << " ";
            if (sum > s) {ok = 0; break;}
        }
        //cout << endl;
        if (ok) {
            Insert(data1, sum);
            //cout << mask << " " <<  sum << endl;
        }
    }
    //for (it = data1.begin(); it != data1.end(); it++) cout << it -> first << "  ";
    //cout <<endl;
    FOR (mask, 0, (1<<(n-m)) - 1) {
        //cout << mask << endl;
        ok = 1; sum = 0;
        REP(i, n-m) {
            sum += a[i+m+1] * (((1<<i) & mask) > 0);
            //cout << "=>" << sum << " ";
            if (sum > s) {ok = 0; break;}
        }
        //cout << endl;
        if (ok) {
            res += Count(data1, s - sum);
            //cout << mask << " " << sum << " " << res << endl;
        }
    }
    if (res == 0) printf("-1\n");
    else printf("%lld\n", res);

}
void sub3() {
    //cerr << "sub3\n";
    reverse(a+1, a+n+1);
    for (int i = 0; i <= n; i++) f[i].resize(s+2);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    for (int j = 0; j <= s; j++) {
        f[i][j] = f[i-1][j];
        if (j >= a[i]) f[i][j] += f[i-1][j-a[i]];
    }
    if (f[n][s] == 0) printf("-1\n");
    else printf("%lld", f[n][s]);
}
int main() {
    freopen("TRAVEL.inp", "r", stdin);
    freopen("TRAVEL.out", "w", stdout);
    scanf("%d %lld", &n, &s);
    //minA = (long long) 2e9;
    FOR (i, 1, n) {
        scanf("%lld", &a[i]);
        tong += a[i];
        minA = min(minA, a[i]);
    }
    //sort(a + 1, a+n+1);
    //reverse(a+1, a+n+1);
    if (tong < s) printf("-1");
    else if (n <= 22) sub1();
    else if (n*s <= 3e7) sub3();
    else sub2();
}
