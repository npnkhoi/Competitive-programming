#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define task "arrange"

const int N = 1e5 + 5;
int n;
int a[N];
int balance, cnt1, cnt2, max1, max2;
long long s, res;
deque<ii> dq;
void sub1() {
    int state = 0;
    ll res = 0;
    balance = s / n;
    FOR(i, 1, n) {
        if (a[i] < balance) {
            if (state <= 0) {
                dq.push_back(mp(a[i], i));
                state = -1;
            } else {
                while (a[i] < balance && !dq.empty()) {
                    int val = dq.front().fi;
                    int pos = dq.front().se;
                    dq.pop_front();
                    a[i] += val - balance;
                    res += 1LL * (val - balance) * (i - pos);
                }
                if (a[i] > balance) dq.push_back(mp(a[i], i));
                else if (a[i] < balance) {
                    dq.push_back(mp(a[i], i));
                    state = -1;
                }
                if (dq.empty()) state = 0;
            }
        } else if (a[i] > balance) {
            if (state >= 0) {
                dq.push_back(mp(a[i], i));
                state = 1;
            } else {
                while (a[i] > balance && !dq.empty()) {
                    int val = dq.front().fi;
                    int pos = dq.front().se;
                    dq.pop_front();
                    a[i] -= balance - val;
                    res += 1LL * (balance - val) * (i - pos);
                }
                if (a[i] < balance) dq.push_back(mp(a[i], i));
                else if (a[i] > balance) {
                    dq.push_back(mp(a[i], i));
                    state = 1;
                }
                if (dq.empty()) state = 0;
            }
        }
        //printf("size: %d, state %d\n", (int) dq.size(), state);
    }
    printf("%lld\n", res);
}

void sub2() {
    balance = s / n;
    res = 0;
    int j;

    FOR(z, 1, n) if (a[z] > balance)
        {j = z; break;} /// init j - pointer

    FOR(i, 1, n) while (a[i] < balance) {
        if (a[j] + a[i] < 2*balance) {
            delta = a[j] - balance;
            a[j] -= delta;
            a[i] += delta;
            res += 1LL * deltta * abs(i - j);
        } else {
            delta = balance - a[i];
            a[i] += delta;
            a[j] -= delta;
            res += 1LL * delta * abs(i - j);
        }
        while (j <= n && a[j] <= balance) j ++; /// update j
    }

    FOR(i, 1, n) if (a[i] > balance + 1)
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    if (s % n == 0) sub1();
    else sub2();
    return 0;
}
/** Happy Coding :D */
