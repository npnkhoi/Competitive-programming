#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 4, C = 13;
int n, c, root = 1, totNode = 1;
string s[N];

struct TrieNode {
    int cnt;
    int child[27];
    TrieNode() {
        cnt = 0;
        for (int i = 0; i < 27; ++i) {
            child[i] = 0;
        }
    }
} node[N * C];

void add(string t) {
    int p = root;
    for (int i = 0; i < c; ++i) {
        node[p].cnt++;
        int cur = (t[i] == '*' ? 26 : t[i] - 'a');
        if (node[p].child[cur] == 0) {
            totNode++;
            node[p].child[cur] = totNode;
        }
        p = node[p].child[cur];
    }
    node[p].cnt++;
}

int query(int cur, string t, int i, string curS = "") {
    if (i == c) {
        return node[cur].cnt;
    }
    int res = 0;
    if (node[cur].child[t[i] - 'a']) {
        res += query(node[cur].child[t[i] - 'a'], t, i + 1, curS + t[i]);
    }
    if (node[cur].child[26]) { //asterisk
        res += query(node[cur].child[26], t, i + 1, curS + '*');
    }
    return res;
}

int main() {
    ios_base ::sync_with_stdio(0); cin.tie(0);
    freopen("F.inp", "r", stdin);

    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        add(s[i]);
    }

    int maxRes = 0;
    string res;
    res.clear();
    for (int i = 0; i < c; ++i) {
        res += 'z';
    }
    for (int i = 1; i <= n; ++i) {
        string t = s[i];
        for (int j = 0; j < c; ++j) if (t[j] == '*') {
            for (int ch = 0; ch < 26; ++ch) {
                t[j] = char('a' + ch);
                int curRes = query(1, t, 0);
                if (curRes > maxRes) {
                    maxRes = curRes;
                    res = t;
                } else if (curRes == maxRes) {
                    res = min(res, t);
                }
            }
            break;
        }
    }

    cout << res << ' ' << maxRes << endl;

    return 0;
}
