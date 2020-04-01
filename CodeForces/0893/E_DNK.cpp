#include <bits/stdc++.h>
#define MAX_N 1000100
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define LOWBIT(x) ( (x) & -(x) )

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int dx[] = {0 , -1 , 0 , 1};
int dy[] = {1 , 0 , -1 , 0};

int test;
int query;
long long F[MAX_N], invF[MAX_N];

long long POW(long long x, long long n) {
	if (n == 1) {
		return x;
	}

	long long tmp = POW(x, n >> 1);
	(tmp *= tmp) %= MOD;
	if (n % 2 == 1) {
		(tmp *= x) %= MOD;
	}
	return tmp;
}

void init() {
	F[0] = 1LL;
	invF[0] = 1LL;

	for (int i = 1; i <= 1000000; i++) {
		F[i] = (F[i - 1] * 1LL * i) % MOD;
		invF[i] = POW(F[i], MOD - 2);
	}
}

long long Comb(int n, int k) {
	long long res = F[n];
	(res *= invF[k]) %= MOD;
	(res *= invF[n - k]) %= MOD;
	return res;
}

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);

  //freopen("input.txt", "r" , stdin);
  init();
  scanf("%d", &query);

  while (query--) {
  	int l, x;
  	scanf("%d %d", &x, &l);
  	long long res = 1LL;

  	for (int i = 2; ; i++) {
  		if (i > (int) sqrt(x)) {
  			break;
  		}

  		if (x % i == 0) {
  			int cnt = 0;

  			while (x % i == 0) {
  				cnt++;
  				x /= i;
  			}

  			//cout << cnt << endl;

  			(res *= Comb(cnt + l - 1, l - 1)) %= MOD;
  		}
  	}

  	if (x > 1) {
  		(res *= Comb(l, l - 1)) %= MOD;
  	}

  	(res *= POW(2LL, (ll) l - 1));
  	printf("%I64d\n", res);
  }

	return 0;
}
