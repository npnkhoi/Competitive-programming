#include <bits/stdc++.h>
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
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define task "COLPATHS"
const int nTest = 100;

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}

set<ii> data;

void test() {
    ofstream inp(task".in");
    int n = Rand(2e5, 3e5), m = Rand(1, 3e5), k = Rand(1, 5);
    inp << n << ' ' << m << ' ' << k << '\n';
    FOR(i, 1, n) inp << Rand(1, k) << ' ';
    inp << '\n';
    data.clear();
    FOR(i, 1, m) {
        while (1) {
            int u = Rand(1, n - 1), v = Rand(u + 1, n);
            if (data.find(mp(u, v)) != data.end()) continue;
            data.insert(mp(u, v));
            inp << u << ' ' << v << '\n';
            break;
        }
    }
    inp.close();
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    srand(time(NULL));
    FOR(love, 1, nTest) {
        printf("*TEST NUMBER %d\n", love);
        test();
        cerr << "test created\n";

        double timer1 = clock();
        system(task".exe");
        timer1 = (clock() - timer1) / CLOCKS_PER_SEC;
        double timer2 = clock();
        //system(task"_BF.exe");
        timer2 = (clock() - timer2) / CLOCKS_PER_SEC;
        printf("Time: %lf %lf\n", timer1, timer2);
    }
}
