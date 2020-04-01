#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)
#define task "mixperm"

const int N = 1e4 + 5;
int cntA[N], cntB[N], a[N], b[N];
int n, correctA, correctB, res;

void update(int cnt[], int val, int &correct, int delta) {
    correct -= cnt[val] == 1;
    cnt[val] += delta;
    correct += cnt[val] == 1;
}
void mix1(int i) {
    update(cntA, a[i], correctA, -1);
    update(cntA, b[i], correctA, +1);
    update(cntB, b[i], correctB, -1);
    update(cntB, a[i], correctB, +1);
}
void mix2(int i) {
    update(cntA, a[i], correctA, +1);
    update(cntA, b[i], correctA, -1);
    update(cntB, b[i], correctB, +1);
    update(cntB, a[i], correctB, -1);
}
int main() {
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    scanf("%d", &n);
    FOR(i, 1, n) {
        scanf("%d", &a[i]);
        cntA[a[i]] ++;
    }
    FOR(i, 1, n) {
        scanf("%d", &b[i]);
        cntB[b[i]] ++;
    }
    FOR(i, 1, n) {
        correctA += (cntA[i] == 1);
        correctB += (cntB[i] == 1);
    }
    //cerr << correctA << " " << correctB << "\n";
    int i = 1;
    while (1) {
        FOR(j, i, n) {
            mix1(j);
            res += (correctA == n) | (correctB == n);
            /*printf("%d %d: %d %d\n", i, j, correctA, correctB);
            FOR(i, 1, n) cerr << cntA[i] << " " ; cerr << "\n";
            FOR(i, 1, n) cerr << cntB[i] << " " ; cerr << "\n";*/
        }
        mix2(i);
        //cerr << i << " " << n << "\n";
        if (i == n) break; else i ++;
        res += (correctA == n) | (correctB == n);
        /*printf("%d %d: %d %d\n", i, n, correctA, correctB);
        FOR(j, 1, n) cerr << cntA[j] << " " ; cerr << "\n";
        FOR(j, 1, n) cerr << cntB[j] << " " ; cerr << "\n";*/

        FORD(j, n, i+1) {
            mix2(j);
            res += (correctA == n) | (correctB == n);
            /*printf("%d %d: %d %d\n", i, j, correctA, correctB);
            FOR(i, 1, n) cerr << cntA[i] << " " ; cerr << "\n";
            FOR(i, 1, n) cerr << cntB[i] << " " ; cerr << "\n";*/
        }
        mix2(i);
        //cerr << i << " " << n << "\n";
        if (i == n) break; else i ++;
    }
    printf("%d", res);

    return 0;
}
