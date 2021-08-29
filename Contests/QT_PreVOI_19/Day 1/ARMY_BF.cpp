#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task ""

typedef long long lint;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<lint, lint> ll;
typedef pair<lint, int> li;
typedef vector<int> vi;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int n, a[100], cnt = 0;
    cin >> n;
    FOR(i, 1, n) a[i] = i;
    do {
        bool flag = 1;
        FOR(i, 1, n) if (a[i] == i) flag = 0;
        cnt += flag;
        if (flag) {FOR(i, 1, n) cerr << a[i] << ' '; cerr << '\n';}
    } while (next_permutation(a + 1, a + n + 1));
    cout << cnt;
}
