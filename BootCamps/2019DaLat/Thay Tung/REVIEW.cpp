#include <bits/stdc++.h>
using namespace std;

vector<string> a[30];

int main() {

    int k, n; cin >> k >> n;
    vector<string> v;
    while (k--) {
        string s; cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end());

    for (string s : v) {
        a[s[0] - 'a'].push_back(s);
    }

    vector<int> cnt(30);
    while (n--) {
        char c; cin >> c;
        int sz = a[c - 'a'].size();
        cout << a[c - 'a'][cnt[c - 'a'] % sz] << "\n";
        ++cnt[c - 'a'];
    }
}
