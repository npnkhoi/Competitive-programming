#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, k;
int a[N], f[N], g[N];

void load() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
}

void init() {
    deque <int> mi, ma;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) for (int j = f[i - 1]; j <= i; ++j) {
        while (!mi.empty() && mi.front() < j) mi.pop_front();
        while (!ma.empty() && ma.front() < j) ma.pop_front();

        while (!mi.empty() && a[mi.back()] > a[i]) mi.pop_back();
        while (!ma.empty() && a[ma.back()] < a[i]) ma.pop_back();

        mi.push_back(i);
        ma.push_back(i);
        if (a[ma.front()] - a[mi.front()] <= k) {
            f[i] = j;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) g[i] = max(i - f[i] + 1, g[i - 1]);
    //for (int i = 1; i <= n; ++i) cout << f[i] << "\n";
}

void process() {
    int answer = 0;
    for (int i = 1; i <= n; ++i)
        answer = max(answer, i - f[i] + 1 + g[f[i] - 1]);
    printf("%d\n", answer);
}

int main() {
  //  freopen("input.in", "r", stdin);
 //   freopen("output.out", "w", stdout);

    load();
    init();
    process();

    return 0;
}
