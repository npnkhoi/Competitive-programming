#include <bits/stdc++.h>
using namespace std;
const int  N = 1e5 + 5;
int n, k, m, cost[N], b[N];
map<string, int> id;
string word[N];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++) {
        cin >> word[i];
        id[word[i]] = i;
    }
    for (int i = 1; i <= n; i++) cin >> cost[i];
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        int tmp = 1e9 + 7;
        for (int j = 1; j <= x; j++) {
            cin >> b[j];
            tmp = min(tmp, cost[b[j]]);
        }
        for (int j = 1; j <= x; j++)
        cost[b[j]] = tmp;
    }
    long long res = 0;
    for (int i = 1; i <= m; i++) {
        string str;
        cin >> str;
        res += cost[id[str]];
    }
    cout << res;
}
