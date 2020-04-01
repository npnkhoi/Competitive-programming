#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef vector<int> vi;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = a; i <= b; ++ i)
#define FORD(i,b,a) for (int i = b; i >= a; -- i)
#define REP(i,n) for (int i = 0; i < n; ++ i)

#define task "bonus"

const int nTest = 100;
const double TimeLimit = 1.0;

double maxTime = 1.0;
int score = 0;

long long Rand(long long l, long long r) {
    return l + (1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                1LL * rand() * (RAND_MAX + 1) +
                1LL * rand() ) % (r-l+1);
}

void test() {
    ofstream inp(task".inp");
    int n = Rand(1, 500);
    int r = Rand(1, n);
    int k = Rand(1, 1e5);
    inp << n << " " << r << " " << k << "\n";
    FOR(i, 1, n) {
        FOR(j, 1, n) inp << Rand(1, 1e6) << " ";
        inp << "\n";
    }
    REP(z, k) inp << Rand(1, n-r+1) << " " << Rand(1, n-r+1) << "\n";
    inp.close();
}
int main() {
    srand(time(NULL));

    FOR(iTest, 1, nTest) {
        printf("* TEST NUMBER %d\n", iTest);

        test();
        cerr << "ok test\n";

        double Time1 = clock();
        system(task".exe");
        Time1 = (clock() - Time1)/double(CLOCKS_PER_SEC);
        cerr << ".out ok\n";

        double Time2 = clock();
        //system(task"_BF.exe");
        Time2 = (clock() - Time2)/double(CLOCKS_PER_SEC);
        cerr << ".ans ok\n";

        printf("Time: %f - %f\n", Time1, Time2);

        //if (system("fc "task".out "task".ans")) {
        if (system("fc "task".out "task".out")) {
            printf("WRONG ANSWER\n");
            return 0;
        }
        else {
            printf("CORRECT\n");
            if (Time1 > TimeLimit) {
                printf("TIME LIMIT EXCEEDED\n");
                return 0;
            }
        }
    }
    return 0;
}
/**/
