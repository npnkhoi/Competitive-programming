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
const int N = 1e5 + 5;
int n;
string s[N];
int cnt[30], a[30];
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    scanf("%d ", &n);
    for (int i = 1; i <= n; i++) {
        getline(cin, s[i]);
        cnt[s[i][0] - 'a'] ++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    if (s[i].size() == n-1) {
        memset(a, 0, sizeof a);
        for (int j = 0; j < n-1; j++) a[s[i][j]-'a'] ++;
        a[s[i][0]-'a'] ++;
        bool ans = 1;
        for (int j = 0; j < 26; j++) if (a[i] != cnt[i]) {
            ans = 0;
            break;
        }
        res += ans;
    }
    cout << res << endl;
    return 0;
}
/** Happy Coding ^^ */

