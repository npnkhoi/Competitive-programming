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

const int N = 1e5 + 5;

string str;
stack<int> st;
int n, s[N];
lint res, p[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	cin >> str;
	n = str.size();

	REP(i, n) {
		if (str[i] == '(') {
			st.push(i);
		} else {
			int l = st.top();
			res += (i - l + 1) * p[l];
			st.pop();
			if (!st.empty()) {
				p[st.top()] += (lint) (i - l + 1) / 2 * s[st.top()];
				s[st.top()] += (i - l + 1) / 2;
			}
		}
	}
	cout << res;
}
