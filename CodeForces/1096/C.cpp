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



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int tc, ang, start;
    cin >> tc;
    while (tc --) {
        cin >> ang;
        if (ang > 90) ang = 180 - ang, start = 2;
        else start = 1;
        //debug(ang);
        bool flag = 0;
        FOR(k, start, 10 * ang) {
            if (180 * k % ang == 0 && 180 * k / ang >= 3) {
                cout << 180 * k / ang << '\n';
                flag = 1;
                break;
            }
        }
        if (flag == 0) cout << "-1\n";
    }
}
