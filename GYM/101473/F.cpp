using namespace std;
#include <bits/stdc++.h>

const int N = 1e5 + 10;
set<int> data;
int n, a[N], s;
int main() {
    scanf("%d", &n);

    a[0] = 0; data.insert(0);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = a[i-1] + x;
        data.insert(a[i]);
    }

    int s = a[n];

    if (s % 3) {
        cout << "0";
        return 0;
    }

    int res = 0;

    for (int i = 0; a[i] < s / 3; i++)
        res += ((data.find(a[i] + s/3) != data.end()) && (data.find(a[i]+2*s/3) != data.end()));
    cout << res;
}
