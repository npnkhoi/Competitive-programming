#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define vecOut(v) cerr << #v << " = "; for (int i = 0; i < v.size(); ++ i) cerr << v[i] << ' '; cerr << '\n'
#define all(x) x.begin(), x.end()

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 3005;

int m, n, k, a[N], b[N], grad[N];
vi va, vb, cand, res;
deque<int> q;

void calc(int a[], int n, int k, vi &v) {
    int idx = 0;
    v.clear();
    while (!q.empty()) q.pop_back();
    FOR(i, 1, k) {
        while (idx < n - k + i) {
            ++ idx;
            while (!q.empty() && q.back() > a[idx]) q.pop_back();
            q.push_back(a[idx]);
        }
        v.push_back(q.front());
        q.pop_front();
    }
}

/*void Merge(vi &a, vi &b, vi &c) {
    c.clear();
    int i = 0, j = 0;
    while (i < a.size() || j < b.size()) {
        if (i == a.size()) {
            for (; j < b.size(); j ++) c.push_back(b[j]);
        } else if (j == b.size()) {
            for (; i < a.size(); i ++) c.push_back(a[i]);
        } else {
            if (a[i] < b[j]) c.push_back(a[i]), i ++;
            else c.push_back(b[j]), j ++;
        }
    }
}*/

void Merge(vi &a, vi &b, vi &c){
    c.clear();
    grad[a.size() - 1];
    FORD(i, a.size() - 2, 0) {
        if (a[i] == a[i + 1]) grad[i] = grad[i + 1];
        else grad[i] = (a[i] < a[i + 1]);
    }
    int j = 0;
    REP(i, a.size()) {
        while (1) {
            if (j == b.size()) break;
            if (b[j] > a[i]) break;
            if (b[j] == a[i] && grad[i] == 0) break;
            c.push_back(b[j]);
            j ++;
        }
        c.push_back(a[i]);
    }
    for (; j < b.size(); j ++) c.push_back(b[j]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >>  m >> n >> k;
    FOR(i, 1, m) cin >> a[i];
    FOR(j, 1, n) cin >> b[j];
    FOR(i, max(k - n, 0), min(m, k)) {
        //debug(i);
        calc(a, m, i, va);
        calc(b, n, k-i, vb);
        //cerr << "done calc\n";
        Merge(va, vb, cand);
        //vecOut(va);
        //vecOut(vb);
        //vecOut(cand);
        if (res.empty() || cand < res) res = cand;
    }
    REP(i, k) cout << res[i] << ' ';
}

