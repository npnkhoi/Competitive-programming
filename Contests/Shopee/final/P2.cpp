#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
using namespace std;

const int base1 = 256, base2 = 257;
const long long MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
const int N = 1005;

int a[N][N], b[N][N];
int m, n, p, q;
pair<long long, long long> expo[N*N];

struct HashValue {
    long long hash1 = 0, hash2 = 0;
    bool operator==(const HashValue other) {
        return (hash1 == other.hash1 && hash2 == other.hash2);
    }
    void add(int cur) {
        hash1 = hash1 * base1 + cur;
        hash1 %= MOD1;
        hash2 = hash2 * base2 + cur;
        hash2 %= MOD2;
    }

    void addHash(HashValue tail, int deg) {
        hash1 = (hash1 * expo[deg].first % MOD1 + tail.hash1) % MOD1;
        hash2 = (hash2 * expo[deg].second % MOD2 + tail.hash2) % MOD2;
    }
} ha[N][N], hb;

HashValue get(int row, int l, int r) {
    HashValue ret;
    ret.hash1 = (ha[row][r].hash1 - ha[row][l-1].hash1 * expo[r-l+1].first + MOD1 * MOD1) % MOD1;
    ret.hash2 = (ha[row][r].hash2 - ha[row][l-1].hash2 * expo[r-l+1].second + MOD2 * MOD2) % MOD2;
    return ret;
}

void init() {
    expo[0] = {1, 1};
    FOR(i, 1, m*n) {
        expo[i] = {expo[i-1].first * base1 % MOD1, expo[i-1].second * base2 % MOD2};
    }
}

int main() {
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin >> m >> n >> p >> q;
    init();
    FOR(i, 1, m) {
        FOR(j, 1, n) {
            cin >> a[i][j];
            ha[i][j] = ha[i][j-1];
            ha[i][j].add(a[i][j]);
        }
    }
    FOR(i, 1, p) FOR(j, 1, q) {
        cin >> b[i][j];
        hb.add(b[i][j]);
    }

    int res = 0;
    FOR(j, 1, n - q + 1) {
        HashValue hashTmp;
        FOR(k, 1, p) {
            HashValue miniRow = get(k, j, j+q-1);
            hashTmp.addHash(miniRow, q);
        }
        FOR(i, 1, m - p + 1) {
            if (hashTmp == hb) res ++;

            // remove row i
            HashValue upRow = get(i, j, j+q-1);
            hashTmp = {
                (hashTmp.hash1 - upRow.hash1 * expo[(p-1) * q].first % MOD1 + MOD1 * MOD1) % MOD1,
                (hashTmp.hash2 - upRow.hash2 * expo[(p-1) * q].second % MOD2 + MOD2 * MOD2) % MOD2
            };
            // add row i + p
            hashTmp.addHash(get(i+p, j, j+q-1), q);
        }
    } 

    cout << res;
}