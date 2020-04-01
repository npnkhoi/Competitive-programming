#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
string a, b, s;
int m, n, l, r, z[N];
int main() {
    getline(cin, a);
    getline(cin, b);
    s = b + '*' + a;
    m = b.size(); n = s.size();
    l = r = -1;
    for (int i = 1; i < n; i++) {
        z[i] = 0;
        if (i <= r) z[i] = min(z[i-l], r-i+1);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i] ++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
        if (z[i] >= m) printf("%d ", i - m);
    }
}
//ababa
