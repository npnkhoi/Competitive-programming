#include <bits/stdc++.h>

using namespace std;
#define int long long

const int N = 1e5 + 5, MOD = 1e9 + 7;
int n, q, a[N];

struct node {
    int lazy;
    int sum;
    int prod;
} st[4 * N];

int Left(int x) {
    return (x << 1);
}

int Right(int x) {
    return (x << 1) + 1;
}

void push(int id, int L, int R) {
    int mid
}

void add(int id, int L, int R, int i, int j, int x) {
    if (L > j || R < i) {
        return;
    }
    if (L >= i && R <= j) {
        st[id].lazy += x;
        st[id].sum += (R - L + 1) * x;
        st[id].sum %= MOD;
        st[id].prod += (st[id].sum * (R - L) % MOD) * x % MOD + (x * x % MOD) * ((R - L) * (R - L + 1) / 2) % MOD) % MOD;
        st[id].prod %= MOD;
    }
    int mid = (L + R) >> 1;
    st[id].lazy += x;
    st[id].sum += (R - L + 1) * x;
    st[id].sum %= MOD;
    st[id].prod += (st[id].sum * (R - L) % MOD) * x % MOD + (x * x % MOD) * ((R - L) * (R - L + 1) / 2) % MOD) % MOD;
    st[id].prod %= MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("K.inp", "r", stdin);

    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    return 0;
}
