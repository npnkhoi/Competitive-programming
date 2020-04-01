using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
const int N = 1005;
const int maxPrime = 1700;
long long a[N][N];
int h[N], n, m, res = 0, l[N], r[N];
bool prime[maxPrime + 5];
void sieve() {
    prime[0] = prime[1] = 1;
    FOR(i, 2, maxPrime) if (prime[i] == 0) {
        for (ll j = 1LL * i * i; j <= maxPrime; j += 1LL * i) prime[j] = 1;
    }
}
bool cp(ll &num) {
    ll tmp = (ll)(floor(sqrt(num)));
    return tmp * tmp == num;
}
bool lp(ll &num) {
    ll tmp = (ll)(floor(cbrt(num)));
    return (prime[tmp] == 0 && tmp * tmp * tmp == num);
}
int main() {
    //freopen("0.in", "r", stdin);
    //freopen("", "w", stdout);
    sieve();
    scanf("%d %d", &n, &m);
    while (m--) {
        int x, u, v, k;
        scanf("%d %d %d %d", &x, &u, &v, &k);
        a[x][u] += 1LL * k;
        a[x][v+1] -= 1LL * k;
    }
    FOR(i, 1, n) {
        ll tmp = 0;
        FOR(j, 1, n) {
            tmp += a[i][j];
            a[i][j] = tmp;
        }
    }
    FOR(i, 1, n) {
        FOR(j, 1, n)
            if (cp(a[i][j]) || lp(a[i][j]))
                h[j] ++; else h[j] = 0;

        stack<int> st;
        FOR(j, 1, n) {
            while (!st.empty() && h[st.top()] >= h[j]) st.pop();
            int tmp;
            if (st.empty()) l[j] = 0; else l[j] = st.top();
            st.push(j);
        }
        while (!st.empty()) st.pop();
        FOD(j, n, 1) {
            while (!st.empty() && h[st.top()] >= h[j]) st.pop();
            int tmp;
            if (st.empty()) tmp = n+1; else tmp = st.top();
            res = max(res, h[j] * (tmp - l[j] - 1));
            st.push(j);
        }

    }
    //ll gg = 0LL;
    //cout << cp(gg) << endl;
    cout << res;
    return 0;
}
/** Happy Coding ^^ */
