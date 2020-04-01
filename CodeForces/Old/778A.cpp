using namespace std;
#include <iostream>
#include <stdio.h>
#include <string.h>
string a, b;
int n, m, p[212345];

bool ok(int d) {
    string x = a;
    //cout << d << "\n";
    for (int i = 1; i <= d; i++) x[p[i]-1] = '.';
    int i = -1;
    //cout << x << endl;
    for (int j = 0; j < n && i < m; j++) {
        do i++;
        while (i < m && x[i] != b[j]);
    }
    //cout << i << endl;
    return i < m;
}
int main() {
    cin >> a >> b;
    m = a.size();
    n = b.size();
    for (int i = 1; i <= m; i ++) scanf("%d", &p[i]);
    int lo = 0, hi = m;
    while (lo < hi) {
        int mi = (lo + hi + 1) / 2;
        if (ok(mi)) lo = mi;
        else hi = mi - 1;
    }
    cout << lo;
}
