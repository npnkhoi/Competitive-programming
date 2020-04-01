#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
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

const int N = 40;

int n;
char a[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> n;
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			cin >> a[i][j];
			// if (isdigit(a[i][j])) {
			// 	if (a[i][j] - '0' >= n) {
			// 		cout << "No\n";
			// 		exit(0);
			// 	}
			// } else if ('A' <= a[i][j] && a[i][j] <= 'Z') {
			// 	if (10 + a[i][j] - 'A' >= n) {
			// 		cout << "No\n";
			// 		exit(0);
			// 	}
			// } else {
			// 	cout << "No\n";
			// 	exit(0);
			// }
		}
	}	
	FOR(i, 1, n) {
		FOR(j, 1, n - 1) FOR(k, j + 1, n) {
			if (a[i][j] == a[i][k] || a[j][i] == a[k][i]) {
				cout << "No\n";
				exit(0);
			}
		}
	}
	FOR(j, 2, n) if (a[1][j - 1] > a[1][j] || a[j - 1][1] > a[j][1]) {
		cout << "Not Reduced\n";
		exit(0);
	}
	cout << "Reduced\n";
}
