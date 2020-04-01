using namespace std;
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FOD(i, b, a) for (int i = b; i >= a; i--)
#define REP(i ,n) for (int i = 0; i < n; i++)
ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r-l+1);
}
void test() {
    ofstream inp("0.inp");
    int n = 2000;
    inp << n << "\n";
    int maxA = (int)1e9;
    while (n--) {
        inp << Rand(0, maxA) << "\n";
    }
    //inp << maxA << " " << maxA;
    inp.close();
}
int main() {
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
    srand(time(NULL));
    int ntest = 100;
    FOR(iTest, 1, ntest) {
        printf("Test: %d\n", iTest);
        test();
        double Time = clock();
        system("seq198.exe");
        Time = (clock() - Time) / CLOCKS_PER_SEC;

        //system("BF__seq198.exe");
        if (system("fc 0.out 0.ans")) {
        //if (system("fc 0.out 0.ans") {
            printf("Test %d: \x1b[31mWRONG\x1b[0m\n", iTest);
            return 0;
        }
        else printf("Test %d: \x1b[32mCORRECT (%f s)\x1b[0m\n", iTest, Time);
    }
    return 0;
}
/** Happy Coding ^^ */
