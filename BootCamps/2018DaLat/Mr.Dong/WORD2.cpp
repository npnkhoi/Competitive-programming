using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FOD(i,b,a) for (int i = (b); i >= (a); i--)
#define REP(i,n) for (int i = 0; i < (n); i++)

map<string, int> data, memo;
map<string, int>::iterator it;
bool same(string &t, string &s, int i) {
    if (i + t.size() > s.size()) return 0;
    else {
        REP(j, t.size())
        if (t[j] != s[i+j]) return 0;
        return 1;
    }
}
int dp(string &s) {
    if (memo.find(s) != memo.end()) return memo[s];
    else {
        //cout << "dp " << s << endl;
        int res = 0;
        REP(i, s.size()) {
            for (it = data.begin(); it != data.end(); ++ it) {
                string t = it ->  fi;
                if (same(t, s, i)) {
                    string v = s;
                    v.erase(v.begin()+i, v.begin()+i+t.size());
                    res = max(res, dp(v) + it -> se);
                }
            }
        }
        //cout << res << endl;
        return memo[s] = res;
    }
}
int main() {
    freopen("WORD.inp", "r", stdin);
    freopen("WORD.out", "w", stdout);
    string str, s;
    getline(cin, str);
    //cout << str << endl;

    int n;
    scanf("%d ", &n);
    FOR(i, 1, n) {
        getline(cin, s);
        int w;
        scanf("%d ", &w);
        //cout << s << " " << w << endl;
        data[s] = max(data[s], w);
    }
    cout << dp(str);
    return 0;
}
/** Happy Coding ^^ */

