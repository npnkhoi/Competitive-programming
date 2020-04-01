#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const string name = "DG";
const int ntest = 50;
ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * RAND_MAX * RAND_MAX * RAND_MAX +
    1LL * rand() * RAND_MAX * RAND_MAX +
    1LL * rand() * RAND_MAX +
    1LL * rand()) % (r - l);
}
void test() {
    int m = Rand((int)1e5);

}
int main() {
    REP(itest, ntest) {
        test();

        double Time = clock();
        system((name + ".exe").c_str());
        Time = (clock() - Time) / double(CLOCKS_PER_SEC);
        system((name + "_BF.exe").c_str());

        if (system(("fc " + name + ".out " + name + ".ans").c_str)) {
            cout << "WRONG ANSWER @@@@@@@@@@@@@@\n";
            return 0;
        }
        else printf("Test %d: %lf\n", itest, Time);
    }
}
