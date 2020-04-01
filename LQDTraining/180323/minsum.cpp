#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int a[15], b[15];
long long res = (long long) 1e18;
set<int> head;

int main() {
    freopen("minsum.inp", "r", stdin);
    freopen("minsum.out", "w", stdout);
    scanf("%d ", &n);
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        for (int i = s.size() - 1, tmp = 1; i >= 0; i --, tmp *= 10)
            a[s[i] - 'a'] += tmp;
        head.insert(s[0] - 'a');
    }
    //for (int i = 0; i <= 9; i++) cerr << a[i] << "\n";

    for (int i = 0; i <= 9; i++) b[i] = i;

    do if (head.find(b[0]) == head.end()) {
        long long tmp = 0;
        for (int i = 0; i <= 9; i++) tmp += 1LL * i * a[b[i]];
        res = min(res, tmp);
    } while (next_permutation(b, b + 10));
    printf("%lld", res);
}
