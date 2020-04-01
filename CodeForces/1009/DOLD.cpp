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
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;
const int N = 1000 + 1;
int isPrime[N], res; 
vi prime;
void sieve() { // remember to call this beneath "int main()"
    memset(isPrime, -1, sizeof isPrime);
    for (int i = 2; i < N; i++) if (isPrime[i] == -1){
        prime.push_back(i);
        res += 1000 - 1000 / i;
        //printf("%d\n", i);
        for (long long j = 1LL*i*i; j < N; j+=i) isPrime[j] = 0;
    }
}
int main() {
	//ios_base::sync_with_stdio(0);
	//cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	sieve();
	cerr << prime.size() << " " << res; 
}

