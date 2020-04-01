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
#define task ""
const int nTest = 100;

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}
void test() {
    ofstream inp("test.inp");
    int tc = Rand(0, 50);
    inp << tc << "\n";
    while (tc --) {
        int n = Rand(1, 400);
        int m = Rand(1, 2000);
        inp << n << " " << m << "\n";
        while (m --) {
            inp << Rand(1, n) << "," << Rand(1, n) << " ";
        }
        inp << "\n";
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
        system("CHIENTRANHVUTRU.exe");
        timer1 = (clock() - timer1) / CLOCKS_PER_SEC;
        double timer2 = clock();
        // system(task"_BF.exe");
        timer2 = (clock() - timer2) / CLOCKS_PER_SEC;
        printf("Time: %lf %lf\n", timer1, timer2);

        // if (system("fc "task".out "task".ans")) {
        if (system("fc "task".out "task".out")) {
            printf("WRONG ANSWER\n");
            return 0;
        }
        printf("CORRECT\n");
    }
}
