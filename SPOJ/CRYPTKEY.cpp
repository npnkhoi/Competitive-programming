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
const int N = 5e4 + 5;
int tc;
set<ll> data;
set<ll>::iterator it;
queue<ll> q;
int n;
ll k;
bool res;

ll lcm(ll a, ll b, ll c) {
    a = a / c;
    if (int(floor((log10(a) + log10(b))) + 1) >= 14) return -1;
    else return a * b;
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d", &tc);
    while (tc --) {
        data.clear();
        while (!q.empty()) q.pop();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld", &k);
            q.push(k);
            data.insert(k);
        }
        scanf("%lld", &k);
        res = 0;

        while (!q.empty()) {
            ll t = q.front(); q.pop();
            //cout << t << endl;
            if (t == k) {
                res = 1;
                break;
            }
            for (it = data.begin(); it != data.end(); it++) {
                ll x = __gcd(t, *it);
                if (data.find(x) == data.end()) {
                    data.insert(x);
                    q.push(x);
                }
                x = lcm(t, *it, x);
                if (x != -1 && data.find(x) == data.end()) {
                    q.push(x);
                    data.insert(x);
                }
            }
        }
        if (res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
/** Happy Coding ^^ */

