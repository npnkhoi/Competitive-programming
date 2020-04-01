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

const int N = 5e3 + 5;
const int A = 5e7 + 5;
int n, x;
int era[(int)1e7+5]; vector<int> prime;
int res[N], a[N], b[N];
vector<int> uni;
map<int, int> id;
bool mark[N];

void sieve() {
    FOR(i, 2, 1e7) if (era[i] == 0) {
        prime.pb(i);
        for (long long j = 1LL * i * i; j <= 1e7; j += i)
        if (era[j] == 0) era[j] = i;
    }
}
int main() {
    //freopen("D.inp", "r", stdin);
    //freopen("D.out", "w", stdout);
    sieve();
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &x);
        if (x == 0) a[i] = 0;
        else if (x > 0) a[i] = 1;
        else a[i] = -1, x = -x;

        for (int j = 0; 1LL * prime[j] * prime[j] <= x; j++) {
            if (x % prime[j] == 0) {
                int cnt = 0;
                while (x % prime[j] == 0)
                    x /= prime[j], cnt ++;
                if (cnt % 2) a[i] *= prime[j];
            }
        }
        if (x > 1) a[i] *= x;
        uni.push_back(a[i]);
    }
    //FOR(i, 1, n) cerr << a[i] << " "; cerr << "\n";

    int rr = 0;
    sort(uni.begin(), uni.end());
    REP(i, uni.size()) {
        if (i == 0 || uni[i] != uni[i-1]) id[uni[i]] = ++ rr;
    }
    FOR(i, 1, n) b[i] = id[a[i]];

    FOR(i, 1, n) {
        int cnt = 0;
        FOR(j, i, n) {
            if (a[j] != 0) {
                cnt += (mark[b[j]] == 0);
                mark[b[j]] = 1;
            }
            res[max(cnt, 1)] ++;
        }
        memset(mark, 0, sizeof mark);
    }
    FOR(i, 1, n) printf("%d ", res[i]);
}
