#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define FORD(i,a,b) for (int i = a; i >= b; --i)
#define REP(i,n) for (int i = 0; i < n; ++i)

#define task "minsum"
const int nTest = 100;
long long Rand(long long l, long long r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}
void test() {
    ofstream inp(task".inp");
    inp << "1\n";
    inp << Rand(1, 100) << " " << Rand(1, 100) << "\n";
    inp.close();
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    FOR(iTest, 1, nTest) {
        printf("Test %d\n", iTest);
        test();

        double time1 = clock();
        system(task".exe");
        time1 = (clock() - time1) / CLOCKS_PER_SEC;

        double time2 = clock();
        system(task"_BF.exe");
        time2 = (clock() - time2) / CLOCKS_PER_SEC;

        cerr << time1 << " " << time2 << "\n";
        if (system("fc "task".out "task".ans")) {
            printf("WRONG ANSWER\n");
            return 0;
        }
        printf("CORRECT");
    }
}
