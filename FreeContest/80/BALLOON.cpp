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
const int K = 205;
int n, m, k, cur, pre;
int a[N];
deque<int> dq;
long long f[2][N], res;

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, n) scanf("%d", &a[i]);
    cur = 0; pre = 1;
    FOR(i, 1, k) {
        cur = !cur; pre = !pre;
        while (!dq.empty()) dq.pop_back();
        dq.push_back(i-1);
        FOR(j, i, n) {
            if (!dq.empty() && dq.front() < j - m) dq.pop_front();
            f[cur][j] = f[pre][dq.front()] + 1LL * i * a[j];
            //cerr << f[cur][j] << " ";
            while (!dq.empty() && f[pre][dq.back()] < f[pre][j]) dq.pop_back();
            dq.push_back(j);
        }
        //cerr << "\n";
    }
    FOR(j, 1, n) res = max(res, f[cur][j]);
    printf("%lld", res);
}
