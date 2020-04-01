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

#define task "fliprow"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

string str;
int k, a[400], b[400];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
    ifstream f1(task".ans");
    ifstream f2(task".out");
    f1 >> str >> k;
    REP(i, k) f1 >> a[i];
    f2 >> str >> k;
    REP(i, k) f2 >> b[i];
    sort(a, a + k);
    sort(b, b + k);
    REP(i, k) {
        cerr << a[i] << '\n';
        if (a[i] != b[i]) cerr << "diff!";
    }
    cerr << "no diff";
}
