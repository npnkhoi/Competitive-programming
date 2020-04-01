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
#define task "SUBSEQ"
const int nTest = 100;

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}
void test() {
    ofstream inp(task".inp");
    int n = Rand(1, 10000);
    long long k = Rand(1, 1e13);
    inp << n << " " << k << "\n";
    FOR(i, 1, n) inp << Rand(1, 1e9) << " ";
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
