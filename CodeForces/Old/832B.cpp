using namespace std;
#include <bits/stdc++.h>
string a, x;
int n, q;
bool ok;
set<char> data;

bool valid(char u, char v) {
    if (u == v) return true;
    if (u == '*') return data.find(v) == data.end();
    if (u == '?') return data.find(v) != data.end();
    return 0;
}
int main() {
    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    string line;
    cin >> line;
    for (int i = 0; i < line.size(); i++) data.insert(line[i]);

    cin >> a;
    //cout << a << endl;
    n = a.size();
    bool star = 0;
    for (int i = 0; i < n; i++) if (a[i] == '*') star = 1;

    cin >> q;
    //cout << q;
    while (q--) {
        cin >> x;
        if (x.size() == n) {
            ok = 1;
            for (int i = 0; i < n; i++)
                if (!valid(a[i], x[i])) ok = 0;

            if (ok) {
                printf("YES\n");
                continue;
            }
        }
        else if (star && x.size() == n-1) {
            ok = 1;
            for (int i = 0, j = 0; i < n-1; i++, j++) {
                if (a[j] == '*') j++;
                if (!valid(a[j], x[i])) ok = 0;
            }

            if (ok) {
                printf("YES\n");
                continue;
            }
        }
        else if (star && x.size() > n) {
            ok = 1;
            for (int i = 0, j = 0; i < n; i++, j++) {
                if (a[i] == '*') {
                    for (; j - x.size() != i - n; j++)
                        if (!valid(a[i], x[j])) ok = 0;
                }
                else if (!valid(a[i], x[j])) ok = 0;
            }

            if (ok) {
                printf("YES\n");
                continue;
            }
        }
        printf("NO\n");
    }
}
