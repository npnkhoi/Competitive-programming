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
#define task "DADY"
const int nTest = 100;

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}

const int N = 2e5 + 5;

int a[N];

void test() {
    ofstream inp(task".inp");
    int n = 2e5, m = 2e5;
    inp << n << " " << m << "\n";
    for (int i = 1; i <= n; ++ i) {
        a[i] = i;   
    }
    random_shuffle(a + 1, a + n + 1);
    int p = 1;
    while (m --) {
        if (Rand(0, 1) && p <= n) {
            inp << "M " << Rand(1, n) << " " << a[p ++] << "\n";
        } else {
            inp << "D " << Rand(1, n) << " " << Rand(1, n) << "\n";
        }
    }
    inp.close();
}
int main() {
    // freopen(task".inp", "r", stdin);
    // freopen(task".out", "w", stdout);
    srand(time(NULL));
    FOR(love, 1, nTest) {
        printf("*TEST NUMBER %d\n", love);
        test();
        cerr << "done\n";

        double timer1 = clock();
        system(task"_Tan.exe");
        cerr << "done exe 1\n";
        timer1 = (clock() - timer1) / CLOCKS_PER_SEC;
        double timer2 = clock();
        system(task".exe");
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
