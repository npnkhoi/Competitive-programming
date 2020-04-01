#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((ll)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
typedef pair<ll, ll> LL;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI (2 * acos((ld)0))
#define linf (1ll << 60)
#define y1 y32432
#define y0 y435346

#define maxn 200005

ll n, m, st, fn, phi;
vector<pair<ll, ll> > V[maxn];
ll f[maxn];

void solve(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m >> st >> fn >> phi;
    For(i, 0, n) V[i].clear();
    For(run, 1, m){
    	ll u, v, c;
    	cin >> u >> v >> c;
    	c += (phi + 1) * run;
    	if(u == st) c -= run;
    	if(v == fn) c -= phi * run;
    	V[u].pb(mp(v, c));
    }

    priority_queue<pair<ll, ll> > que;
    que.push(mp(0, st));
    ms(f, 0x3f);
    f[st] = 0;
    while(!que.empty()){
    	ll u = que.top().se, c = -que.top().fi;
    	que.pop();
    	if(f[u] < c) continue;
    	if(u == fn){
    		cout << f[fn] << endl;
    		return;
    	}
    	Rep(i, sz(V[u])){
    		ll v = V[u][i].fi, add = V[u][i].se;
    		if(f[v] > f[u] + add){
    			f[v] = f[u] + add;
    			que.push(mp(-f[v], v));
    		}
    	}
    }
    cout << -1 << endl;
}

void sol(int test){
//	cout << test << endl;
//    freopen(("METRO/input/" + toString(test) + ".in").c_str(), "r", stdin);
//    freopen(("METRO/output/" + toString(test) + ".out").c_str(), "w", stdout);
    solve();
}

int main()
{
#ifdef THEMIS
	freopen("metro.inp", "r", stdin);
	freopen("metro.out", "w", stdout);
#endif //THEMIS

	sol(0);
//	srand(1112);
//	Rep(i, 50) gen(i);
//	Rep(i, 50) sol(i);
//	cerr << clock() << endl;
    return 0;
}
