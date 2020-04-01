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
string testDir, runDir;

void input() {
    ifstream inp((testDir + task".inp").c_str());
    inp >> n >> m;
    FOR(i, 1, n) {
        FOR(j, 1, m) inp >> a[i][j];
    }
    inp.close();
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

string str, str2;
int k, row;

void check() {
    ifstream out((runDir + task".out").c_str());
    out >> str;
    if (str == "No") {
        ifstream ans((testDir + task".out").c_str());
        ans >> str2;
        if (str2 != str) {
            cout << "Expected Yes, but No found\n";
            cout << "0\n";
            ans.close();
            exit(0);
        }
    } else {
        out >> k;
        if (k > 3000) {
            cout << "Too many operations\n";
            cout << "0\n";
            out.close();
            exit(0);
        }
        REP(i, k) {
            out >> row;
            rev(row);
        }
        FOR(j, 1, m) {
            if (!check(j)) {
                cout << "Wrong in column " << j << "\n";
                cout << "0\n";
                out.close();
                exit(0);
            }
        }
    }
    out.close();
    cout << "Correct!\n";
    cout << "1\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	getline(cin, testDir);
	getline(cin, runDir);
    input();
    check();
}
