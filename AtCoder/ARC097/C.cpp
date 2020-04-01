#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; ++ i)
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define task ""
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 5005;
set<string> data;
string s, tmp[N], minstr;
int k, save;

int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    cin >> s >> k;
    int n = s.size();
    REP(i, n) tmp[i] = s[i];
    FOR(z, 1, k) {
        while (1) {
            minstr = "";
            REP(i, n) if (tmp[i] != "" && (tmp[i] < minstr || minstr == ""))
                minstr = tmp[i], save = i;
            if (data.find(minstr) == data.end()) {
                data.insert(minstr);
                if (z == k) cout << minstr;
                break;
            }
            if (n - save == minstr.size()) tmp[save] = "";
            else tmp[save] += s[save + (int)tmp[save].size()];
        }
    }
}
