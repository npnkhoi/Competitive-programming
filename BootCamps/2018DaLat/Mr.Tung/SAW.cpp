using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

//ifstream inp("SAW.inp");
//ofstream out("SAW.out");
const int N = 1e3 + 5;
vector<char> v[N];
int main() {
    freopen("SAW.inp", "r", stdin);
    freopen("SAW.out", "w", stdout);
    int n;
    string s;
    scanf("%d ", &n);
    getline(cin, s);
    int size = s.size();
    for (int i = 0; i < size; ) {
        int j = i;
        for (int k = 1; k <= n && j < size; ++j, ++ k) v[k].push_back(s[j]);
        for (int k = n-1; k >= 2 && j < size; ++j, --k) v[k].push_back(s[j]);
        i = j;
    }
    FOR(i, 1, n) REP(j, v[i].size()) printf("%c", v[i][j]);
    return 0;
}
/** Happy Coding :D */
