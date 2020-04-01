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
#define task "REINVENT"
const int nTest = 100;

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}
set<int> spe;
void test() {
    ofstream inp(task".inp");
    int n = Rand(1, 1e4);
    int m = n - 1 + Rand(1, 1e4);
    int x = Rand(1, n);
    inp << n << " " << m << " " << x << "\n";
    for (int i = 2; i <= n; ++ i) {
        inp << i << " " << Rand(1, i-1) << "\n";
    }
    for (int i = 1; i <= m - n + 1; ++ i) {
        inp << Rand(1, n) << " " << Rand(1, n) << "\n";
    }
    spe.clear();
    for (int i = 1; i <= x; ++ i) {
        int u;
        do u = Rand(1, n);
        while (spe.find(u) != spe.end());
        inp << u << " ";
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

        double timer1 = clock();
        system(task".exe");
        timer1 = (clock() - timer1) / CLOCKS_PER_SEC;
        double timer2 = clock();
        system(task"_BF.exe");
        timer2 = (clock() - timer2) / CLOCKS_PER_SEC;
        printf("Time: %lf %lf\n", timer1, timer2);

        if (system("fc "task".out "task".ans")) {
        // if (system("fc "task".out "task".out")) {
            printf("WRONG ANSWER\n");
            return 0;
        }
        printf("CORRECT\n");
    }
}
