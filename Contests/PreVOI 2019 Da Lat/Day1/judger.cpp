#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <bitset>
#include <complex>
#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define FOR(i,a,b) for (int i = a; i <= b; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FORD(i,b,a) for (int i = b; i >= a; --i)

#define all(v) v.begin(), v.end()
#define debug(a) cerr << #a << " = " << a << '\n'

#define task ""

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

void test() {
    ofstream inp(task".inp");

    inp.close();
}

int main() {
    int n = 100;
    FOR(i, 1, n) {
        cerr << "Test " << i << ": \n";
        test();
        double Time1 = clock();
        system(task".exe");
        Time1 = (clock() - Time1) / 1000;
        double Time2 = clock();
        system(task"_BF.exe");
        Time2 = (clock() - Time2) / 1000;
        cerr << Time1 << " - " << Time2 << '\n';
        if (system("fc "task".out "task".ans")) {
            cerr << "WRONG!\n";
            return 0;
        } else {
            cerr << "CORRECT!\n";
        }
    }

}
