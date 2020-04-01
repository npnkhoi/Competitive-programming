#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define REP(i,n) for (int i = 0; i < (n); ++ i)
#define FOR(i,a,b) for (int i = (a); i <= (b); ++ i)
#define FORD(i,b,a) for (int i = (b); i >= (a); -- i)

#define debug(x) cerr << #x << ": " << x << "\n"
#define all(x) x.begin(), x.end()

#define task "FLIPROW"

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> li;
typedef vector<int> vi;

const int N = 1005;

int n, m, a[N][N], b[N];

ll Rand(ll l, ll r) {
    return l + (
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
    1LL * rand() * (RAND_MAX + 1) +
    1LL * rand()) % (r - l + 1);
}

bool check(int col) {
    FOR(i, 1, n) b[i] = a[i][col];
    sort(b + 1, b + n + 1);
    FOR(i, 1, n - 1) {
        if (b[i] == b[i + 1]) {
            return false;
        }
    }
    return true;
}

void rev(int row) {
    FOR(j, 1, m/2) swap(a[row][j], a[row][m-j+1]);
}

void test() {
    ofstream inp(task".inp");
    n = Rand(1, 5), m = Rand(1, 5);
    inp << n << " " << m << "\n";
    FOR(i, 1, n) {
        FOR(j, 1, m) {
            a[i][j] =  Rand(1, 5);
            inp << a[i][j] << ' ';
        }
        inp << '\n';
    }
    inp.close();
}

string str, str2;
int k, row;

void check() {
    ifstream out(task".out");
    out >> str;
    cerr << "It's a " << str << "\n";
    if (str == "No") {
        system(task"_BF.exe");
        ifstream ans(task".ans");
        ans >> str2;
        if (str2 != str) {
            cout << "Expected Yes, but No found\n";
            ans.close();
            exit(0);
        }
    } else {
        out >> k;
        cerr << k << "operations\n";
        if (k > 3000) {
            cout << "Too many operations\n";
            out.close();
            exit(0);
        }
        REP(i, k) {
            out >> row;
            rev(row);
        }
        FOR(j, 1, m) {
            if (!check(j)) {
                cerr << "Bug in column " << j << "\n";
                out.close();
                exit(0);
            }
        }
    }
    out.close();
    cout << "Correct!\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int nTest = 100;
    /*FOR(iTest, 1, nTest) {
        test();
        cerr << "Test " << iTest << " created\n";
        system(task".exe");
        cerr << "Program executed\n";
        check();
    }*/
    check();
}
