#include <ctime>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <complex>
#include <iterator>
#include <bitset>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,n) for (int i = 0; i < n; i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define task "fmatch"
typedef long long ll;
typedef pair<int, int> ii;

const int nTest = 100;

long long Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r-l+1);
}
void test() {
    ofstream inp(task".inp");
    int nl, nr, m;
    nl = Rand(1, 5e4);
    nr = Rand(1, 5e4);
    m = Rand(1, 15e4);
    inp << nl << " " << nr << " " << m << "\n";
    while (m--) {
        inp << Rand(1, nl) << " " << Rand(1, nr) << "\n";
    }
    inp.close();
}

int main() {
    FOR(iTest, 1, nTest) {
        test();
        printf("Test %d\n", iTest);

        double Time = clock();
        system(task".exe");
        Time = (clock() - Time) / CLOCKS_PER_SEC;
        cerr << Time << "\n";
        if (Time > 1) break;

    }
}
