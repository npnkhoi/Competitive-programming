#include <cstdio>
#include <iostream>

using namespace std;

#define debug(x) cerr << #x << ": " << x << "\n"
#define task "faflower"

const int N = 25;
const int MAX_SPAN = (1 << 20) + 5;
int n, newMask, mask, a[N][N], pos[MAX_SPAN], nex[MAX_SPAN];
long long t;
long long rec[N], val[MAX_SPAN];

int bit(int mask, int i) { return (mask & (1 << i)) > 0;}
void calc(int &mask) {
    newMask = 0;
    for (int i = 0; i < n; ++i) {
        rec[i] = 0;
        for (int j = 0; j < n; j++) if (a[i][j]) {
            rec[i] += (bit(mask, j)) ? 1 : 2;
        }
        if (rec[i]%2) newMask |= (1 << i);
    }
}
long long sumVal(int mask, int d) {
    long long res = 0;
    for (int i = 1; i <= d; i++) {
        res += val[mask];
        mask = nex[mask];
    }
    return res;
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d%lld", &n, &t);
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        char ch;
        scanf(" %c", &ch);
        a[i][j] = (ch == '1');
    }
    for (int j = 0; j < n; j++)
        if (a[0][j]) mask += (1 << j);

    pos[mask] = 1;
    val[mask] = __builtin_popcount(mask);

    long long res = val[mask];
    for (int i = 2; i <= t; i++) {
        calc(mask);
        nex[mask] = newMask;
        mask = newMask;
        val[mask] = 0;
        for (int j = 0; j < n; j++) val[mask] += rec[j];
        if (pos[mask]) {
            int span = i - pos[mask];
            res += 1LL * (t - i + 1) / span * sumVal(mask, span);
            res += sumVal(mask, (t-i+1) % span);
            break;
        } else {
            pos[mask] = i;
            res += val[mask];
        }

    }
    printf("%lld", res);
}
