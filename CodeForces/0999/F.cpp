#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define debug(x) cerr << #x << ": " << x << "\n"
#define task "0"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;

const int N = 503;
const int K = 13;
const int A = 1e5 + 5;
int n, k;
int cntCard[A], cntMan[A], f[N][N*K], joy[N*K];
long long res;

int main() {
	//cerr << "ok\n";
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cerr << "ok\n";
    //freopen(task".inp", "r", stdin);
    //cerr << "ok\n";
    //freopen(task".out", "w", stdout);
    cin >> n >> k;
    //cerr << "ok\n";
    FOR(i, 1, n*k) {
    	int x;
    	cin >> x;
    	cntCard[x] ++;
    }	
    //cerr << "ok\n";
    FOR(i, 1, n) {
    	int x;
    	cin >> x;
    	cntMan[x] ++;
    }
    //cerr << "ok\n";
    FOR(i, 1, k) cin >> joy[i];
    //cerr << "ok\n";

    FOR(i, 1, n) FOR(j, 1, n*k) {
    	FOR(t, 0, min(j, k)) f[i][j] = max(f[i][j], f[i-1][j-t] + joy[t]);
    	//cerr << i << " " << j << " " << f[i][j] << "\n"; 
    }
    FOR(i, 1, (int)1e5) res += f[cntMan[i]][min(cntMan[i] * k, cntCard[i])];
    cout << res;
}
