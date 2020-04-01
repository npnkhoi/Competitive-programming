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

#define task "SUM"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

int n;
priority_queue<int> heapMin;
priority_queue<int, vector<int>, greater<int> > heapMax;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
	cin >> n;
	long long res = 0, sumMin = 0, sumMax = 0;
	FOR(i, 1, n) {
		int val;
		cin >> val;
		while (!heapMax.empty() && heapMax.top() < val) {
			sumMax += val - heapMax.top();
			heapMax.pop();
			heapMax.push(val);
		}
		while (!heapMin.empty() && heapMin.top() > val) {
			sumMin += val - heapMin.top();
			heapMin.pop();
			heapMin.push(val);
		} 
		heapMax.push(val); sumMax += val;
		heapMin.push(val); sumMin += val;
		res += sumMax - sumMin;
		// debug(sumMin);
		// debug(sumMax);
	}	
	cout << res;
	return 0;
}
