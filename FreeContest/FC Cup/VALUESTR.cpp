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
#define all(x) x.begin(), x.end()

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1e6 + 5;

vector<char> v;
vi posA, posB;
int n, cntB, cntA, cnt[N];
ll c, val;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    cin >> n >> c;
    char ch;
    REP(i, n) {
        cin >> ch;
        if (ch == 'a' || ch == 'b') {
            v.push_back(ch);
            if (ch == 'a') {
                posA.push_back(v.size() - 1);
                cntA ++;
                cnt[v.size() - 1] = v.size() - cntA;
            } else {
                posB.push_back(v.size() - 1);
                val += cntA;
                cnt[v.size() - 1] = cntA;
            }

        } //else cntOth ++;
    }
    //REP(i, v.size()) cerr << v[i] << "\n";
    cntB = v.size() - cntA;
    if (val == 0) {
        cout << n;
        exit(0);
    }
    int idx = posB.size() - 1;
    while (val > c) {
        val -= cnt[posB[idx]];
        idx --;
        cerr << idx << "\n";
    }
    // check when idx == -1
    int res = n - (cntB - 1 - idx);
    cerr << "del 0: idx = " << idx << " " << val << "\n";
    FOR(i, 1, cntA) {
        val -= max(cntB - cnt[posA[i - 1]], cntB - 1 - idx);
        while (idx + 1 < posB.size()) {
            int tmp = max(0, cnt[posB[idx + 1]] - (i - 1));
            if (val + tmp > c) break;
            val += tmp;
            idx ++;
        }
        cerr << "del " << i << ": idx = " << idx << " " << val <<  "\n";
        res = max(res, n - i - (cntB - 1 - idx));
    }
    cout << res;
}
