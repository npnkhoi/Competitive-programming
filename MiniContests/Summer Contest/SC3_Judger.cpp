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

#define task "sc3"

const int nTest = 10;
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
    int tc = 20 , n, q, d;
    inp << tc << "\n";
    while (tc --) {
        n = Rand(1, 500);
        q = Rand(1, 1e5);
        d = Rand(1, n);
        inp << n << " " << q << " " << d << "\n";
        FOR(i, 1, n) inp << Rand(1, 10) << " ";
        inp << "\n";
        while (q --) {
            int l = Rand(1, n-d+1);
            int k = Rand(1, d);
            inp << l << " " << k << "\n";
        }
    }
    inp.close();
}
int main() {
    srand(time(NULL));

    FOR(iTest, 1, nTest) {
        printf("* TEST NUMBER %d\n", iTest);

        test();

        double Time1 = clock();
        system(task".exe");
        Time1 = (clock() - Time1)/double(CLOCKS_PER_SEC);

        double Time2 = clock();
        system(task"_BF2.exe");
        Time2 = (clock() - Time2)/double(CLOCKS_PER_SEC);

        printf("Time: %f - %f\n", Time1, Time2);

        if (system("fc "task".out "task".ans")) {
        //if (system("fc "task".out "task".out")) {
            printf("WRONG ANSWER\n");
            return 0;
        }
        else {
            printf("CORRECT\n");
            /*if (Time1 > TimeLimit) {
                printf("TIME LIMIT EXCEEDED\n");
                return 0;
            }*/
        }
    }
    return 0;
}
/**/
