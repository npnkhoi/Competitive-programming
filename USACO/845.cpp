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

#define task "backforth"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 22;

int a[N], pos[N], cap[3];
set<int> data;

void brute(int turn, int loc) {
    if (turn == 5) {
        data.insert(cap[1]);
        return;
    }
    FOR(i, 1, 20) if (pos[i] == loc) {
        pos[i] = 3 - loc;
        cap[loc] -= a[i];
        cap[3 - loc] += a[i];

        brute(turn + 1, 3 - loc);

        pos[i] = loc;
        cap[loc] += a[i];
        cap[3 - loc] -= a[i];
    }
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".in", "r", stdin);
	freopen(task".out", "w", stdout);
    FOR(i, 1, 20) cin >> a[i];
    FOR(i, 1, 10) pos[i] = 1;
    FOR(i, 11, 20) pos[i] = 2;
    cap[1] = cap[2] = 1000;
    brute(1, 1);
    cout << data.size();
}
