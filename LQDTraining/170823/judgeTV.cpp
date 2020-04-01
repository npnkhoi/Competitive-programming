#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, a, b) for (int i = a; i >= b; i--)
#define REP(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
const string name = "TRAVEL";
const int ntest = 50;
ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * RAND_MAX * RAND_MAX * RAND_MAX +
    1LL * rand() * RAND_MAX * RAND_MAX +
    1LL * rand() * RAND_MAX +
    1LL * rand()) % (r - l);
}
void test() {
    ofstream inp((name + ".inp").c_str());
    int n = 30, s = Rand(0, (long long)2e7);
    //s = 333333;
    inp << n << " " << s << endl;
    //cerr << n << " " << s << endl;
    REP(i, n) {
        inp << Rand(0, s/n) + Rand(0, s/n) + Rand(0, s/n) << endl;
        //inp << 1 << endl;
    }
    inp.close();
}
int main() {
    srand(time(NULL));
    REP(itest, ntest) {
        test();

        double Time = clock();
        system((name + ".exe").c_str());
        Time = (clock() - Time) / double(CLOCKS_PER_SEC);
        //system((name + "_BF.exe").c_str());

        if (system(("fc " + name + ".out " + name + ".out").c_str())) {
            cout << "WRONG ANSWER @@@@@@@@@@@@@@\n";
            return 0;
        }
        else printf("Test %d: %lf\n", itest, Time);
    }
}
