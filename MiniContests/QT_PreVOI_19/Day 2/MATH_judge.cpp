// This is to compare output of two programs
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "MATH"

typedef long long lint;
typedef vector<int> vi;

const int nTest = 100;

lint Rand(lint l, lint r) {
    lint res = l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
    if (res < 0) res += r - l + 1;
    return res;
}
void test() {
    ofstream inp(task".inp");
    int bound = 1e6, A = 1e9;
    int q = 1e6;
    int m = Rand(1, sqrt(bound)), n = Rand(1, bound / m);
    if (Rand(0, 1)) swap(m, n);
    inp << m << ' ' << n << '\n';
    REP(i, m) {
        REP(j, n) inp << Rand(1, A) << ' ';
        inp << '\n';
    }
    inp << q << '\n';
    REP(i, q) {
        int x = Rand(1, m), y = Rand(1, n), u = Rand(x, m), 
        v = Rand(y, n), c = Rand(1, A);
        inp << x << ' ' << y << ' ' << u << ' ' << v << ' ' << c << '\n';
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
        // system(task"_BF.exe");
        timer2 = (clock() - timer2) / CLOCKS_PER_SEC;
        printf("Time: %lf %lf\n", timer1, timer2);

        // if (system("fc "task".out "task".ans")) {
        // // if (system("fc "task".out "task".out")) {
        //     printf("WRONG ANSWER\n");
        //     return 0;
        // }
        // printf("CORRECT\n");
    }
}
