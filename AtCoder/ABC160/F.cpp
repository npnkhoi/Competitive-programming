#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, factorial[N], ways_down[N], ways_up[N], ways_all[N], size[N];
vector<int> adj[N];

int power(int base, int exponent) {
    if (exponent == 0) return 1;
    long long res = power(base, exponent / 2);
    res = res * res % MOD;
    if (exponent % 2 == 1) {
        res = res * base % MOD;
    }
    return res;
}

int choose(int n, int k) {
    long long res = factorial[n];
    res = res * power(factorial[n - k], MOD - 2) % MOD;
    res = res * power(factorial[k], MOD - 2) % MOD;
    return res;
}

void dfs_1(int u, int parent) {
    ways_down[u] = 1;
    size[u] = 1;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs_1(v, u);
        size[u] += size[v];
        ways_down[u] = 1LL * ways_down[u] * choose(size[u] - 1, size[v]) % MOD * ways_down[v] % MOD;
    }
}

void dfs_2(int u, int parent) {
    if (parent == -1) {
        ways_up[u] = 1;
    } else {
        // ways_up[u] = 1LL * ways_all[parent] * power(choose(size[parent] - 1, size[u]), 2) % MOD * size[u] % MOD * (size[parent] - 1) % MOD;
        ways_up[u] = 1LL * ways_up[parent] 
            * ways_down[parent] % MOD * power(1LL * choose(size[parent] - 1, size[u]) * ways_down[u] % MOD, MOD - 2) % MOD
            * choose(n - size[u] - 1, n - size[parent]) % MOD;
    }
    ways_all[u] = 1LL * ways_down[u] * choose(n - 1, n - size[u]) % MOD * ways_up[u] % MOD;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs_2(v, u);
    }
}



void precalculate(int n) {
    factorial[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        factorial[i] = 1LL * factorial[i - 1] * i % MOD;
    }
}

int main() {
    scanf("%d", &n);
    precalculate(n);
    for (int i = 1; i <= n-1; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_1(1, -1);
    dfs_2(1, -1);
    // printf("n = %d\n", n);
    // for (int u = 1; u <= n; ++ u) {
    //     // printf("%d %d\n", ways_down[u], ways_up[u]);
    //     cerr << ways_up[u] << ' ' << ways_down[u] << '\n';
    // }
    for (int u = 1; u <= n; ++ u) {
        printf("%d\n", ways_all[u]);
    }

}