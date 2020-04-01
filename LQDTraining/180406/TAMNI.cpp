#include <bits/stdc++.h>
using namespace std;
#define task "tamni"
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<ll, int> li;
typedef pair<int, ll> il;

const int N = 2e5 + 5;
const long long oo = 1e18 + 5;

long long n, pos[N], dist[N];
priority_queue<li, vector<li>, greater<li> > heap;
int k, rr;
vector<long long> v;
map<ll, int> id;
vector<il> adj[N];
vector<pair<ll, ll> > MKN;

ll _sqrt(ll x) {
    int l = 0, r = 1e9, res = r;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (mid * mid >= x) {
            res = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return res;
}
ll calc(ll x) { /// index of inside-cell
    ll t = _sqrt(x);
    if (x > (t * t + (t-1) * (t-1)) / 2) return x - (4*t - 5);
    else return x - (4*t - 7);
}

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);

    scanf("%lld", &n);
    scanf("%d", &k);
    for (int i = 1; i <= k ; i++) {
        long long x, t;
        scanf("%lld", &x);
        t = calc(x);
        MKN.push_back(mp(x, t));
        v.push_back(x);
        v.push_back(t);
    }
    v.push_back(1);
    v.push_back(n);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        if (i == 0 || v[i] != v[i-1]) {
            id[v[i]] = ++ rr;
            pos[rr] = v[i];
        }
    for (int i = 1; i < rr; i ++) {
        adj[i].push_back(mp(i+1, pos[i+1] - pos[i]));
        adj[i+1].push_back(mp(i, pos[i+1] - pos[i]));
    }
    for (int i = 0; i < MKN.size(); i++) {
        adj[id[MKN[i].fi]].push_back(mp(id[MKN[i].se], 1));
        adj[id[MKN[i].se]].push_back(mp(id[MKN[i].fi], 1));
    }
    for (int i = 1; i <= rr; i++) dist[i] = oo;
    dist[1] = 0; heap.push(mp(0, 1));
    while (!heap.empty()) {
        long long d = heap.top().first;
        int u = heap.top().second;
        heap.pop();
        if (d > dist[u]) continue;
        for (int j = 0; j < adj[u].size(); ++j) {
            il v = adj[u][j];
            if (dist[v.fi] > dist[u] + v.se) {
                dist[v.fi] = dist[u] + v.se;
                heap.push(mp(dist[v.fi], v.fi));
            }
        }
    }
    printf("%lld", dist[id[n]]);
}
