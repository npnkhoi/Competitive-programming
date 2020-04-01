#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,b,a) for (int i = b; i >= a; i--)
#define task "crocodil"
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
    int m = Rand(1, 400);
    int n = Rand(1, 400);
    inp << m << " " << n << "\n";
    FOR(i, 1, m) {
        FOR(j, 1, n) {
            int x = Rand(0, 4);
            if (x == 0) inp << '.';
            else if (x == 1) inp << 'W';
            else if (x == 2) inp << 'E';
            else if (x == 3) inp << 'N';
            else inp << 'S';
        }
        inp << "\n";
    }
    inp.close();
}
int main() {
    //freopen(task".inp", "r", stdin);
    //freopen(task".out", "w", stdout);
    FOR(love, 1, nTest) {
        printf("TEST NUMBER %d\n", love);
        test();
        double timer = clock();
        system(task".exe");
        timer = (clock() - timer) / CLOCKS_PER_SEC;
        system(task"_BF.exe");
        if (system("fc "task".out "task".ans")) {
            printf("WRONG ANSWER\n");
            return 0;
        }
        printf("CORRECT (%lf)\n", timer);
        if (timer > 1) {
            printf("TIME LIMIT EXCEEDED\n");
            return 0;
        }
    }
}
