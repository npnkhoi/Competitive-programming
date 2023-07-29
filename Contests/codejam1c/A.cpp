#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int N = 105;

bool twoHead[N], vis[N], atMid[26];
string s[N];
int nxt[N], pre[N];

int main() {
  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);
  int tc;
  cin >> tc;
  FOR(iTest, 1, tc) {
    int n;
    cin >> n;
    bool res = true;
    memset(twoHead, 0, sizeof twoHead);
    memset(vis, 0, sizeof vis);
    memset(atMid, 0, sizeof atMid);
    memset(nxt, -1, sizeof nxt);
    memset(pre, -1, sizeof pre);
    // input
    FOR(i, 1, n) {
      cin >> s[i];
      int len = s[i].size();
      for (int j = 1; j < s[i].size(); ++ j) {
        if (s[i][j] != s[i][0]) {
          twoHead[i] = true;
          if (s[i][j] != s[i][len - 1]) {
            if (s[i][0] == s[i][len - 1]) res = false;
            if (atMid[s[i][j] - 'A'] && s[i][j-1] != s[i][j]) {
              res = false;
            } else {
              atMid[s[i][j] - 'A'] = true;
            }
          }
        }
      }
    }
    if (!res) {
      cout << "Case #" << iTest << ": IMPOSSIBLE\n";
      continue;
    }
    FOR(i, 1, n) {
      if (atMid[s[i][0] - 'A'] || atMid[s[i][s[i].size() - 1] - 'A']) {
        res = false;
      }
      if (!twoHead[i]) continue;
      // cerr << i << "is two head\n";
      FOR(j, 1, n) {
        if (twoHead[j] && j != i && s[j][0] == s[i][s[i].size() - 1]) {
          if (nxt[i] == -1 && pre[j] == -1) {
            nxt[i] = j;
            pre[j] = i;
          } else {
            res = false;
          }
        }
      }
    }
    if (!res) {
      cout << "Case #" << iTest << ": IMPOSSIBLE\n";
      continue;
    }
    // worry the twohead first
    string ans = "";
    FOR(i, 1, n) {
      if (!twoHead[i]) continue;
      if (pre[i] == -1) {
        int tmp = i;
        FOR(j, 1, n) {
          if (!twoHead[j] && s[j][0] == s[tmp][0] && !vis[j]) {
            vis[j] = true;
            ans += s[j];
          }
        }
        while (tmp != -1) {
          ans += s[tmp];
          vis[tmp] = true;
          // one-head in the middle
          FOR(j, 1, n) {
            if (!twoHead[j] && s[j][0] == s[tmp][s[tmp].size() - 1] && !vis[j]) {
              vis[j] = true;
              ans += s[j];
            }
          }
          tmp = nxt[tmp];
        }
      } 
    }
    // worry the one-head
    FOR(i, 1, n) {
      if (!vis[i]) {
        if (!twoHead[i]) {
          ans += s[i];
          vis[i] = true;
        } else {
          res = false;
        }
      }
    }
    if (!res) {
      cout << "Case #" << iTest << ": IMPOSSIBLE\n";
    } else {
      cout << "Case #" << iTest << ": " << ans << '\n';;
    }
  }
}